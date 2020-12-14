#include <stdio.h>
#include <ctype.h>

void check_type(int s)
{
    int c = s;
    putchar(c);
    printf("is >> ");
    if (isalpha(c))
        printf("isalpha ");
    if (isdigit(c))
        printf("isdigit ");
    if (isxdigit(c))
        printf("isxdigit ");
    if (isalnum(c))
        printf("isalnum ");
    if (iscntrl(c))
        printf("iscntrl ");
    if (isprint(c))
        printf("isprint ");
    if (ispunct(c))
        printf("ispunct ");
    if (isspace(c))
        printf("isspace ");
    if (isupper(c))
        printf("isupper ");
    if (islower(c))
        printf("islower ");
    putchar('\n');
}

int main()
{
    char *s = "piboqrboi'8 bt7t8635 b1tq\n\t qr ilvq 91 qvb35 q";
    while (*s)
        check_type(*(s++));
}