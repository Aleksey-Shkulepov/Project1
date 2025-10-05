#pragma once

#include "fullstd.h"

#include "Book.h"
#include "Worker.h"

namespace hw20_09_25 {
    void main()
    {
        size_t books_size = 4;

        Book* books = new Book[books_size] {
            Book("������������", "Intermezzo", "�����", 1908, 120),
            Book("������", "����� ������", "�����", 1883, 300),
            Book("��������", "������", "�����", 1840, 400),
            Book("������", "������", "˳����", 1905, 250)
        };

        cout << "������:" << endl;
        for (int i = 0; i < books_size; i++)
            if (strcmp(books[i].getAuthor(), "������") == 0)
                books[i].print();

        cout << endl << "�����:" << endl;
        for (int i = 0; i < books_size; i++)
            if (strcmp(books[i].getPublisher(), "�����") == 0)
                books[i].print();

        cout << endl << "����� 1900 ����:" << endl;
        for (int i = 0; i < books_size; i++)
            if (books[i].getYear() > 1900)
                books[i].print();

        // // // // // // // // // // // // // // // // 

        time_t t = time(nullptr);
        tm local = *localtime(&t);
        size_t current_year = local.tm_year + 1900;

        size_t workers_size = 4;

        Worker* workers = new Worker[workers_size] {
            Worker("�������� �.�.", "�������", 2010, 15000),
            Worker("�������� �.�.", "��������", 2018, 20000),
            Worker("��������� �.�.", "�������", 2005, 25000),
            Worker("������� �.�.", "��������", 2000, 50000)
        };


        cout << endl << "��������� > 10 ����:" << endl;
        for (int i = 0; i < workers_size; i++)
            if (current_year - workers[i].getYearStart() > 10)
                workers[i].print();

        cout << endl << "�� > 20000:" << endl;
        for (int i = 0; i < workers_size; i++)
            if (workers[i].getSalary() > 20000)
                workers[i].print();

        cout << endl << "��������� '�������':" << endl;
        for (int i = 0; i < workers_size; i++)
            if (strcmp(workers[i].getPosition(), "�������") == 0)
                workers[i].print();
    }
}