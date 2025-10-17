#pragma once

#include <cmath>
#include <cstring>

namespace TestingSystem {
    namespace Hash {

        static const unsigned int A0 = 0x67452301u;
        static const unsigned int B0 = 0xefcdab89u;
        static const unsigned int C0 = 0x98badcfeu;
        static const unsigned int D0 = 0x10325476u;

        unsigned char* input = nullptr;
        int size = 0;
        unsigned int A, B, C, D;
        unsigned int T[64];

        inline unsigned int rotate_left(unsigned int value, unsigned int shift) {
            return (value << shift) | (value >> (32 - shift));
        }

        inline unsigned int F(unsigned int x, unsigned int y, unsigned int z) { return (x & y) | (~x & z); }
        inline unsigned int G(unsigned int x, unsigned int y, unsigned int z) { return (x & z) | (y & ~z); }
        inline unsigned int H(unsigned int x, unsigned int y, unsigned int z) { return x ^ y ^ z; }
        inline unsigned int I(unsigned int x, unsigned int y, unsigned int z) { return y ^ (x | ~z); }

        void init_T_once() {
            static bool inited = false;
            if (inited) return;
            for (int i = 0; i < 64; ++i) {
                double val = pow(2.0, 32.0) * fabs(sin((double)(i + 1)));
                T[i] = (unsigned int)val;
            }
            inited = true;
        }

        void appendBits(const mystd::String& data) {
            int len = (int)data.get_length();
            for (int i = 0; i < len; ++i) {
                input[i] = (unsigned char)data[i];
            }
            input[len] = 0x80;
            for (int i = len + 1; i < size - 8; ++i) input[i] = 0x00;
            unsigned long long bit_length = (unsigned long long)len * 8ULL;
            for (int i = 0; i < 8; ++i) {
                input[size - 8 + i] = (unsigned char)((bit_length >> (i * 8)) & 0xFFULL);
            }
        }

