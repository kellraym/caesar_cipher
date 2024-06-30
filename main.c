#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define UPPER_BOTTOM 65
#define UPPER_TOP 90
#define LOWER_BOTTOM 97
#define LOWER_TOP 122

// TODO rotate chars
// output encrypted/decrypted message

int rotate(int c, int r, int bottom)
{
    return (c - bottom + r) % 26 + bottom;
}

// rotates input int c by r or returns non-alpha c
int encrypt(int c, int r)
{
    if (c >= UPPER_BOTTOM && c <= UPPER_TOP)
    {
        return rotate(c, r, UPPER_BOTTOM);
    }
    else if (c >= LOWER_BOTTOM && c <= LOWER_TOP)
    {
        return rotate(c, r, LOWER_BOTTOM);
    }

    return c;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Missing arguments!");
        exit(1);
    }

    int ch;
    for (int i = 0; i < strlen(argv[1]); ++i)
    {
        putchar(encrypt(argv[1][i], 3));
    }
    return EXIT_SUCCESS;
}