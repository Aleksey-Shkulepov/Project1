#pragma once

///04.06.25-08.06.25 hw

size_t mylenstr(const char* str)
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