        void process_block(const unsigned char* block_bytes) {
            // Собираем 16 слов (little-endian) из байтов (избегаем приведения указателя)
            unsigned int X[16];
            for (int i = 0; i < 16; ++i) {
                int idx = i * 4;
                X[i] = (unsigned int)block_bytes[idx]
                    | ((unsigned int)block_bytes[idx + 1] << 8)
                        | ((unsigned int)block_bytes[idx + 2] << 16)
                        | ((unsigned int)block_bytes[idx + 3] << 24);
            }

            unsigned int AA = A;
            unsigned int BB = B;
            unsigned int CC = C;
            unsigned int DD = D;

            // --- 64 операций MD5 (взятно из твоей оригинальной структуры, но использую X[] вместо blk[])

            // Round 1
            A = B + rotate_left((A + F(B, C, D) + X[0] + T[0]), 7);
            D = A + rotate_left((D + F(A, B, C) + X[1] + T[1]), 12);
            C = D + rotate_left((C + F(D, A, B) + X[2] + T[2]), 17);
            B = C + rotate_left((B + F(C, D, A) + X[3] + T[3]), 22);

            A = B + rotate_left((A + F(B, C, D) + X[4] + T[4]), 7);
            D = A + rotate_left((D + F(A, B, C) + X[5] + T[5]), 12);
            C = D + rotate_left((C + F(D, A, B) + X[6] + T[6]), 17);
            B = C + rotate_left((B + F(C, D, A) + X[7] + T[7]), 22);

            A = B + rotate_left((A + F(B, C, D) + X[8] + T[8]), 7);
            D = A + rotate_left((D + F(A, B, C) + X[9] + T[9]), 12);
            C = D + rotate_left((C + F(D, A, B) + X[10] + T[10]), 17);
            B = C + rotate_left((B + F(C, D, A) + X[11] + T[11]), 22);

            A = B + rotate_left((A + F(B, C, D) + X[12] + T[12]), 7);
            D = A + rotate_left((D + F(A, B, C) + X[13] + T[13]), 12);
            C = D + rotate_left((C + F(D, A, B) + X[14] + T[14]), 17);
            B = C + rotate_left((B + F(C, D, A) + X[15] + T[15]), 22);

            // Round 2
            A = B + rotate_left((A + G(B, C, D) + X[1] + T[16]), 5);
            D = A + rotate_left((D + G(A, B, C) + X[6] + T[17]), 9);
            C = D + rotate_left((C + G(D, A, B) + X[11] + T[18]), 14);
            B = C + rotate_left((B + G(C, D, A) + X[0] + T[19]), 20);

            A = B + rotate_left((A + G(B, C, D) + X[5] + T[20]), 5);
            D = A + rotate_left((D + G(A, B, C) + X[10] + T[21]), 9);
            C = D + rotate_left((C + G(D, A, B) + X[15] + T[22]), 14);
            B = C + rotate_left((B + G(C, D, A) + X[4] + T[23]), 20);

            A = B + rotate_left((A + G(B, C, D) + X[9] + T[24]), 5);
            D = A + rotate_left((D + G(A, B, C) + X[14] + T[25]), 9);
            C = D + rotate_left((C + G(D, A, B) + X[3] + T[26]), 14);
            B = C + rotate_left((B + G(C, D, A) + X[8] + T[27]), 20);

            A = B + rotate_left((A + G(B, C, D) + X[13] + T[28]), 5);
            D = A + rotate_left((D + G(A, B, C) + X[2] + T[29]), 9);
            C = D + rotate_left((C + G(D, A, B) + X[7] + T[30]), 14);
            B = C + rotate_left((B + G(C, D, A) + X[12] + T[31]), 20);

            // Round 3
            A = B + rotate_left((A + H(B, C, D) + X[5] + T[32]), 4);
            D = A + rotate_left((D + H(A, B, C) + X[8] + T[33]), 11);
            C = D + rotate_left((C + H(D, A, B) + X[11] + T[34]), 16);
            B = C + rotate_left((B + H(C, D, A) + X[14] + T[35]), 23);

            A = B + rotate_left((A + H(B, C, D) + X[1] + T[36]), 4);
            D = A + rotate_left((D + H(A, B, C) + X[4] + T[37]), 11);
            C = D + rotate_left((C + H(D, A, B) + X[7] + T[38]), 16);
            B = C + rotate_left((B + H(C, D, A) + X[10] + T[39]), 23);

            A = B + rotate_left((A + H(B, C, D) + X[13] + T[40]), 4);
            D = A + rotate_left((D + H(A, B, C) + X[0] + T[41]), 11);
            C = D + rotate_left((C + H(D, A, B) + X[3] + T[42]), 16);
            B = C + rotate_left((B + H(C, D, A) + X[6] + T[43]), 23);

            A = B + rotate_left((A + H(B, C, D) + X[9] + T[44]), 4);
            D = A + rotate_left((D + H(A, B, C) + X[12] + T[45]), 11);
            C = D + rotate_left((C + H(D, A, B) + X[15] + T[46]), 16);
            B = C + rotate_left((B + H(C, D, A) + X[2] + T[47]), 23);

            // Round 4
            A = B + rotate_left((A + I(B, C, D) + X[0] + T[48]), 6);
            D = A + rotate_left((D + I(A, B, C) + X[7] + T[49]), 10);
            C = D + rotate_left((C + I(D, A, B) + X[14] + T[50]), 15);
            B = C + rotate_left((B + I(C, D, A) + X[5] + T[51]), 21);

            A = B + rotate_left((A + I(B, C, D) + X[12] + T[52]), 6);
            D = A + rotate_left((D + I(A, B, C) + X[3] + T[53]), 10);
            C = D + rotate_left((C + I(D, A, B) + X[10] + T[54]), 15);
            B = C + rotate_left((B + I(C, D, A) + X[1] + T[55]), 21);

            A = B + rotate_left((A + I(B, C, D) + X[8] + T[56]), 6);
            D = A + rotate_left((D + I(A, B, C) + X[15] + T[57]), 10);
            C = D + rotate_left((C + I(D, A, B) + X[6] + T[58]), 15);
            B = C + rotate_left((B + I(C, D, A) + X[13] + T[59]), 21);

            A = B + rotate_left((A + I(B, C, D) + X[4] + T[60]), 6);
            D = A + rotate_left((D + I(A, B, C) + X[11] + T[61]), 10);
            C = D + rotate_left((C + I(D, A, B) + X[2] + T[62]), 15);
            B = C + rotate_left((B + I(C, D, A) + X[9] + T[63]), 21);

            A += AA;
            B += BB;
            C += CC;
            D += DD;
        }

        void process() {
            for (int offset = 0; offset < size; offset += 64) {
                process_block(input + offset);
            }
        }

        Vector<unsigned char> hashToArr() {
            Vector<unsigned char> hash(16);
            // копируем A,B,C,D (little-endian) в массив байт
            memcpy(&hash[0], (char*)&A, 4);
            memcpy(&hash[4], (char*)&B, 4);
            memcpy(&hash[8], (char*)&C, 4);
            memcpy(&hash[12], (char*)&D, 4);
            return hash;
        }

        String getHexMD5(Vector<unsigned char> hash) {
            String hex = "0123456789ABCDEF";
            String result;
            for (int i = 0; i < (int)hash.get_size(); i++) {
                result += hex[hash[i] >> 4];
                result += hex[hash[i] & 0x0F];
            }
            return result;
        }

        String MD5(String data) {
            int length = (int)data.get_length();
            int rest = length % 64;
            if (rest < 56) size = length - rest + 56 + 8;
            else size = length + 64 - rest + 56 + 8;

            init_T_once();

            // Сбрасываем начальные регистры каждый вызов
            A = A0; B = B0; C = C0; D = D0;

            // выделяем и нулим буфер
            input = new unsigned char[size]();
            appendBits(data);

            process();

            Vector<unsigned char> hashArr = hashToArr();

            delete[] input;
            input = nullptr;

            return getHexMD5(hashArr);
        }

    } // namespace Hash
} // namespace TestingSystem
