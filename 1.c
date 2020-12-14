#include <stdio.h>

int len(char *s)
{
    char *c = s;
    while (*(s++))
        continue;
    return s - c - 1;
}

void copy(char *s, char *ss, int len)
{
    for (int i = 0; i <= len; i++)
        *(ss++) = *(s++);
}

void nwcount(char *s, int *chars, int *nums)
{
    while (*s)
    {
        if (*s >= '0' && *s <= '9')
            (*nums)++;
        if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))
            (*chars)++;
        s++;
    }
}

void strangesort(char *s, char *chars, char *nums)
{
    while (*s)
    {
        if (*s >= '0' && *s <= '9')
            *(nums++) = *s;
        if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'))
            *(chars++) = *s;
        s++;
    }
    *nums = *chars = '\0';
}

int main()
{
    char *str = "some string";
    char st[12], nm[8], chr[9];
    copy(str, st, len(str));
    printf("l >> %d\n", len(str));
    printf("copied string >> %s\n", st);
    char *nw = "few498rqv9vr184";
    int chars = 0, nums = 0;
    nwcount(nw, &chars, &nums);
    printf("Nums: %d, chars: %d\n", nums, chars);
    strangesort(nw, chr, nm);
    printf("Nums: %s\nChars: %s\nMixed: %s%s\n", nm, chr, nm, chr);
}