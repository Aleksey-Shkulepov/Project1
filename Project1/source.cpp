#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<algorithm>
#include<conio.h>
#include <vector>
#include <cstring>
#include <cctype>
#include <string>
#include <fstream>

#include "MyFunctions.h"
#include "mylibrary.h"
#include "myVector.h"
#include "myStructures.h"
#include "mylist.h"
#include "anyTypeArray.h"
#include "Bank.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    ///21.06.25 lesson

    //ofstream fout;

    //fout.open("log.txt");

    //int arr[] = { 1,2,3,4,5 };
    //fillArr(arr, 5, 0, 100);

    //for (size_t i = 0; i < 5; i++)
    //{
    //    fout << arr[i] << " ";
    //}

    //fout.close();



    //int* b = nullptr;
    //unsigned int size = 0;

    //ifstream fin("log.txt");

    //if (!fin.is_open())
    //    exit(0);

    //int r;
    //while (fin >> r)
    //{
    //    if(isEven(r))
    //        add(b, size, r);
    //}

    //fin.close();



    //printArr(b, size);

    //fout.open("log2.txt");

    //for (size_t i = 0; i < size; i++)
    //{
    //    fout << b[i] << " ";
    //}

    //fout.close();


    //const int size = 10;
    //Point p[size];
    //for (size_t i = 0; i < size; i++)
    //{
    //	p[i].x = rand() % 10;
    //	p[i].y = rand() % 10;
    //	p[i].name = 'A' + i;

    //	p[i].print();
    //}


    //ifstream fin("log.txt");
    //ofstream fout("log.txt");

    //if (!fin.is_open())
    //    exit(0);

    //for (size_t i = 0; i < size; i++)
    //{
    //    fout << p[i].x << " ";
    //    fout << p[i].y << " ";
    //    fout << p[i].name << endl;
    //}

    //unsigned int size2 = 10;
    //Point* p2 = new Point[size2];

    //int r;
    //for (size_t i = 0; i < size2; i++)
    //{
    //    fin >> r;
    //    p2[i].x = r;
    //    fin >> r;
    //    p2[i].y = r;
    //    fin >> r;
    //    p2[i].name = r;
    //}

    //for (size_t i = 0; i < size2; i++)
    //{
    //    cout << p2[i].x << " ";
    //    cout << p2[i].y << " ";
    //    cout << p2[i].name << endl;
    //}

    //fin.close();
    //fout.close();

    //ifstream in("MyFunctions.h");

    //ofstream fout("undmyfunc.txt");

    //char buffer[800];
    //unsigned int size = 0;
    //char** c = new char* [size];
    //while (in.getline(buffer, 800))
    //{
    //    char* newbuffer = new char[strlen(buffer) + 1];
    //    strcpy(newbuffer, buffer);
    //    add(c, size, newbuffer);
    //}

    //for (size_t i = size - 1; i > 0; i--)
    //    fout << c[i] << endl;

    //fout.close();


    //ifstream in("MyFunctions.h");

    //ofstream fout("undmyfunc.txt");

    //char buffer[800];
    //unsigned int size = 0;
    //char** c = new char* [size];
    //char d[] = "------------";
    //unsigned int s = 0;
    //while (in.getline(buffer, 800))
    //{
    //    char* newbuffer = new char[strlen(buffer) + 1];
    //    strcpy(newbuffer, buffer);
    //    if (newbuffer[strlen(buffer) - 1] == ' ')
    //    {
    //        add(c, size, newbuffer);
    //        if(s == 0)
    //            add(c, size, d);
    //        s++;
    //    }
    //    else
    //        add(c, size, newbuffer);
    //}
    //if(s == 0)
    //    add(c, size, d);

    //for (size_t i = 0; i < size; i++)
    //    fout << c[i] << endl;

    //fout.close();

    ifstream in("MyFunctions.h");

    ofstream fout("undmyfunc.txt");

    char buffer[800];
    unsigned int size = 0;
    char** c = new char* [size];
    char d[] = "------------";
    unsigned int s = 0;
    while (in.getline(buffer, 800))
    {
        char* newbuffer = new char[strlen(buffer) + 1];
        strcpy(newbuffer, buffer);
        for (size_t i = 0; i < strlen(buffer); i++)
        {
            if (newbuffer[i] == '1')
                newbuffer[i] = '0';
            else if (newbuffer[i] == '0')
                newbuffer[i] = '1';
        }
        fout << newbuffer << endl;
    }

