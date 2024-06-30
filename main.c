#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define UPPER_BOTTOM 65
#define UPPER_TOP 90
#define LOWER_BOTTOM 97
#define LOWER_TOP 122

int str_to_int(char *arg)
{
    int result = 0;
    int factor = 1; 
    for (int i = strlen(arg) - 1; i >= 0; i--)
    {   
        if (arg[i] < '0' || arg[i] > '9')
        {
            printf("Invalid rotation amount!");
            exit(EXIT_FAILURE);
        }
        result += (arg[i] - '0') * factor;
        factor *= 10;
    }
    return result;
}

bool get_is_encrypt(char *arg)
{
    return !(arg[1] == 'd');
}

int rotate(char c, int r, int bottom)
{
    return (c - bottom + r) % 26 + bottom;
}

// rotates input int c by r or returns non-alpha c
int encrypt(char c, int r)
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
    // TODO: Interface asks user for rotation amount, input/output filenames
    // TODO: make it work with negative args
    if (argc < 2)
    {
        printf("Missing arguments");
        exit(EXIT_FAILURE);
    }
    char c;
    int r = 0;
    bool is_encrypt = true;
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            is_encrypt = get_is_encrypt(argv[i]);
        }
        else
        {
            r = str_to_int(argv[i]) % 26;
        }
    }
    r *= is_encrypt ? r : 26 - r; // inverse of rotation amount if decrypting
    while((c = getchar()) != EOF)
    {
        putchar(encrypt(c, r));
    }  
    return EXIT_SUCCESS;
}