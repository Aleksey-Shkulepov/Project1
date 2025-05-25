#pragma once

#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<algorithm>
#include<conio.h>

using namespace std;

/// <Переменные>
const long double pi = 3.14159265358979L;
/// </Переменные>

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

/// <Функции>

/// Просто существуют
void printArr(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<class T>
void fillArr(T arr[], size_t N) {
    for (size_t i = 0; i < N; i++)
    {
        arr[i] = rand() % 10;
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
bool defcomp(T a, T b) {
    return a > b;
}

template<class T>
void bubbleSort(T arr[], size_t size, bool(*comp)(T a, T b) = defcomp)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - 1 - i; j++)
        {
            if (comp(arr[j], arr[j + 1])) swap(arr[j], arr[j + 1]);
        }
    }
}

template<typename T, size_t ROWS, size_t COLS>
bool isNumberInArr(T(&arr)[ROWS][COLS], T value) {
    for (size_t i = 0; i < ROWS; i++)
        for (size_t j = 0; j < COLS; j++)
            if (arr[i][j] == value)
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
    const char* kozirs[] = { "черва", "бубна", "пика", "трефы" };
    if (price >= 0 && price <= 8 && kozir >= 0 && kozir <= 3) cout << prices[price] << " " << kozirs[kozir] << endl;
    else cout << "Некоректные вводные данные" << endl;
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
    cout << "Пабеда";
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
    delete arr;
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
    delete arr;
    return newArr;
}

///insertElemInArr
template<class T>
T* insert(T* arr, size_t size, T elem, size_t pos) {
    T* newArr = new T[size + 1];
    for (size_t i = 0, j = 0; i < size + 1; i++)
        /// Ура хоть где-то тернарник пригодился
        newArr[i] = (i != pos) ? arr[j++] : elem;
    delete arr;
    return newArr;
}

///removeElemInArr
template<class T>
T* pop(T* arr, size_t size, size_t pos) {
    T* newArr = new T[size - 1];
    for (size_t i = 0, j = 0; i < size; i++)
        if (i != pos) 
            newArr[j++] = arr[i];
    delete arr;
    return newArr;
}

/// </Функции>

/// <Классы>
class myVector {
private:
    int *arr;
    size_t s;
public:
    /// Перегрузка оператора =
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
    /// Конструктор по умол.
    myVector(){}

    /// Конструктор копирования
    myVector(const myVector &other) 
    {
        this -> s = other.s;

        this -> arr = new int[other.s];

        for (size_t i = 0; i < other.s; i++)
        {
            this -> arr[i] = other.arr[i];
        }
    }

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

    /// <Методы>
    
    ///Добавляет указанный елемент в конец вектора
    void add(int elem) {
        int* newArr = new int[s + 1];

        for (size_t i = 0; i < s; i++)
            newArr[i] = arr[i];
        newArr[s] = elem;

        delete[] arr;
        arr = newArr;

        this -> s++;
    }

    ///Вставляет указанный елемент в указаную позицую вектора
    bool insert(int elem, size_t pos) {
        if (pos >= this -> s) { cout << "Ошибка. Такой позиции в векторе не существует(out of range)\n"; return false; }

        int* newArr = new int[s + 1];

        for (size_t i = 0, j = 0; i < s + 1; i++)
            newArr[i] = (i != pos) ? arr[j++] : elem;

        delete[] arr;
        arr = newArr;

        this -> s++;
    }

    ///Удаляет елемент в указаной позиции вектора
    bool pop(size_t pos) {
        if (pos >= this -> s) { cout << "Ошибка. Такой позиции в векторе не существует(out of range)\n"; return false; }

        int* newArr = new int[s - 1];

        for (size_t i = 0, j = 0; i < s; i++)
            if (i != pos) newArr[j++] = arr[i];

        delete[] arr;
        arr = newArr;

        this -> s--;
    }

    ///Розширяет/Уменьшает вектор до n-го кол-ва елементов(Меняет кол-во елементов на n)
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

    ///Выводит вектор на экран/консоль
    void print() const {
        for (size_t i = 0; i < s; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int size() const {
        return this -> s;
    }
};
/// </Классы>