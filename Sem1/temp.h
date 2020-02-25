#include <stdio.h>
#include <stdlib.h>

int codelen(char* code)
{
    int l = 0;
    while (*(code + l) != '\0')
        l++;
    return l;
}


void strconcat(char* str, char* parentcode, char add)
{
    int i = 0;
    while (*(parentcode + i) != '\0')
    {
        *(str + i) = *(parentcode + i);
        i++;
    }
    if (add != '2')
    {
        str[i] = add;
        str[i + 1] = '\0';
    }
    else
        str[i] = '\0';
}


int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
