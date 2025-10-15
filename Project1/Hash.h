#pragma once

#include <cmath>
#include <cstring>

namespace TestingSystem {
    namespace Hash {

        unsigned char* input = nullptr;
        unsigned int* block = nullptr;
        int size = 0;

        unsigned int A = 0x67452301;
        unsigned int B = 0xefcdab89;
        unsigned int C = 0x98badcfe;
        unsigned int D = 0x10325476;
        unsigned int T[64];

        unsigned int rotate_left(unsigned int value, unsigned int shift) {
            return (value << shift) | (value >> (32 - shift));
        }

        unsigned int F(unsigned int x, unsigned int y, unsigned int z) { return (x & y) | (~x & z); }
        unsigned int G(unsigned int x, unsigned int y, unsigned int z) { return (x & z) | (~z & y); }
        unsigned int H(unsigned int x, unsigned int y, unsigned int z) { return x ^ y ^ z; }
        unsigned int I(unsigned int x, unsigned int y, unsigned int z) { return y ^ (~z | x); }

        void appendBits(const mystd::String& data) {
            int len = (int)data.get_length();
            for (int i = 0; i < len; ++i) {
                input[i] = (unsigned char)data[i];
            }
            input[len] = 0x80;
            for (int i = len + 1; i < size - 8; ++i) {
                input[i] = 0x00;
            }
            unsigned long long bit_length = (unsigned long long)len * 8ULL;
            for (int i = 0; i < 8; ++i) {
                input[size - 8 + i] = (unsigned char)((bit_length >> (i * 8)) & 0xFFULL);
            }
        }

        void init() {
            for (int i = 0; i < 64; ++i) {
                double val = pow(2.0, 32.0) * fabs(sin((double)(i + 1)));
                T[i] = (unsigned int)val;
            }
        }

