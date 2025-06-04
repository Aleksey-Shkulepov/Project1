#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<algorithm>
#include<conio.h>
#include <vector>

#include "MyFunctions.h"
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    ///04.06.25 lesson

    char str[] = "Python";



    cout << delSymbol(str, 5);

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