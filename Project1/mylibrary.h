#pragma once

///12.06.25-15.06.25 My first structure

struct Abonent
{
    char* name = nullptr;
    unsigned long long phone = 0;
};

Abonent* searchByName(Abonent* user, size_t size, const char* name) {
    for (size_t i = 0; i < size; i++)
        if (strcmp(user[i].name, name) == 0)
            return &user[i];
    return nullptr;
}

Abonent* searchByPhone(Abonent* user, size_t size, unsigned long long phone) {
    for (size_t i = 0; i < size; i++) 
        if (user[i].phone == phone)
            return &user[i];
    return nullptr;
}

void editContact(Abonent* user, size_t size, const char* name, unsigned long long phone) {
    for (size_t i = 0; i < size; i++) {
        if (strcmp(user[i].name, name) == 0 || user[i].phone == phone) {
            strcpy(user[i].name, name);
            user[i].phone = phone;
        }
    }
}

///08.06.25-12.06.25 hw

/// <summary>
/// Считает количество нахождений заданого слова(заданой строки) в основной строке
/// </summary>
/// <param name="str1"> Основная строка(в ней осуществляеться поиск) </param>
/// <param name="str2"> Указаная строка которую нужно найти </param>
/// <returns> Возвращает количество нахождений заданого слова(заданой строки) </returns>
unsigned int countIncludingWord(const char* str1, const char* str2) 
{
    size_t count = 0, reapets = 0, len1 = lenStr(str1), len2 = lenStr(str2);
    for (size_t i = 0; i <= len1 - len2; i++)
    {
        for (size_t j = 0; j < len2; j++)
            if (str1[i + j] == str2[j]) count++;
        if (count == len2) reapets++;
        count = 0;
    }
    return reapets;
}

/// <summary>
/// Считает количество предложений в строке
/// </summary>
/// <param name="str">Заданная строка</param>
/// <returns>Возвращает количество предложений в строке</returns>
unsigned int countSentences(const char* str)
{
    size_t count = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] == '.' || str[i] == '!' || str[i] == '?') 
            count++;
    return count;
}

/// <summary>
/// Считает количество знаков пункутации(запятая, точка) в строке
/// </summary>
/// <param name="str"> Заданная строка </param>
/// <returns> Возвращает количество знаков пункутации(запятая, точка) в строке </returns>
unsigned int countPunctuation(const char* str) {
    size_t count = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] == '.' || str[i] == ',')
            count++;
    return count;
}

/// <summary>
/// Переворачивает задом наперед строку
/// </summary>
/// <param name="str"> Заданная строка </param>
void reverseString(char* str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++)
        swap(str[i], str[len - i - 1]);
}

/// <summary>
/// Второстепенная функция для reverseEachSentence
/// </summary>
/// <param name="start"> Адрес первого елемента </param>
/// <param name="end"> Адрес последнего елемента </param>
void _reverseWord(char* start, char* end) {
    while (start < end) {
        swap(*start, *end);
        start++;
        end--;
    }
}

/// <summary>
/// Переворачивает задом наперед каждое предложение строки
/// </summary>
/// <param name="str"> Заданная строка </param>
void reverseEachSentence(char* str) {
    size_t len = strlen(str); char* start = str;
    for (size_t i = 0; i <= len; i++) {
        if (str[i] == '.' || str[i] == '!' || str[i] == '?' || str[i] == '\0') {
            _reverseWord(start, str + i - 1);
            start = str + i + 1;
        }
    }
}

///04.06.25-08.06.25 hw

unsigned int mylenstr(const char* str)
{
    size_t s = 0;
    while (str[s] != '\0')
        s++;
    return s;
}

char* mystrcpy(char* str1, const char* str2)
{
    for (size_t i = 0; i < lenStr(str1); i++)
        str1[i] = str2[i];
    return str1;
}

char* mystrcat(char* str1, const char* str2)
{
    size_t len1 = lenStr(str1), len2 = lenStr(str2);
    for (size_t i = 0; i < len2 + 1; i++)
        str1[len1 + i] = str2[i];
    return str1;
}

char* mystrchr(char* str, char s)
{
    for (size_t i = 0; i < lenStr(str); i++)
        if (str[i] == s) return str + i;
    return 0;
}

char* mystrstr(char* str1, const char* str2)
{
    size_t count = 0, len1 = lenStr(str1), len2 = lenStr(str2);
    for (size_t i = 0; i <= len1 - len2; i++)
    {
        for (size_t j = 0; j < len2; j++)
            if (str1[i + j] == str2[j]) count++;
        if (count == len2) return str1 + i;
        else count = 0;
    }
    return 0;
}

/// 24.05.25 My first class

template<typename T>
class myVector {
private:
    T* arr;
    size_t s;
public:
    /// Перегрузка оператора [] (индексирования)
    T& operator[] (size_t index)
    {
        return arr[index];
    }

    /// Перегрузка оператора = (присваивания)
    myVector& operator = (const myVector& other)
    {
        this->s = other.s;

        delete this->arr;

        this->arr = new T[other.s];

        for (size_t i = 0; i < other.s; i++)
        {
            this->arr[i] = other.arr[i];
        }

        return *this;
    }

    /// Конструктор копирования
    myVector(const myVector& other)
    {
        this->s = other.s;

        this->arr = new T[other.s];

        for (size_t i = 0; i < other.s; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }

    /// Конструктор по умол.
    myVector()
    {
        arr = nullptr;
        s = 0;
    }

    /// Конструктор с параметрами
    myVector(size_t s, T n = 0)
    {
        this->s = s;

        this->arr = new T[s];

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
    void add(T elem) {
        T* newArr = new T[s + 1];

        for (size_t i = 0; i < s; i++)
            newArr[i] = arr[i];
        newArr[s] = elem;

        delete[] arr;
        arr = newArr;

        this->s++;
    }

    /// Вставляет элемент на указанную позицую вектора
    bool insert(T elem, size_t pos) {
        if (pos >= this->s) 
            return false;

        T* newArr = new T[s + 1];

        for (size_t i = 0, j = 0; i < s + 1; i++)
            newArr[i] = (i != pos) ? arr[j++] : elem;

        delete[] arr;
        arr = newArr;

        this->s++;
    }

    /// Удаляет элемент вектора на указаной позиции
    bool pop(size_t pos) {
        if (pos >= this->s) 
            return false;

        T* newArr = new T[s - 1];

        for (size_t i = 0, j = 0; i < s; i++)
            if (i != pos) newArr[j++] = arr[i];

        delete[] arr;
        arr = newArr;

        this->s--;
    }

    /// Расширяет вектор до n-го размера элементов
    void resize(size_t s, T value = 0) {
        T* newArr = new T[s];

        size_t min_s = (s < this->s) ? s : this->s;

        for (size_t i = 0; i < min_s; i++)
            newArr[i] = arr[i];
        for (size_t i = min_s; i < s; i++)
            newArr[i] = value;

        delete[] arr;
        arr = newArr;

        this->s = s;
    }

    /// Заполняет вектор рандомными числами от мин(по умол. 0) до макс(по умол. 9)
    void fill(T min = 0, T max = 9)
    {
        for (auto i = 0; i < s; i++)
        {
            arr[i] = rand() % ((int)max - (int)min + 1) + min;
        }
    }

    /// Сортирует вектор, по умол. от мин до макс
    void sort(bool(*comp)(T, T) = asc)
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
        return this->s;
    }
};