//ifstream fin("log.txt");

    //if (!fin.is_open())
    //    exit(0);

    //int r;
    //while (fin >> r)
    //{
    //    if(isEven(r))
    //        add(b, size, r);
    //}

    //fin.close();


    ///18.06.25 lesson

    //Bank bank;
    //bank.menu();


    ///17.06.25 anyType

    //AnyTypeList arr; fraction fr{2,3};
    //arr.add(string("string"));
    //arr.add(4);
    //arr.add(5.5);
    //arr.add(fr);
    //arr.printAll();

    ///16.06.25 mylist

    //mylist<int> arr;

    //unsigned int size;
    //cin >> size;

    //for (size_t i = 0; i < size; i++)
    //{
    //    arr.push_back(rand() % 10);
    //}

    //for (size_t i = 0; i < arr.GetSize(); i++)
    //{
    //    cout << arr[i] << endl;
    //

    //cout << arr.GetSize();

    //arr.clear();

    //for (size_t i = 0; i < arr.GetSize(); i++)
    //{
    //    cout << arr[i] << endl;
    //}

    //cout << arr.GetSize();

    ///15.06.25-18.06.25 h/w

    //int N = 3;
    //Car* cars = new Car[N];

    //cars[0].set(4.2, 0.18, 2.0, 150, 17, "Красный", AUTOMATIC);
    //cars[1].set(3.9, 0.16, 1.6, 110, 15, "Синий", MANUAL);
    //cars[2].set(4.5, 0.20, 2.5, 200, 18, "Красный", AUTOMATIC);

    //for (size_t i = 0; i < N; i++)
    //    cout << cars[i] << endl;

    //cout << searchByColor(cars, N, "Красный");

    //fraction fr1{ 1, 2 };
    //fraction fr2{ 4, 5 };
    //
    //try {
    //    cin >> fr1;
    //    cin >> fr2;

    //    cout << fr1 + fr2 << endl;
    //    cout << fr1 - fr2 << endl;
    //    cout << fr1 * fr2 << endl;
    //    cout << fr1 / fr2 << endl;
    //}
    //catch(exception &ex){
    //    cout << "ЗНАМЕНАТЕЛЬ НЕ МОЖЕТ РАВНЯТЬСЯ НУЛЮ!" << endl;
    //}

    ///14.06.25 lesson

    //Date d = { 4,6,2025 };
    //d.print();
    //cout << d.to_string() << endl;

    /*Point p;
    p.print();


    Human h;
    h.birthDay.day = 20;*/



    /*Point p;
    p.x = 12;
    p.y = 10;
    p.name = 'A';

    Point p1 = { 13, 34, 'B' };

    printPoint(p);
    printPoint(p1);


    Point p2[3] = { {2,4,'C'}, 5,8,'D', 2,6,'E' };
    for (size_t i = 0; i < 3; i++)
    {
        printPoint(p2[i]);
    }*/

    //const int size = 10;
    //Point p[size];
    //for (size_t i = 0; i < size; i++)
    //{
    //    p[i].x = rand() % 10;
    //    p[i].y = 0; // rand() % 10;
    //    p[i].name = 'A' + i;

    //    p[i].print();
    //}
    //double maxLen = 0;
    //Point p1, p2;
    //for (size_t i = 0; i < size - 1; i++)
    //{
    //    for (size_t j = i + 1; j < size; j++)
    //    {
    //        double len = len2Point(p[i], p[j]);
    //        if (len > maxLen)
    //        {
    //            maxLen = len;
    //            p1 = p[i];
    //            p2 = p[j];
    //        }
    //    }
    //}
    //cout << endl;
    //p1.print();
    //p2.print();



    //Point* p = new Point[10];

    ///12.06.25-15.06.25 h/w structure

    //size_t s = 5; Abonent* user;
    //Abonent* users = new Abonent[s];

    //for (size_t i = 0; i < s; i++)
    //    users[i].name = new char[20];

    //strcpy(users[0].name, "Sergei");
    //users[0].phone = 88005353535;

    //user = searchByName(users, s, "Sergei");
    //if (user)
    //    cout << "[name - " << user->name <<  ", phone - " << user->phone << "]" << endl;

    //user = searchByPhone(users, s, 88005353535);
    //if (user)
    //    cout << "[name - " << user->name << ", phone - " << user->phone << "]" << endl;

    //editContact(users, s, "Sergei", 38095193787);
    //editContact(users, s, "Aleksey", 38095193787);

    //user = searchByName(users, s, "Aleksey");
    //if(user)
    //    cout << "[name - " << user->name << ", phone - " << user->phone << "]"<< endl;

    //user = searchByPhone(users, s, 38095193787);
    //if (user)
    //    cout << "[name - " << user->name << ", phone - " << user->phone << "]" << endl;

    ///12.06.25-15.06.25 h/w

    //size_t row = 2, col = 5, len = 8000;
    //char*** Abonents = nullptr;
    //createArray3D<char>(Abonents, row, col, len);

    //strcpy(Abonents[0][0], "Sergei");
    //strcpy(Abonents[0][1], "88005353535");

    //printArr(searchByName(Abonents, col, "Sergei"), row);
    //printArr(searchByPhone(Abonents, col, "88005353535"), row);

    //editContact(Abonents, col, "Sergei", "88005353535");
    //editContact(Abonents, col, "Aleksey", "0");


    ///12.06.25 lesson



    //int row = 10, col = 5;
    //int** arr = nullptr;
    //createArray2D(arr, row, col);
    //fillArray2D(arr, row, col);
    //printArray2D(arr, row, col);
    ////cout << "\n";
    ////addRowArray2D(arr, row, col);
    ////printArray2D(arr, row, col);
    ////cout << "\n";
    ////deleteRowArray2D(arr, row, col);
    ////printArray2D(arr, row, col);
    ////cout << "\n";
    ////insertRowArray2D(arr, row,col, 2);
    ////printArray2D(arr, row, col);
    ////cout << "\n";
    ////popRowArray2D(arr, row,col, 1);
    ////printArray2D(arr, row, col);
    //cout << "\n";
    ////delZeroRow(arr, row, col);
    //trancportArray2D(arr, row, col);
    //printArray2D(arr, row, col);

    ///08.06.25-12.06.25 hw

    //char str1[8000] = "Python is the capital of programming. Python is nohtyp, Python Python!";

    //cout << countIncludingWord(str1, "Python") << endl;
    //cout << countSentences(str1) << endl;
    //cout << countPunctuation(str1) << endl;

    ////reverseString(str1); cout << str1 << endl;
    //reverseEachSentence(str1); cout << str1;
    ///04.06.25-08.06.25 hw

    //char str1[8000] = "Python is the capital of programming";
    ////char str2[] = " the best!";

    //cout << mystrstr(str1, "capital");
    /*cout << mystrcpy(str, "C++");*/

    //cout << str1;

    ///04.06.25 lesson

    //char str[] = "Python";

    //cout << delSymbol(str, 5);
    //cout << addSymbol(str, 'f', 2);

    ///31.05.25-04.06.25 hw

    //size_t option; double Num1, Num2;
    //cout << "Выберете действие(метод) из следущего списка: 1(+), 2(-), 3(*), 4(/), 5(**): "; cin >> option;

    //cout << "Введите первое число: "; cin >> Num1;
    //cout << "Введите второе число: "; cin >> Num2;

    //cout << Calculate(Num1, Num2, methods[option - 1]);

    ///31.05.25 lesson

    //size_t M = 10, N = 10;

    //int* arr1 = new int[M]; fillArr(arr1, M); printArr(arr1, M);
    //int* arr2 = new int[N]; fillArr(arr2, N); printArr(arr2, N);
    //cout << Action(arr1, arr2, M, N, avgArray);

    //int* arr = new int[10]; fillArr(arr, 10, 10, 100); printArr(arr, 10);
    //bubbleSort(arr, 10, uniqcomp);
    //printArr(arr, 10);

    ///31.05.25 hw

    ///delIncludeElems

    //size_t M, N, size3;
    //cin >> M >> N;
    //int* arr1 = new int[M]; fillArr(arr1, M); printArr(arr1, M);
    //int* arr2 = new int[N]; fillArr(arr2, N); printArr(arr2, N);

    //size3 = M;
    //int* arr3 = new int[size3]; 

    //delIncludeElems(arr1, M, arr2, N, arr3, size3);
    //printArr(arr3, size3);

    /////colabDifferentInArrs

    //size_t M_2, N_2, size3_2;
    //cin >> M_2 >> N_2;
    //int* arr1_2 = new int[M_2]; fillArr(arr1_2, M_2); printArr(arr1_2, M_2);
    //int* arr2_2 = new int[N_2]; fillArr(arr2_2, N_2); printArr(arr2_2, N_2);

    //size3_2 = M_2 + N_2;
    //int* arr3_2 = new int[size3_2];

    //colabDifferentInArrs(arr1_2, M_2, arr2_2, N_2, arr3_2, size3_2);
    //printArr(arr3_2, size3_2);

    //myVector arr;
    //arr.print();
    //arr.add(5);
    //arr.print();
    //myVector arr; arr.print();
    //arr.add(5); arr.print();
    //arr.insert(100, 5); arr.print();
    //arr.pop(2); arr.print(); 
    //arr.resize(-1); arr.print();

    //size_t s = 10;
    //int* arr = new int[s];
    //cout << "def - \t\t"; fillArr(arr, s); printArr(arr, s);

    //cout << "add - \t\t"; arr = add(arr, s++, 52); printArr(arr, s);
    //cout << "deletelast - \t"; arr = deletelast(arr, s--); printArr(arr, s);
    //cout << "insert(pos=3) - \t"; arr = insert(arr, s++, -52, 3); printArr(arr, s);
    //cout << "pop(pos=2) - \t\t"; arr = pop(arr, s--, 2); printArr(arr, s);
}