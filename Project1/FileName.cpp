//#include <iostream>
//#include <windows.h>
//#include <ctime>
//#include "MyFunctions.h"
//using namespace std;
//int main() {
//    srand(time(0));
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    const long double pi = 3.14159265358979L;
    //*******************************************1dz************************************************************************
    //!!!!!!!!!!!!!!!!!!!!! task1 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //ВНИМАНИЕ НЕ РАБОТАЕТ С КИРИЛИЦОЙ! МНЕ ЛЕНЬ ЕЕ ДЕЛАТЬ ТАКОГО В УСЛОВИИ НЕ БЫЛО
    //char symbol;
    //cout << "Задача 1:\n";
    //cout << "Введите симввл: \n";
    //cin >> symbol;
    //if (((int)symbol >= 65 && (int)symbol <= 90) || ((int)symbol >= 97 && (int)symbol <= 122)) {
    //    cout << "Буква\n";
    //}
    //else if ((int)symbol >= 48 && (int)symbol <= 57) {
    //    cout << "Цифра\n";
    //}
    //else if (((int)symbol >= 33 && (int)symbol <= 47) || ((int)symbol >= 58 && (int)symbol <= 64) ||
    //    ((int)symbol >= 91 && (int)symbol <= 96) || ((int)symbol >= 123 && (int)symbol <= 126)) {
    //    cout << "Пунктуация тип\n";
    //}
    //else {
    //    cout << "Что то другое\n";
    //}
    ////!!!!!!!!!!!!!!!!!!!!!!! task2 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //cout << "Задача 2:\n";
    //double price, fprice;
    //int firssecondoperper, secondoper;
    //cout << "Цена разговора(грн): ";
    //cin >> price;
    //cout << "Оператор 1 (1-Kyivstar, 2-Vodafone, 3-Lifecell): ";
    //cin >> firssecondoperper;
    //cout << "Оператор 2 (1-Kyivstar, 2-Vodafone, 3-Lifecell): ";
    //cin >> secondoper;
    //if (firssecondoperper == secondoper)
    //    fprice = price;
    //else
    //    fprice = price * 1.5; //мне лень еще раз заморачиваться и искать цены на операторы и тп
    //cout << "Итоговая цена разг: " << fprice << " грн\n";
    ////!!!!!!!!!!!!!!!!!!!!!!! task3 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //cout << "Задача 3:\n";
    ////1
    //double money;
    //int opozdanie;
    //cout << "1. Вводные: доход и кол-во опозданий.\n";
    //cout << "Доход: ";
    //cin >> money;
    //cout << "кол-во опозданий: ";
    //cin >> opozdanie;
    //int lines = ((money + (opozdanie / 3) * 20) / 50) * 100;
    //cout << "Надо написать " << lines << " строчек\n";
    ////2
    //int lines2;
    //double money2;
    //cout << "2.Вводные: кол-во строчек и доход.\n";
    //cout << "кол-во строчек: ";
    //cin >> lines2;
    //cout << "доход: ";
    //cin >> money2;
    //if ((lines2 / 100) * 50 < money2) {
    //    cout << "Недостаточно строчек.\n";
    //}
    //else {
    //    int maxopozdanie = (int)(((lines2 / 100) * 50 - money2) / 20) * 3;
    //    cout << "Мах опозданий: " << maxopozdanie << "\n";
    //}
    ////3
    //int lines3, opozdanie3;
    //cout << "3.Вводные: кол-во рядков и опозданий\n";
    //cout << "кол-во рядков: ";
    //cin >> lines3;
    //cout << "кол-во опозданий: ";
    //cin >> opozdanie3;
    //double money3 = (lines3 / 100) * 50 - (opozdanie3 / 3) * 20;
    //if (money3 <= 0)
    //    cout << "Без зарплаты :(\n";
    //else
    //    cout << "Зп - " << money3 << "грн \n";
    //*******************************************2dz************************************************************************
    ////!!!!!!!!!!!!!!!!!!!!!!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //cout << "Задание 1\n";
    //int a1, sum1 = 0;
    //cout << "Введите a: ";
    //cin >> a1;
    //if (a1 > 500) {
    //    cout << "Ошибка: a > 500.\n";
    //}
    //else {
    //    int i = a1;
    //    while (i <= 500) {
    //        sum1 += i;
    //        i++;
    //    }
    //    cout << "Сумма чисел от " << a1 << " до 500: " << sum1 << "\n";
    //}
    ////!!!!!!!!!!!!!!!!!!!!!!2!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //cout << "Задание 2\n";
    //int x, y, pow = 1, count = 0;
    //cout << "Введите x: ";
    //cin >> x;
    //cout << "Введите y: ";
    //cin >> y;
    //if (y < 0) {
    //    cout << "Ошибка: pow < 0\n";
    //}
    //else {
    //    while (count < y) {
    //        pow *= x;
    //        count++;
    //    }
    //    cout << x << " в степени " << y << " = " << pow<< "\n";
    //}
    ////!!!!!!!!!!!!!!!!!!!!!!3!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //cout << "Задание 3\n";
    //int sum3 = 0, n3 = 1;
    //while (n3 <= 1000) {
    //    sum3 += n3;
    //    n3++;
    //}
    //double avg = sum3 / 1000.0;
    //cout << "Среднее арифметическое: " << avg << "\n";
    ////!!!!!!!!!!!!!!!!!!!!!!4!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //cout << "Задание 4\n";
    //int a4;
    //cout << "Введите a: ";
    //cin >> a4;
    //if (a4 < 1 || a4 > 20) {
    //    cout << "Ошибка: a < 1 или a > 20\n";
    //}
    //else {
    //    long long product = 1;
    //    int j = a4;
    //    do {
    //        product *= j;
    //        j++;
    //    } while (j <= 20);
    //    cout << "Произв от " << a4 << " до 20: " << product << "\n";
    //}
    ////!!!!!!!!!!!!!!!!!!!!!!5!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //cout << "Задание 5\n";
    //int k;
    //cout << "Введите цифру: ";
    //cin >> k;
    //int m = 2;
    //while (m <= 9) {
    //    cout << k << " x " << m << " = " << (k * m) << "\n";
    //    m++;
    //}
