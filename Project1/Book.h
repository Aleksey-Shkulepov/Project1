#pragma once

#include "SOSL.h"

namespace hw20_09_25 {

    class Book {
        char* author;
        char* title;
        char* publisher;
        int year;
        int pagesCount;
    public:
        Book(): author(nullptr), title(nullptr), publisher(nullptr),year(0), pagesCount(0) {}

        Book(const char* a, const char* t, const char* p, int y, int pc)
            : year(y), pagesCount(pc)
        {
            size_t a_s = strlen(a);
            author = new char[a_s + 1];
            strcpy_s(author, a_s + 1, a);

            size_t t_s = strlen(t);
            title = new char[t_s + 1];
            strcpy_s(title, t_s + 1, t);

            size_t p_s = strlen(p);
            publisher = new char[p_s + 1];
            strcpy_s(publisher, p_s + 1, p);
        }

        Book(const Book& other) 
            : year(other.year), pagesCount(other.pagesCount)
        {
            if (other.author) {
                size_t a_s = strlen(other.author);
                author = new char[a_s + 1];
                strcpy_s(author, a_s + 1, other.author);
            }
            else author = nullptr;

            if (other.title) {
                size_t t_s = strlen(other.title);
                title = new char[t_s + 1];
                strcpy_s(title, t_s + 1, other.title);
            }
            else title = nullptr;

            if (other.publisher) {
                size_t p_s = strlen(other.publisher);
                publisher = new char[p_s + 1];
                strcpy_s(publisher, p_s + 1, other.publisher);
            }
            else publisher = nullptr;
        }

        explicit Book(const char* a)
            : year(0), pagesCount(0)
        {
            size_t a_s = strlen(a);
            author = new char[a_s + 1];
            strcpy_s(author, a_s + 1, a);

            title = nullptr;
            publisher = nullptr;
        }

        explicit Book(int y)
            : year(y), pagesCount(0)
        {
            author = nullptr;
            title = nullptr;
            publisher = nullptr;
        }

        ~Book() {
            delete[] author;
            delete[] title;
            delete[] publisher;
        }


        const char* getAuthor()     const { return author; }
        const char* getTitle()      const { return title; }
        const char* getPublisher()  const { return publisher; }
        int         getYear()       const { return year; }
        int         getPagesCount() const { return pagesCount; }


        void setAuthor (const char* a) 
        { 
            size_t a_s = strlen(a);
            author = new char[a_s + 1];
            strcpy_s(author, a_s + 1, a);
        }

        void setTitle (const char* t) 
        {
            size_t t_s = strlen(t);
            title = new char[t_s + 1];
            strcpy_s(title, t_s + 1, t);
        }

        void setPublisher (const char* p) 
        {
            size_t p_s = strlen(p);
            publisher = new char[p_s + 1];
            strcpy_s(publisher, p_s + 1, p);
        }

        void setYear      (int y)         { year = y; }
        void setPagesCount(int pc)        { pagesCount = pc; }

        void print() const {
            cout
                << "Author: " << author << endl
                << "Title: " << title << endl
                << "Publisher: " << publisher << endl
                << "Year: " << year << endl
                << "Count of pages: " << pagesCount << endl
                << endl;
        }
    };

}

