#pragma once


template<class T>
class Shared_Ptr
{
    T* ptr;
    size_t* count;

    void release() {
        if (count) {
            --(*count);
            if (*count == 0) {
                delete ptr;
                delete count;
            }
            ptr = nullptr;
            count = nullptr;
        }
    }

public:
    explicit Shared_Ptr(T* p) : ptr(p), count(1){}

    ~Shared_Ptr() { release(); }

    Shared_Ptr(const Shared_Ptr& other) : ptr(other.ptr), count(other.count)
    {
        if (count) ++(*count);
    }

    Shared_Ptr& operator=(const Shared_Ptr& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            count = other.count;
            if (count) ++(*count);
        }
        return *this;
    }

    Shared_Ptr(Shared_Ptr&& other)
        : ptr(other.ptr)
        , count(other.count)
    {
        other.ptr = nullptr;
        other.count = nullptr;
    }

    Shared_Ptr& operator=(Shared_Ptr&& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            count = other.count;
            other.ptr = nullptr;
            other.count = nullptr;
        }
        return *this;
    }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    T* get() const { return ptr; }

    size_t use_count() const { return count ? *count : 0; }

    void reset(T* p = nullptr) {
        release();
        if (p) {
            ptr = p;
            count = new size_t(1);
        }
        else {
            ptr = nullptr;
            count = nullptr;
        }
    }
};

