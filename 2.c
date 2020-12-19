#include <stdio.h>

int main()
{
    char *a = "qwer2331";
    char *b = "qwerabcd";
    char c[10], d[10];
    printf("%s\n%s\n", a, b);
    printf("identical >> %d\n", compare(a, b));
    printf("remaining after identical:\na >> %d\nb >> %d\n\n", len(a) - compare(a, b), len(b) - compare(a, b));
    deltacopy(a, b, c);//Подсчет количество символов, остающихся после последнего совпадения в каждой из строк
    mixcopy(a, b, d);
    printf("delta >> %s\nmix >> %s\n", c, d);
}

int compare(char *a, char *b)
{
    int len = 0;
    while (*(a + len) && *(b + len))
    {
        if (*(a + len) == *(b + len))
            len++;
        else
            return len;
    }
    return len; // Проверка, сколько первых символов в строках совпадают.
}

int len(char *s)
{
    char *c = s;
    while (*(s++))
        continue;
    return s - c - 1;
}

void deltacopy(char *a, char *b, char *c)//Составление новой строки(начать символами первой строки, а продолжить из второй)
{
    int idc = compare(a, b);
    a += idc;
    b += idc;
    for (; len(a); a++)
        *(c++) = *a;
    for (; len(b); b++)
        *(c++) = *b;
}

void mixcopy(char *a, char *b, char *c)//Составление новой строки(начать с первого символа первой строки, затем первый символ втоpой, второй символ первой и т.д.)
{
    int idc = compare(a, b);
    a += idc;
    b += idc;
    for (; len(a) + len(b); a++, b++)
    {
        *(c++) = *a;
        *(c++) = *b;
    }
}
