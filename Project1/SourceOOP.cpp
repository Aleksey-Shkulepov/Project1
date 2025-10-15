#define _CRT_SECURE_NO_WARNINGS

#include "fullstd.h" 
#include "mystd.h"

//#include "exam-main.h"

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

    //TestingSystem::main();
    List<int> list = {1,2,3,4,5,6};
    List<int> list2 = list;
    list2.print();

    List<int> list3 = list2.splice(1, 3);
    list3.print();
    list2.print();
}