//*******************************************3dz************************************************************************
    //// !!!!!!!!!!!!!!!task1!!!!!!!!!!!!
    //cout << "Задача 1\n";
    //double x = 3.0;
    //while (x <= 4.5) {
    //    double y = sqrt(4.5 * 4.5 - x * x);
    //    double ugolnaklona = atan2(y, x) * 180.0 / pi;
    //    cout << "x = " << x << " м, угол = " << ugolnaklona << " градусов" << endl;
    //    x += 0.2;
    //}
    //// !!!!!!!!!!!!!!!task2!!!!!!!!!!!!
    //cout << "Задача 2\n";
    //int n;
    //cout << "n= ";
    //cin >> n;
    //for (int i = 10; i <= 99; i++) {
    //    int d1 = i / 10;
    //    int d2 = i % 10;
    //    if (i % n == 0 || d1 == n || d2 == n) {
    //        cout << i << " ";
    //    }
    //}
    //// !!!!!!!!!!!!!!!task3!!!!!!!!!!!!
    //cout << "\nЗадача 3\n";
    //int count = 0;
    //for (int i = 100; i <= 500; i++) {
    //    int sum = 0, x = i;
    //    while (x > 0) {
    //        sum += x % 10;
    //        x /= 10;
    //    }
    //    if (sum == 15) {
    //        count++;
    //    }
    //}
    //cout << "Кол-во: " << count << endl;
    //// !!!!!!!!!!!!!!!task4!!!!!!!!!!!!
    //cout << "Задача 4\n";
    //int num, sum = 0;
    //cout << "Число: ";
    //cin >> num;
    //for (int i = 1; i < num; i++) {
    //    if (num % i == 0) {
    //        sum += i;
    //    }
    //}
    //if (sum == num) {
    //    cout << "Число совершенное" << endl;
    //}
    //else {
    //    cout << "Число не совершенное" << endl;
    //}
