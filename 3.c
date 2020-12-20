#include <stdio.h>

int main()
{
    char *s = "12345.6789";
    char c[12];
    printf("целая часть : %d\n", num(s));
    reverse(s, c, len(s));
    printf("перевернутая : %s\n", c);
}

int num(char *s)
{
    char *c = s;
    while (*s)
    {
        if (*s < '0' || *s > '9')
            if (*s == '.' || *s == ',')
                return s - c;
        s++;
    }
    return s - c;
}

int len(char *s)
{
    char *c = s;
    while (*(s++))
        continue;
    return s - c - 1;
}

void reverse(char *s, char *c, int size)
{
    s += size - 1;
    for (int i = 0; i < size; i++)
        *(c++) = *(s--);
    *c = 0;
}
