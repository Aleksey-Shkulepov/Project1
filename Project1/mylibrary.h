#pragma once

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
