#include <stdio.h>

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
    return len;
}

int len(char *s)
{
    char *c = s;
    while (*(s++))
        continue;
    return s - c - 1;
}

void deltacopy(char *a, char *b, char *c)
{
    int idc = compare(a, b);
    a += idc;
    b += idc;
    for (; len(a); a++)
        *(c++) = *a;
    for (; len(b); b++)
        *(c++) = *b;
}

void mixcopy(char *a, char *b, char *c)
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

int main()
{
    char *a = "abcd1234";
    char *b = "abcdefgh";
    char c[10], d[10];
    printf("%s\n%s\n", a, b);
    printf("identical >> %d\n", compare(a, b));
    printf("remaining after identical:\na >> %d\nb >> %d\n\n", len(a) - compare(a, b), len(b) - compare(a, b));
    deltacopy(a, b, c);
    mixcopy(a, b, d);
    printf("delta >> %s\nmix >> %s\n", c, d);
}