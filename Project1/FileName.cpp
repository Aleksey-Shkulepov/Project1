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
    //�������� �� �������� � ���������! ��� ���� �� ������ ������ � ������� �� ����
    //char symbol;
    //cout << "������ 1:\n";
    //cout << "������� ������: \n";
    //cin >> symbol;
    //if (((int)symbol >= 65 && (int)symbol <= 90) || ((int)symbol >= 97 && (int)symbol <= 122)) {
    //    cout << "�����\n";
    //}
    //else if ((int)symbol >= 48 && (int)symbol <= 57) {
    //    cout << "�����\n";
    //}
    //else if (((int)symbol >= 33 && (int)symbol <= 47) || ((int)symbol >= 58 && (int)symbol <= 64) ||
    //    ((int)symbol >= 91 && (int)symbol <= 96) || ((int)symbol >= 123 && (int)symbol <= 126)) {
    //    cout << "���������� ���\n";
    //}
    //else {
    //    cout << "��� �� ������\n";
    //}
    ////!!!!!!!!!!!!!!!!!!!!!!! task2 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //cout << "������ 2:\n";
    //double price, fprice;
    //int firssecondoperper, secondoper;
    //cout << "���� ���������(���): ";
    //cin >> price;
    //cout << "�������� 1 (1-Kyivstar, 2-Vodafone, 3-Lifecell): ";
    //cin >> firssecondoperper;
    //cout << "�������� 2 (1-Kyivstar, 2-Vodafone, 3-Lifecell): ";
    //cin >> secondoper;
    //if (firssecondoperper == secondoper)
    //    fprice = price;
    //else
    //    fprice = price * 1.5; //��� ���� ��� ��� �������������� � ������ ���� �� ��������� � ��
    //cout << "�������� ���� ����: " << fprice << " ���\n";
    ////!!!!!!!!!!!!!!!!!!!!!!! task3 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //cout << "������ 3:\n";
    ////1
    //double money;
    //int opozdanie;
    //cout << "1. �������: ����� � ���-�� ���������.\n";
    //cout << "�����: ";
    //cin >> money;
    //cout << "���-�� ���������: ";
    //cin >> opozdanie;
    //int lines = ((money + (opozdanie / 3) * 20) / 50) * 100;
    //cout << "���� �������� " << lines << " �������\n";
    ////2
    //int lines2;
    //double money2;
    //cout << "2.�������: ���-�� ������� � �����.\n";
    //cout << "���-�� �������: ";
    //cin >> lines2;
    //cout << "�����: ";
    //cin >> money2;
    //if ((lines2 / 100) * 50 < money2) {
    //    cout << "������������ �������.\n";
    //}
    //else {
    //    int maxopozdanie = (int)(((lines2 / 100) * 50 - money2) / 20) * 3;
    //    cout << "��� ���������: " << maxopozdanie << "\n";
    //}
    ////3
    //int lines3, opozdanie3;
    //cout << "3.�������: ���-�� ������ � ���������\n";
    //cout << "���-�� ������: ";
    //cin >> lines3;
    //cout << "���-�� ���������: ";
    //cin >> opozdanie3;
    //double money3 = (lines3 / 100) * 50 - (opozdanie3 / 3) * 20;
    //if (money3 <= 0)
    //    cout << "��� �������� :(\n";
    //else
    //    cout << "�� - " << money3 << "��� \n";
    //*******************************************2dz************************************************************************
    ////!!!!!!!!!!!!!!!!!!!!!!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //cout << "������� 1\n";
    //int a1, sum1 = 0;
    //cout << "������� a: ";
    //cin >> a1;
    //if (a1 > 500) {
    //    cout << "������: a > 500.\n";
    //}
    //else {
    //    int i = a1;
    //    while (i <= 500) {
    //        sum1 += i;
    //        i++;
    //    }
    //    cout << "����� ����� �� " << a1 << " �� 500: " << sum1 << "\n";
    //}
    ////!!!!!!!!!!!!!!!!!!!!!!2!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //cout << "������� 2\n";
    //int x, y, pow = 1, count = 0;
    //cout << "������� x: ";
    //cin >> x;
    //cout << "������� y: ";
    //cin >> y;
    //if (y < 0) {
    //    cout << "������: pow < 0\n";
    //}
    //else {
    //    while (count < y) {
    //        pow *= x;
    //        count++;
    //    }
    //    cout << x << " � ������� " << y << " = " << pow<< "\n";
    //}
    ////!!!!!!!!!!!!!!!!!!!!!!3!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //cout << "������� 3\n";
    //int sum3 = 0, n3 = 1;
    //while (n3 <= 1000) {
    //    sum3 += n3;
    //    n3++;
    //}
    //double avg = sum3 / 1000.0;
    //cout << "������� ��������������: " << avg << "\n";
    ////!!!!!!!!!!!!!!!!!!!!!!4!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //cout << "������� 4\n";
    //int a4;
    //cout << "������� a: ";
    //cin >> a4;
    //if (a4 < 1 || a4 > 20) {
    //    cout << "������: a < 1 ��� a > 20\n";
    //}
    //else {
    //    long long product = 1;
    //    int j = a4;
    //    do {
    //        product *= j;
    //        j++;
    //    } while (j <= 20);
    //    cout << "������ �� " << a4 << " �� 20: " << product << "\n";
    //}
    ////!!!!!!!!!!!!!!!!!!!!!!5!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //cout << "������� 5\n";
    //int k;
    //cout << "������� �����: ";
    //cin >> k;
    //int m = 2;
    //while (m <= 9) {
    //    cout << k << " x " << m << " = " << (k * m) << "\n";
    //    m++;
    //}
