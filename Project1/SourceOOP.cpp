#define _CRT_SECURE_NO_WARNINGS

#include "SOSL.h" 

#include "MyFunctions.h"
#include "mylibrary.h"
#include "myVector.h"
#include "myStructures.h"
#include "mylist.h"
#include "anyTypeArray.h"
#include "Bank.h"
#include "String.h"
#include "Queue.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    //❗❗❗
    //❗❗❗
    //❗❗❗
    //❗❗❗
    //❗❗❗
    //❗❗❗
    //❗❗❗
    // 
    // Все дз в папке homework пронумерованы числом их выдачи/создания
    // 
    //❗❗❗
    //❗❗❗
    //❗❗❗
    //❗❗❗
    //❗❗❗
    //❗❗❗
    //❗❗❗

    PriorityQueue<int, int> a;
    a.enqueue(5, 3);
    a.enqueue(64, 9);
    a.enqueue(3, 1);
    a.enqueue(5, 1);
    a.enqueue(55, 0);
    a.print();
}