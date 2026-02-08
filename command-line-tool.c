#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ascii_check(char **);
int arg_check(int, char **);
int main(int argc, char *argv[])
{
    if (ascii_check(argv))
    {
        switch (arg_check(argc, argv))
        {
        case 1:
            printf("Sum = %.2f\n", atof(argv[2]) + atof(argv[3]));
            break;
        case 2:
            printf("Difference= %.2f\n", atof(argv[2]) - atof(argv[3]));
            break;
        case 3:
            printf("Product= %.2f\n", atof(argv[2]) * atof(argv[3]));
            break;
        case 4:
            if (atof(argv[3]) == 0)
            {
                printf("Can not divide by zero\n");
                break;
            }
            printf("Quotient= %.2f", atof(argv[2]) / atof(argv[3]));
            break;
        default:
            printf("Insufficient arguments\n");
        }
    }
    else
        printf("Invalid arguments\n");
    return 0;
}

int arg_check(int argc, char *argv[])
{

    if (strcmp(argv[1], "add") == 0 && argc == 4)
        return 1;
    if (strcmp(argv[1], "sub") == 0 && argc == 4)
        return 2;
    if (strcmp(argv[1], "mult") == 0 && argc == 4)
        return 3;
    if (strcmp(argv[1], "div") == 0 && argc == 4)
        return 4;

    return 0;
}
int ascii_check(char *argv[])
{
    if (argv[2][0] < 48 || argv[2][0] > 57)
        return 0;
    if (argv[3][0] < 48 || argv[3][0] > 57)
        return 0;
    return 1;
}
