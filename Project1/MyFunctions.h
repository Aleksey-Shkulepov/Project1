#pragma once

#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<algorithm>
#include<conio.h>

using namespace std;

/// <Переменные константы>
const long double pi = 3.14159265358979L;
/// </Переменные константы>

/// <Енумы>
enum DIRECTION
{
    UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, ESC = 27
};

enum Color {
    Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7,
    DarkGray = 8, LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12,
    LightMagenta = 13, Yellow = 14, White = 15
};
/// </Енумы>

/// <Фукнции>

template<class T>
void printArr(T arr[], size_t N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<class T>
void fillArr(T arr[], size_t size, T min = 0, T max = 9)
{
    for (auto i = 0; i < size; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

template<typename T, size_t ROWS, size_t COLS>
void printArr(const T(&arr)[ROWS][COLS]) {
    for (size_t i = 0; i < ROWS; i++) {
        for (size_t j = 0; j < COLS; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T>
bool asc(T a, T b) {
    return a > b;
}

template<class T>
void bubbleSort(T arr[], size_t size, bool(*comp)(T, T) = asc)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - 1 - i; j++)
        {
            if (comp(arr[j], arr[j + 1])) swap(arr[j], arr[j + 1]);
        }
    }
}

template<class T, size_t ROWS, size_t COLS>
bool isNumberInArr(T(&arr)[ROWS][COLS], T value) {
    for (size_t i = 0; i < ROWS; i++)
        for (size_t j = 0; j < COLS; j++)
            if (arr[i][j] == value)
                return true;
    return false;
}

template<class T>
bool isNumberInArr(T* arr, size_t size, T value) {
    for (size_t i = 0; i < size; i++)
        if (arr[i] == value)
            return true;
    return false;
}

template<class T, size_t ROWS, size_t COLS>
void fillArr(T(&arr)[ROWS][COLS], T min = 0, T max = 9, bool repeat = true) {
    if (repeat) {
        for (size_t i = 0; i < ROWS; i++) {
            for (size_t j = 0; j < COLS; j++) {
                arr[i][j] = rand() % (max - min + 1) + min;
            }
        }
    }
    else {
        for (size_t i = 0; i < ROWS; i++) {
            for (size_t j = 0; j < COLS; j++) {
                T num;
                do {
                    num = rand() % (max - min + 1) + min;
                } while (isNumberInArr(arr, num));
                arr[i][j] = num;
            }
        }
    }
}

/// 14.05.25 h/w
void SetColor(int text, int background) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}

int getDaysInMonth(int month) {
    if (month == 2) return 28;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    return 31;
}

int getWeekday(int year, int month) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int K = year % 100;
    int J = year / 100;
    int h = (1 + 13 * (month + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
    int d = ((h + 6) % 7);
    return d;
}
/// 17.05.25 h/w
int power(int a, int b) {
    int res = 1;
    for (int i = 0; i < b; i++) {
        res *= a;
    }
    return res;
}

int sumInRange(int a, int b) {
    int start, end, sum = 0;
    if (a < b) { start = a; end = b; }
    else { start = b; end = a; }
    for (int i = start; i <= end; i++) {
        sum += i;
    }
    return sum;
}

void findPerfectnums(int start, int end) {
    for (int i = start; i <= end; i++) {
        int sum = 0;
        for (int j = 1; j < i; j++) {
            if (i % j == 0) sum += j;
        }
        if (sum == i) cout << i << " ";
    }
    cout << endl;
}

void printCard(int price, int kozir) {
    price -= 6;
    const char* prices[] = { "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    const char* kozirs[] = { "÷åðâà", "áóáíà", "ïèêà", "òðåôû" };
    if (price >= 0 && price <= 8 && kozir >= 0 && kozir <= 3) cout << prices[price] << " " << kozirs[kozir] << endl;
    else cout << "Íåêîðåêòíûå ââîäíûå äàííûå" << endl;
}

bool isLuckyTicket(int num) {
    return num % 10 + num / 10 % 10 + num / 100 % 10 == num / 1000 % 10 + num / 10000 % 10 + num / 100000 % 10;
}
/// 17.05.25 lesson
void hill(int arr[], int temp[], int size)
{
    bubbleSort(arr, size);
    for (size_t i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            temp[i / 2] = arr[i];
        }
        else
        {
            temp[size - 1 - i / 2] = arr[i];
        }
    }

}
/// 21.05.25 lesson
template<class T>
int lineSearch(T arr[], T key, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == key) return i;
    }
    return -1;
}

template<class T>
int rlineSearch(T arr[], T key, int size) {
    for (int i = size - 1; i >= 0; i--)
    {
        if (arr[i] == key) return i;
    }
    return -1;
}

template<class T>
double avgArray(T arr[], size_t size)
{
    T sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return (double)sum / size;
}

double avgArray(int arr[], size_t size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return (double)sum / size;
}

int maxArray(int arr[], size_t size)
{
    int max = arr[0];
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

template<class T>
T maxArray(T arr[], size_t size)
{
    T max = arr[0];
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

template<class T>
T sumArray(T arr[], int size)
{
    T sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

template<class T1, class T2>
auto sum(T1 a, T2 b) -> decltype(a + b)
{
    return a + b;
}

float avg(int a, int b, int c)
{
    return (a + b + c) / 3.f;
}

bool isEven(int a)
{
    return a % 2 == 0;
}

/// 21.05.25 h/w

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

template<class T, size_t ROWS, size_t COLS>
void moveUp(T(&arr)[ROWS][COLS], int x, int y) {
    swap(arr[y][x], arr[y + 1][x]);
}

template<class T, size_t ROWS, size_t COLS>
void moveDown(T(&arr)[ROWS][COLS], int x, int y) {
    swap(arr[y][x], arr[y - 1][x]);
}

template<class T, size_t ROWS, size_t COLS>
void moveLeft(T(&arr)[ROWS][COLS], int x, int y) {
    swap(arr[y][x], arr[y][x + 1]);
}

template<class T, size_t ROWS, size_t COLS>
void moveRight(T(&arr)[ROWS][COLS], int x, int y) {
    swap(arr[y][x], arr[y][x - 1]);
}

template<typename T, size_t ROWS, size_t COLS>
bool isWin(T(&arr)[ROWS][COLS]) {
    T WinArr[ROWS][COLS] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    for (size_t i = 0; i < ROWS; i++) {
        for (size_t j = 0; j < COLS; j++) {
            if (arr[i][j] != WinArr[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void gameFifteen() {
    CONSOLE_CURSOR_INFO curs;
    curs.dwSize = 25;
    curs.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curs);

    int x = 0, y = 0; const int s = 4; bool win = false;

    int arr[s][s];
    fillArr(arr, 0, 15, false);

    for (size_t i = 0; i < s; i++) {
        for (size_t j = 0; j < s; j++) {
            if (arr[i][j] == 0) {
                x = j; y = i;
            }
        }
    }

    gotoxy(0, 0);
    printArr(arr);

    while (not win)
    {
        if (_kbhit())
        {
            char c = _getch();
            switch (c)
            {
            case UP:
                if (y < s - 1) { moveUp(arr, x, y); y++; }
                break;
            case DOWN:
                if (y > 0) { moveDown(arr, x, y); y--; }
                break;
            case LEFT:
                if (x < s - 1) { moveLeft(arr, x, y); x++; }
                break;
            case RIGHT:
                if (x > 0) { moveRight(arr, x, y); x--; }
                break;
            default:
                break;
            }
            gotoxy(0, 0);
            printArr(arr);
        }
        win = isWin(arr);
    }
    cout << "Ïàáåäà";
}
/// 24.05.25 lesson

///addElemtoArr
template<class T>
T* add(T* arr, size_t size, T elem) {
    T* newArr = new T[size + 1];
    for (size_t i = 0; i < size + 1; i++)
    {
        newArr[i] = arr[i];
    }
    newArr[size] = elem;
    delete[] arr;
    return newArr;
}
/// 24.05.25 h/w

///delLastElemArr
template<class T>
T* deletelast(T* arr, size_t size) {
    T* newArr = new T[size - 1];
    for (size_t i = 0; i < size - 1; i++)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;
    return newArr;
}

///insertElemInArr
template<class T>
T* insert(T* arr, size_t size, T elem, size_t pos) {
    T* newArr = new T[size + 1];
    for (size_t i = 0, j = 0; i < size + 1; i++)
        newArr[i] = (i != pos) ? arr[j++] : elem;
    delete[] arr;
    return newArr;
}

///removeElemInArr
template<class T>
T* pop(T* arr, size_t size, size_t pos) {
    if (pos >= size or pos < 0) return nullptr;
    T* newArr = new T[size - 1];
    for (size_t i = 0, j = 0; i < size; i++)
        if (i != pos) 
            newArr[j++] = arr[i];
    delete[] arr;
    return newArr;
}

///28.05.25 lesson

void my_swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;

    cout << a << " " << b << endl;
}

template<class T>
void margeArrs(T* arr1, size_t size1, const T* arr2, size_t size2, T*& arr3, size_t& size3)
{
    size3 = size1 + size2;
    arr3 = new T[size1 + size2];
    for (size_t i = 0; i < size1; i++)
    {
        arr3[i] = arr1[i];
    }
    for (size_t i = 0; i < size2; i++)
    {
        arr3[i + size1] = arr2[i];
    }
}

void delValueArray(int*& arr, size_t& size, bool isEven = true)
{
    size_t newSize = 0;
    int* temp = nullptr;
    if (isEven)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (arr[i] % 2 == 0)
                newSize++;
        }
        temp = new int[newSize];
        newSize = 0;
        for (size_t i = 0; i < size; i++)
        {
            if (arr[i] % 2 == 0)
                temp[newSize++] = arr[i];
        }
    }
    else
    {
        for (size_t i = 0; i < size; i++)
        {
            if (arr[i] % 2 != 0)
                newSize++;
        }
        temp = new int[newSize];
        newSize = 0;
        for (size_t i = 0; i < size; i++)
        {
            if (arr[i] % 2 != 0)
                temp[newSize++] = arr[i];
        }
    }

    delete arr;
    size = newSize;
    arr = temp;
}

template<class T>
void bublik(T*& arr, size_t size, int& sum, int& dobutok)
{
    sum = 0, dobutok = 1;
    for (size_t i = 0; i < size; i++)
    {
        sum += arr[i];
        dobutok *= arr[i];
    }

}

///28.05.25 h/w

template<class T>
void delIncludeElems(T* arr1, size_t size1, T* arr2, size_t size2, T*& arr3, size_t& size3)
{
    size3 = 0;
    for (int i = 0; i < size1; i++) {
        if (!isNumberInArr(arr2, size2, arr1[i]) && !isNumberInArr(arr3, size3, arr1[i])) {
            arr3[size3] = arr1[i];
            size3++;
        }
    }
}

template<class T>
void colabDifferentInArrs(T* arr1, size_t size1, T* arr2, size_t size2, T*& arr3, size_t& size3)
{
    size3 = 0;
    for (size_t i = 0; i < size1; i++)
    {
        if (!isNumberInArr(arr2, size2, arr1[i]) && !isNumberInArr(arr3, size3, arr1[i]))
            arr3[i] = arr1[i];
            size3++;
    }
    for (size_t i = 0; i < size2; i++)
    {
        if (!isNumberInArr(arr1, size1, arr2[i]) && !isNumberInArr(arr3, size3, arr2[i]))
            arr3[i] = arr2[i];
            size3++;
    }
}

///31.05.25 lesson

template<class T>
bool uniqcomp(T a, T b) 
{
    if (a % 10 > b % 10)
    {
        if (a / 10 > b / 10)
        {
            return a > b;
        }
    }
    return a < b;
}

template<class T>
double Action(T* arr1, T* arr2, size_t size1, size_t size2, double(*method)(int*, size_t))  
{
    size_t size3;
    T* arr3 = nullptr;
    margeArrs(arr1, size1, arr2, size2, arr3, size3);

    return method(arr3, size3);
}

///31.05.25-04.06.25 hw

/// <summary>
/// Сложение чисел а и b
/// </summary>
template<class T>
T addition(T a, T b) {
    return a + b;
}

/// <summary>
/// Вычитание числа b от а
/// </summary>
template<class T>
T subtraction(T a, T b) {
    return a - b;
}

/// <summary>
/// Умножение чисел a и b
/// </summary>
template<class T>
T multiplication(T a, T b) {
    return a * b;
}

/// <summary>
/// Деление числа a на b
/// </summary>
template<class T>
T division(T a, T b) {
    return a / b;
}

/// <summary>
/// Введение числа а в степень числа b
/// </summary>
template<class T>
T power(T a, T b) {
    T res = 1;
    for (size_t i = 0; i < b; i++) {
        res *= a;
    }
    return res;
}

double(*methods[])(double, double) = { addition, subtraction, multiplication, division, power };

template<class T>
T Calculate(T Num1, T Num2, T(*method)(T, T)) 
{
    return method(Num1, Num2);
}

///04.06.25 lesson

size_t lenStr(const char* str)
{
    size_t s = 0;
    while (str[s] != '\0')
        s++;
    return s;
}

char* delSymbol(const char* str, size_t pos)
{
    size_t tempS = lenStr(str);
    if (pos >= tempS) return nullptr;
    char* temp = new char[tempS + 1];
    for (size_t i = 0; i <= tempS; i++)
    {
        temp[i] = str[i];
    }
    char* res = pop(temp, tempS + 1, pos);
    return res;
}

char* addSymbol(const char* str, char elem,  size_t pos)
{
    size_t tempS = lenStr(str);
    if (pos >= tempS) return nullptr;
    char* temp = new char[tempS + 1];
    for (size_t i = 0; i <= tempS; i++)
    {
        temp[i] = str[i];
    }
    char* res = insert(temp, tempS + 1, elem, pos);
    return res;
}

//11.06.2025
template<class T>
void createArray2D(T**& arr, size_t row, size_t col) {
    arr = new T*[row];
    for (size_t i = 0; i < row; i++)
    {
        arr[i] = new T[col];
    }
}


void fillArray2D(int** arr, int row, int col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }
}

template<class T>
void printArray2D(T** arr, int row, int col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T>
void deleteArray2D(T**& arr, int row)
{
    for (size_t i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;
}

template<class T>
void addRowArray2D(T**& arr, int& row, int col)
{
    T** temp = new T* [row + 1];
    for (size_t i = 0; i < row; i++)
    {
        temp[i] = arr[i];
    }
    temp[row] = new T[col]{ 0 };
    row++;
    delete[] arr;
    arr = temp;
}

template<class T>
void deleteRowArray2D(T**& arr, int& row, int col)
{
    T** temp = new T * [row - 1];
    for (size_t i = 0; i < row - 1; i++)
    {
        temp[i] = arr[i];
    }
    delete[] arr[row - 1];
    row--;
    delete[] arr;
    arr = temp;
}

template<class T>
void insertRowArray2D(T**& arr, int& row, int col, size_t pos) {
    T** temp = new T * [row + 1];
    for (size_t i = 0, j = 0; i < row + 1; i++)
        temp[i] = (i != pos) ? arr[j++] : new T[col]{ 0 };
    row++;
    delete[] arr;
    arr = temp;
}

template<class T>
void popRowArray2D(T**& arr, int& row, int col, size_t pos) {
    T** temp = new T * [row - 1];
    for (size_t i = 0, j = 0; i < row; i++)
        if (i != pos) temp[j++] = arr[i];
    row--;
    delete[] arr;
    arr = temp;
}

void delZeroRow(int**& arr, int& row, int col)
{
    for (size_t i = 0; i < row; i++)
    {
        if (lineSearch(arr[i], 0, col) != -1)
        {
            popRowArray2D(arr, row, col, i--);
        }
    }
}

template<class T>
void trancportArray2D(T**& arr, int& row, int &col)
{
    T** temp = nullptr;
    createArray2D(temp, col, row);
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            temp[j][i] = arr[i][j];
        }
    }

    deleteArray2D(arr, row);
    swap(row, col);
    arr = temp;
}

/// </Фукнции>

/// <Классы>
class myVector {
private:
    int *arr;
    size_t s;
public:
    /// Перегрузка оператора [] (индексирования)
    int &operator[] (int index)
    {
        return arr[index];
    }

    /// Перегрузка оператора = (присваивания)
    myVector &operator = (const myVector &other) 
    {
        this -> s = other.s;

        delete this -> arr;

        this -> arr = new int[other.s];

        for (size_t i = 0; i < other.s; i++)
        {
            this -> arr[i] = other.arr[i];
        }

        return *this;
    }

    /// Конструктор копирования
    myVector(const myVector& other)
    {
        this->s = other.s;

        this->arr = new int[other.s];

        for (size_t i = 0; i < other.s; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }

    /// Конструктор по умол.
    myVector() {}

    /// Конструктор с параметрами
    myVector(size_t s, int n = 0)
    {
        this -> s = s;

        this -> arr = new int[s];

        for (size_t i = 0; i < s; i++)
        {
            arr[i] = n;
        }
    }

    /// Деструктор
    ~myVector() 
    {
        delete[] arr;
    }
    
    /// Добавляет указанный элемент в конец вектора
    void add(int elem) {
        int* newArr = new int[s + 1];

        for (size_t i = 0; i < s; i++)
            newArr[i] = arr[i];
        newArr[s] = elem;

        delete[] arr;
        arr = newArr;

        this -> s++;
    }

    /// Вставляет элемент на указанную позицую вектора
    bool insert(int elem, size_t pos) {
        if (pos >= this -> s) { cout << "Ошибка. Указанный индекс не находиться в диапозоне вектора (оut of range)\n"; return false; }

        int* newArr = new int[s + 1];

        for (size_t i = 0, j = 0; i < s + 1; i++)
            newArr[i] = (i != pos) ? arr[j++] : elem;

        delete[] arr;
        arr = newArr;

        this -> s++;
    }

    /// Удаляет элемент вектора на указаной позиции
    bool pop(size_t pos) {
        if (pos >= this -> s) { cout << "Ошибка. Указанный индекс не находиться в диапозоне вектора (out of range)\n"; return false; }

        int* newArr = new int[s - 1];

        for (size_t i = 0, j = 0; i < s; i++)
            if (i != pos) newArr[j++] = arr[i];

        delete[] arr;
        arr = newArr;

        this -> s--;
    }

    /// Расширяет вектор до n-го размера элементов
    void resize(size_t s, int value = 0) {
        int* newArr = new int[s];

        size_t min_s = (s < this -> s) ? s : this -> s;

        for (size_t i = 0; i < min_s; i++)
            newArr[i] = arr[i];
        for (size_t i = min_s; i < s; i++)
            newArr[i] = value;

        delete[] arr;
        arr = newArr;

        this -> s = s;
    }

    /// Заполняет вектор рандомными числами от мин(по умол. 0) до макс(по умол. 9)
    void fill(int min = 0, int max = 9)
    {
        for (auto i = 0; i < s; i++)
        {
            arr[i] = rand() % (max - min + 1) + min;
        }
    }

    /// Сортирует вектор, по умол. от мин до макс
    void sort(bool(*comp)(int, int) = asc)
    {
        for (size_t i = 0; i < s - 1; i++)
        {
            for (size_t j = 0; j < s - 1 - i; j++)
            {
                if (comp(arr[j], arr[j + 1])) swap(arr[j], arr[j + 1]);
            }
        }
    }

    /// Выводит вектор в консоль
    void print() const {
        for (size_t i = 0; i < s; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    /// Возвращает размер вектора
    int get_size() const {
        return this -> s;
    }
};
/// </Классы>
