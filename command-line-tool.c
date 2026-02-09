#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
extern int errno;
void help();
int number_ascii_check(char **);
int arg_check(int, char **);
int re_name(char **);
int main(int argc, char *argv[])
{
    if (strcmp(argv[1], "help") == 0)
        help();
    else if (strcmp(argv[1], "add") == 0 && argc == 4 && number_ascii_check(argv))
        printf("Sum = %.2f\n", atof(argv[2]) + atof(argv[3]));

    else if (strcmp(argv[1], "sub") == 0 && argc == 4 && number_ascii_check(argv))
        printf("Difference= %.2f\n", atof(argv[2]) - atof(argv[3]));

    else if (strcmp(argv[1], "mult") == 0 && argc == 4 && number_ascii_check(argv))
        printf("Product= %.2f\n", atof(argv[2]) * atof(argv[3]));

    else if (strcmp(argv[1], "div") == 0 && argc == 4 && number_ascii_check(argv))
    {
        if (atof(argv[3]) == 0)
        {
            printf("Cannot divide by zero\n");
        }
        else
            printf("Quotient= %.2f", atof(argv[2]) / atof(argv[3]));
    }
    else if (strcmp(argv[1], "rename") == 0 && argc == 4)
    {
        if (re_name(argv))
        printf("Renamed Successfully\n");
            ;
    }
    fprintf(stderr, "\nInvalid arguments\nType 'help' for commands");

    return 0;
}

void help()
{
    printf("Availabel Commands\n");
    printf("add (eg add 2 3)\n");
    printf("sub (eg 4-1)\n");
    printf("mult (eg 2 mult 2)\n");
    printf("div (eg div 4 2)\n");
}
int number_ascii_check(char *argv[])
{
    if (argv[2][0] < 48 || argv[2][0] > 57)
        return 0;
    if (argv[3][0] < 48 || argv[3][0] > 57)
        return 0;
    return 1;
}
int re_name(char *argv[])
{
    FILE *file;
    file = fopen(argv[2], "r");
    if (file == NULL)
    {
        fprintf(stderr, "error:%s", strerror(errno));
        return 0;
    }
    int i = 0;
    while (argv[3][i] != '\n')
    {
        argv[2][i] = argv[3][i];
        i++;
    }
    return 1;
}