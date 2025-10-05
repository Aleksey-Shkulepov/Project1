#pragma once

#include "fullstd.h"

#include "Book.h"
#include "Worker.h"

namespace hw20_09_25 {
    void main()
    {
        size_t books_size = 4;

        Book* books = new Book[books_size] {
            Book("Коцюбинський", "Intermezzo", "Весна", 1908, 120),
            Book("Франко", "Захар Беркут", "Наука", 1883, 300),
            Book("Шевченко", "Кобзар", "Весна", 1840, 400),
            Book("Франко", "Мойсей", "Літера", 1905, 250)
        };

        cout << "Франка:" << endl;
        for (int i = 0; i < books_size; i++)
            if (strcmp(books[i].getAuthor(), "Франко") == 0)
                books[i].print();

        cout << endl << "Весна:" << endl;
        for (int i = 0; i < books_size; i++)
            if (strcmp(books[i].getPublisher(), "Весна") == 0)
                books[i].print();

        cout << endl << "после 1900 року:" << endl;
        for (int i = 0; i < books_size; i++)
            if (books[i].getYear() > 1900)
                books[i].print();

        // // // // // // // // // // // // // // // // 

        time_t t = time(nullptr);
        tm local = *localtime(&t);
        size_t current_year = local.tm_year + 1900;

        size_t workers_size = 4;

        Worker* workers = new Worker[workers_size] {
            Worker("Іваненко І.І.", "Інженер", 2010, 15000),
            Worker("Петренко П.П.", "Менеджер", 2018, 20000),
            Worker("Сидоренко С.С.", "Інженер", 2005, 25000),
            Worker("Мельник М.М.", "Директор", 2000, 50000)
        };


        cout << endl << "Работники > 10 років:" << endl;
        for (int i = 0; i < workers_size; i++)
            if (current_year - workers[i].getYearStart() > 10)
                workers[i].print();

        cout << endl << "ЗП > 20000:" << endl;
        for (int i = 0; i < workers_size; i++)
            if (workers[i].getSalary() > 20000)
                workers[i].print();

        cout << endl << "Работники 'Инженер':" << endl;
        for (int i = 0; i < workers_size; i++)
            if (strcmp(workers[i].getPosition(), "Інженер") == 0)
                workers[i].print();
    }
}