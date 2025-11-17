#pragma once

#include<iostream>
using namespace std;

namespace cmatehelp {
    template <class T>
    class UniquePtr {
    private:
        T* ptr;

    public:
        UniquePtr() : ptr(nullptr) {}
        explicit UniquePtr(T* p) : ptr(p) {}


        UniquePtr(const UniquePtr&) = delete;
        UniquePtr& operator=(const UniquePtr&) = delete;



        UniquePtr(UniquePtr&& other) noexcept {
            ptr = other.ptr;
            other.ptr = nullptr;
        }

        UniquePtr& operator=(UniquePtr&& other) noexcept {
            if (this != &other) {
                delete ptr;
                ptr = other.ptr;
                other.ptr = nullptr;
            }
            return *this;
        }

        T& operator*() { return *ptr; }
        T* operator->() { return ptr; }
        T* get() const { return ptr; }

        void reset(T* p = nullptr) {
            delete ptr;
            ptr = p;
        }

        T* release() {
            T* tmp = ptr;
            ptr = nullptr;
            return tmp;
        }

        ~UniquePtr() {
            delete ptr;
        }
    };




    template <class T>
    class SharedPtr {
    private:
        T* ptr;
        size_t* count;

    public:
        SharedPtr() : ptr(nullptr), count(nullptr) {}

        explicit SharedPtr(T* p) : ptr(p) {
            count = new size_t(1);
        }

        SharedPtr(const SharedPtr& other) {
            ptr = other.ptr;
            count = other.count;
            if (count) (*count)++;
        }


        SharedPtr(SharedPtr&& other) noexcept {
            ptr = other.ptr;
            count = other.count;
            other.ptr = nullptr;
            other.count = nullptr;
        }

        SharedPtr& operator=(const SharedPtr& other) {
            if (this != &other) {
                release();
                ptr = other.ptr;
                count = other.count;
                if (count) (*count)++;
            }
            return *this;
        }

        SharedPtr& operator=(SharedPtr&& other) noexcept {
            if (this != &other) {
                release();
                ptr = other.ptr;
                count = other.count;
                other.ptr = nullptr;
                other.count = nullptr;
            }
            return *this;
        }

        void release() {
            if (count) {
                (*count)--;
                if (*count == 0) {
                    delete ptr;
                    delete count;
                    ptr = nullptr;
                    count = nullptr;
                }
            }
        }

        T& operator*() { return *ptr; }
        T* operator->() { return ptr; }
        T* get() const { return ptr; }

        size_t use_count() const {
            return count ? *count : 0;
        }

        ~SharedPtr() {
            release();
        }
    };

    class Test {
    public:
        Test() { cout << "Test(): створено\n"; }
        ~Test() { cout << "~Test(): видалено\n"; }
        void hello() { cout << "Hello from Test!\n"; }
    };

    void main()
    {
        cout << "====== TEST UNIQUE_PTR ======\n";

        {
            UniquePtr<Test> u1(new Test());
            u1->hello();

            UniquePtr<Test> u2 = move(u1);
            if (!u1.get()) cout << "u1 тепер порожній\n";

            u2->hello();
        }


        cout << "\n====== TEST SHARED_PTR ======\n";

        Test* test = new Test;

        SharedPtr<Test> p1(test);
        cout << "use_count = " << p1.use_count() << "\n";
        {
            SharedPtr<Test> p2 = p1;
            cout << "use_count = " << p1.use_count() << "\n";
            p2->hello();
        }


        cout << "Після знищення p2 use_count = " << p1.use_count() << "\n";

        SharedPtr<Test> p3 = move(p1);
        cout << "Після move: p1=" << p1.use_count() << "  p3=" << p3.use_count() << "\n";
    }
}