//*******************************************urok4************************************************************************
    //int n;//5
    //cin >> n;
    //for (int i = 0; i < n; i++) {
    //    for (int j = 0; j < n; j++) {
    //        if ((i != 0 and i != n - 1 and j != 0 and j != n-1) and (i != j and n - i-1 != j)){
    //            cout << "  ";
    //        }
    //        else cout << "* ";
    //    }
    //    cout << "\n";
    //}
    //for (int i = 1; i <= 100000000; i++) {
    //    int sum = 0;
    //    for (int j = 2; j < i; j++) {
    //        if (i % j == 0) {
    //            sum ++;
    //        }
    //    }
    //    if (sum == 5) { 
    //        cout << i << endl; 
    //    }
    //}
    //int max = 0, imax = 0;
    //for (int i = 1; i <= 1000; i++) {
    //    int sum = 0;
    //    for (int j = 2; j < i; j++) {
    //        if (i % j == 0) {
    //            sum ++;
    //        }
    //    }
    //    if (max < sum) { 
    //        max = sum;
    //        imax = i;
    //    }
    //}
    //cout << max << "    " << imax;
    //for (int i = 1; i <= 9; i++) {
    //    for (int j = 1; j <= 7; j++) {
    //        if (i / j == i / 2 / j / 2) {
    //            cout << i << "/" << j << endl;
    //        }
    //    }
    //}
//*******************************************5dz************************************************************************
    //const int N = 10;
    ////!!!!!!!!!!!!!!!!!!!!!!!!!task1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //cout << "Задача 1\n";
    //int A1[N], iLMax = 0;
    //fillArr(A1, N);
    //printArr(A1, N);
    //for (int i = 1; i < N - 1; i++) {
    //    if (A1[i] > A1[i - 1] && A1[i] > A1[i + 1]) {
    //        iLMax = i;
    //    }
    //}
    //cout << "Номер последнего локального максимума: " << iLMax << "\n";
    ////!!!!!!!!!!!!!!!!!!!!!!!!!task2!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //cout << "Задача 2\n";
    //int A2[N], B2[N];
    //fillArr(A2, N); fillArr(B2, N);
    //printArr(A2, N); printArr(B2, N);
    //for (int i = 0; i < N; i++) {
    //    swap(A2[i], B2[i]);
    //}
    //cout << "Массив A после обмена: ";
    //printArr(A2, N);
    //cout << "Массив B после обмена: ";
    //printArr(B2, N);
    ////!!!!!!!!!!!!!!!!!!!!!!!!!task3!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //cout << "Задача 3\n";
    //int A3[N], B3[N], C3[N], sizeB = 0, sizeC = 0;
    //fillArr(A3, N);
    //printArr(A3, N);
    //for (int i = 0; i < N; i++) {
    //    if (A3[i] > 0) {
    //        B3[sizeB++] = A3[i];
    //    }
    //    else if (A3[i] < 0) {
    //        C3[sizeC++] = A3[i];
    //    }
    //}
    //cout << "Размер массива B=" << sizeB << "\nСодержимое B(+):\n";
    //printArr(B3, sizeB);
    //cout << "Размер массива C=" << sizeC << "\nСодержимое C(-):\n";
    //printArr(C3, sizeC);
//*******************************************6dz************************************************************************
//    int month;
//    const int year = 2025;
//    cout << "Введите номер месяца (1-12): ";
//    cin >> month;
//    if (month < 1 || month > 12) {
//        cout << "Неверный месяц" << endl;
//    }
//    const char days[7][3] = { "Нд", "Пн", "Вт", "Ср", "Чт", "Пт", "Сб" };
//    cout << "\nКалендарь на " << month << "." << year << "\n";
//    for (int i = 0; i < 7; ++i) {
//        if (i == 0 || i == 6)
//            SetColor(Red, Black);
//        else
//            SetColor(LightGray, Black);
//
//        cout << " " << days[i];
//    }
//    SetColor(LightGray, Black);
//    cout << "\n";
//    int startDay = getWeekday(year, month);
//    int daysInMonth = getDaysInMonth(month);
//    for (int i = 0; i < startDay; ++i) {
//        cout << "   ";
//    }
//    for (int day = 1; day <= daysInMonth; ++day) {
//        int currentDay = (startDay + day - 1) % 7;
//        if (currentDay == 0 || currentDay == 6)
//            SetColor(Red, Black);
//        else
//            SetColor(LightGray, Black);
//        if (day < 10) cout << "  " << day;
//        else cout << " " << day;
//        if (currentDay == 6) cout << "\n";
//    }
//    SetColor(LightGray, Black);
//    cout << "\n";
//}