        void process_block(const unsigned int* blk) {
            unsigned int AA = A;
            unsigned int BB = B;
            unsigned int CC = C;
            unsigned int DD = D;

            A = B + rotate_left((A + F(B, C, D) + blk[0] + T[0]), 7);
            D = A + rotate_left((D + F(A, B, C) + blk[1] + T[1]), 12);
            C = D + rotate_left((C + F(D, A, B) + blk[2] + T[2]), 17);
            B = C + rotate_left((B + F(C, D, A) + blk[3] + T[3]), 22);

            A = B + rotate_left((A + F(B, C, D) + blk[4] + T[4]), 7);
            D = A + rotate_left((D + F(A, B, C) + blk[5] + T[5]), 12);
            C = D + rotate_left((C + F(D, A, B) + blk[6] + T[6]), 17);
            B = C + rotate_left((B + F(C, D, A) + blk[7] + T[7]), 22);

            A = B + rotate_left((A + F(B, C, D) + blk[8] + T[8]), 7);
            D = A + rotate_left((D + F(A, B, C) + blk[9] + T[9]), 12);
            C = D + rotate_left((C + F(D, A, B) + blk[10] + T[10]), 17);
            B = C + rotate_left((B + F(C, D, A) + blk[11] + T[11]), 22);

            A = B + rotate_left((A + F(B, C, D) + blk[12] + T[12]), 7);
            D = A + rotate_left((D + F(A, B, C) + blk[13] + T[13]), 12);
            C = D + rotate_left((C + F(D, A, B) + blk[14] + T[14]), 17);
            B = C + rotate_left((B + F(C, D, A) + blk[15] + T[15]), 22);

            A = B + rotate_left((A + G(B, C, D) + blk[1] + T[16]), 5);
            D = A + rotate_left((D + G(A, B, C) + blk[6] + T[17]), 9);
            C = D + rotate_left((C + G(D, A, B) + blk[11] + T[18]), 14);
            B = C + rotate_left((B + G(C, D, A) + blk[0] + T[19]), 20);

            A = B + rotate_left((A + G(B, C, D) + blk[5] + T[20]), 5);
            D = A + rotate_left((D + G(A, B, C) + blk[10] + T[21]), 9);
            C = D + rotate_left((C + G(D, A, B) + blk[15] + T[22]), 14);
            B = C + rotate_left((B + G(C, D, A) + blk[4] + T[23]), 20);

            A = B + rotate_left((A + G(B, C, D) + blk[9] + T[24]), 5);
            D = A + rotate_left((D + G(A, B, C) + blk[14] + T[25]), 9);
            C = D + rotate_left((C + G(D, A, B) + blk[3] + T[26]), 14);
            B = C + rotate_left((B + G(C, D, A) + blk[8] + T[27]), 20);

            A = B + rotate_left((A + G(B, C, D) + blk[13] + T[28]), 5);
            D = A + rotate_left((D + G(A, B, C) + blk[2] + T[29]), 9);
            C = D + rotate_left((C + G(D, A, B) + blk[7] + T[30]), 14);
            B = C + rotate_left((B + G(C, D, A) + blk[12] + T[31]), 20);

            A = B + rotate_left((A + H(B, C, D) + blk[5] + T[32]), 4);
            D = A + rotate_left((D + H(A, B, C) + blk[8] + T[33]), 11);
            C = D + rotate_left((C + H(D, A, B) + blk[11] + T[34]), 16);
            B = C + rotate_left((B + H(C, D, A) + blk[14] + T[35]), 23);

            A = B + rotate_left((A + H(B, C, D) + blk[1] + T[36]), 4);
            D = A + rotate_left((D + H(A, B, C) + blk[4] + T[37]), 11);
            C = D + rotate_left((C + H(D, A, B) + blk[7] + T[38]), 16);
            B = C + rotate_left((B + H(C, D, A) + blk[10] + T[39]), 23);

            A = B + rotate_left((A + H(B, C, D) + blk[13] + T[40]), 4);
            D = A + rotate_left((D + H(A, B, C) + blk[0] + T[41]), 11);
            C = D + rotate_left((C + H(D, A, B) + blk[3] + T[42]), 16);
            B = C + rotate_left((B + H(C, D, A) + blk[6] + T[43]), 23);

            A = B + rotate_left((A + H(B, C, D) + blk[9] + T[44]), 4);
            D = A + rotate_left((D + H(A, B, C) + blk[12] + T[45]), 11);
            C = D + rotate_left((C + H(D, A, B) + blk[15] + T[46]), 16);
            B = C + rotate_left((B + H(C, D, A) + blk[2] + T[47]), 23);

            A = B + rotate_left((A + I(B, C, D) + blk[0] + T[48]), 6);
            D = A + rotate_left((D + I(A, B, C) + blk[7] + T[49]), 10);
            C = D + rotate_left((C + I(D, A, B) + blk[14] + T[50]), 15);
            B = C + rotate_left((B + I(C, D, A) + blk[5] + T[51]), 21);

            A = B + rotate_left((A + I(B, C, D) + blk[12] + T[52]), 6);
            D = A + rotate_left((D + I(A, B, C) + blk[3] + T[53]), 10);
            C = D + rotate_left((C + I(D, A, B) + blk[10] + T[54]), 15);
            B = C + rotate_left((B + I(C, D, A) + blk[1] + T[55]), 21);

            A = B + rotate_left((A + I(B, C, D) + blk[8] + T[56]), 6);
            D = A + rotate_left((D + I(A, B, C) + blk[15] + T[57]), 10);
            C = D + rotate_left((C + I(D, A, B) + blk[6] + T[58]), 15);
            B = C + rotate_left((B + I(C, D, A) + blk[13] + T[59]), 21);

            A = B + rotate_left((A + I(B, C, D) + blk[4] + T[60]), 6);
            D = A + rotate_left((D + I(A, B, C) + blk[11] + T[61]), 10);
            C = D + rotate_left((C + I(D, A, B) + blk[2] + T[62]), 15);
            B = C + rotate_left((B + I(C, D, A) + blk[9] + T[63]), 21);

            A += AA;
            B += BB;
            C += CC;
            D += DD;
        }

        void process() {
            for (int offset = 0; offset < size; offset += 64) {
                const unsigned int* blk = (const unsigned int*)(input + offset);
                process_block(blk);
            }
        }

        Vector<unsigned char> hashToArr() {
            Vector<unsigned char> hash(16);
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

            input = new unsigned char[size];
            appendBits(data);
            init();
            process();

            Vector<unsigned char> hashArr = hashToArr();

            delete[] input;
            input = nullptr;

            return getHexMD5(hashArr);
        }

    } 
} 