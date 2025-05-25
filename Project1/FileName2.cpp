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

    //size_t s = 10;
    //int* arr = new int[s];
    //cout << "def - \t\t"; fillArr(arr, s); printArr(arr, s);

    //cout << "add - \t\t"; arr = add(arr, s++, 52); printArr(arr, s);
    //cout << "deletelast - \t"; arr = deletelast(arr, s--); printArr(arr, s);
    //cout << "insert(pos=3) - \t"; arr = insert(arr, s++, -52, 3); printArr(arr, s);
    //cout << "pop(pos=2) - \t\t"; arr = pop(arr, s--, 2); printArr(arr, s);

    //myVector arr;
    //arr.print();
    //arr.add(5);
    //arr.print();
    myVector arr(8); arr.print();
    arr.add(5); arr.print();
    arr.insert(100, 5); arr.print();
    arr.pop(2); arr.print(); 
}