//*******************************************3dz************************************************************************
    //// !!!!!!!!!!!!!!!task1!!!!!!!!!!!!
    //cout << "������ 1\n";
    //double x = 3.0;
    //while (x <= 4.5) {
    //    double y = sqrt(4.5 * 4.5 - x * x);
    //    double ugolnaklona = atan2(y, x) * 180.0 / pi;
    //    cout << "x = " << x << " �, ���� = " << ugolnaklona << " ��������" << endl;
    //    x += 0.2;
    //}
    //// !!!!!!!!!!!!!!!task2!!!!!!!!!!!!
    //cout << "������ 2\n";
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
    //cout << "\n������ 3\n";
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
    //cout << "���-��: " << count << endl;
    //// !!!!!!!!!!!!!!!task4!!!!!!!!!!!!
    //cout << "������ 4\n";
    //int num, sum = 0;
    //cout << "�����: ";
    //cin >> num;
    //for (int i = 1; i < num; i++) {
    //    if (num % i == 0) {
    //        sum += i;
    //    }
    //}
    //if (sum == num) {
    //    cout << "����� �����������" << endl;
    //}
    //else {
    //    cout << "����� �� �����������" << endl;
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
    //cout << "������ 1\n";
    //int A1[N], iLMax = 0;
    //fillArr(A1, N);
    //printArr(A1, N);
    //for (int i = 1; i < N - 1; i++) {
    //    if (A1[i] > A1[i - 1] && A1[i] > A1[i + 1]) {
    //        iLMax = i;
    //    }
    //}
    //cout << "����� ���������� ���������� ���������: " << iLMax << "\n";
    ////!!!!!!!!!!!!!!!!!!!!!!!!!task2!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //cout << "������ 2\n";
    //int A2[N], B2[N];
    //fillArr(A2, N); fillArr(B2, N);
    //printArr(A2, N); printArr(B2, N);
    //for (int i = 0; i < N; i++) {
    //    swap(A2[i], B2[i]);
    //}
    //cout << "������ A ����� ������: ";
    //printArr(A2, N);
    //cout << "������ B ����� ������: ";
    //printArr(B2, N);
    ////!!!!!!!!!!!!!!!!!!!!!!!!!task3!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //cout << "������ 3\n";
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
    //cout << "������ ������� B=" << sizeB << "\n���������� B(+):\n";
    //printArr(B3, sizeB);
    //cout << "������ ������� C=" << sizeC << "\n���������� C(-):\n";
    //printArr(C3, sizeC);
//*******************************************6dz************************************************************************
//    int month;
//    const int year = 2025;
//    cout << "������� ����� ������ (1-12): ";
//    cin >> month;
//    if (month < 1 || month > 12) {
//        cout << "�������� �����" << endl;
//    }
//    const char days[7][3] = { "��", "��", "��", "��", "��", "��", "��" };
//    cout << "\n��������� �� " << month << "." << year << "\n";
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
