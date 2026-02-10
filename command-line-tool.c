#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
extern int errno;
void help();
int number_ascii_check(char **);
int re_name(char **);
int copy_file(char **);
int move_file(char **);
int delete(char **);
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
    }
    else if (strcmp(argv[1], "copy") == 0 && argc == 4)
    {
        if (copy_file(argv))
            printf("File copied successfully\n");
        else
            printf("Error copying file\n");
    }
    else if (strcmp(argv[1], "move") == 0 && argc == 4)
    {
        if (move_file(argv))
            printf("File moved successfully\n");
        else
        printf("Error moving file\n");
    }
    else if(strcmp(argv[1],"delete")==0 && argc ==3)
    {
        if(delete(argv))
        printf("File deleted successfully\n");
        else
        printf("Error deleting file\n");
    }
    else
        fprintf(stderr, "Invalid arguments\nType 'help' for commands");

    return 0;
}

void help()
{
    printf("*****Availabel Commands*****\n");
    printf("add (eg add 2 3)\n");
    printf("sub (eg 4-1)\n");
    printf("mult (eg 2 mult 2)\n");
    printf("div (eg div 4 2)\n");
    printf("rename (eg rename oldname newname)\n");
    printf("copy (eg copy source destination)\n");
    printf("delete (eg delete filename)");
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
    if (strcmp(argv[2], argv[3]) == 0)
    {
        printf("%s and %s are the same file name", argv[2], argv[3]);
        fclose(file);
        return 0;
    }
    else if (rename(argv[2], argv[3]) != 0)
    {
        fprintf(stderr, "%s", strerror(errno));
        fclose(file);
        return 0;
    }
    fclose(file);
    return 1;
}

int copy_file(char *argv[])
{
    FILE *file;
    file = fopen(argv[2], "rb");
    if (file == NULL)
    {
        fprintf(stderr, "%s", strerror(errno));
        fclose(file);
        return 0;
    }
    FILE *filecopy;
    filecopy = fopen(argv[3], "ab");
    if (filecopy == NULL)
    {
        fprintf(stderr, "%s", strerror(errno));
        fclose(file);
        remove(argv[3]);
        return 0;
    }
    char original_byte, copy_byte;
    while (fread(&original_byte, 1, 1, file))
    {
        copy_byte = original_byte;
        if (fwrite(&copy_byte, 1, 1, filecopy) != 1)
        {
            fprintf(stderr, "%s", strerror(errno));
            fclose(file);
            fclose(filecopy);
            remove(argv[3]);
            return 0;
        }
    }
    fclose(file);
    fclose(filecopy);
    return 1;
}

int move_file(char *argv[])

{

    FILE *file;
    file = fopen(argv[2], "rb");
    if (file == NULL)
    {
        fprintf(stderr, "%s", strerror(errno));
        fclose(file);
        return 0;
    }
    FILE *filecopy;
    filecopy = fopen(argv[3], "ab");
    if (filecopy == NULL)
    {
        fprintf(stderr, "%s", strerror(errno));
        fclose(file);
        remove(argv[3]);
        return 0;
    }
    char original_byte, copy_byte;
    while (fread(&original_byte, 1, 1, file))
    {
        copy_byte = original_byte;
        if (fwrite(&copy_byte, 1, 1, filecopy) != 1)
        {
            fprintf(stderr, "%s", strerror(errno));
            fclose(file);
            fclose(filecopy);
            remove(argv[3]);
            return 0;
        }
    }
    fclose(file);
    if(remove(argv[2])!=0){
        fclose(filecopy);
        remove(argv[3]);
        return 0;
    }
    fclose(filecopy);
    return 1;
}


int delete(char *argv[]){
FILE *file=fopen(argv[2],"rb");
if(file==NULL){
    fprintf(stderr,"%s\n",strerror(errno));
    return 0;
}
if(remove(argv[2])!=0){
fclose(file);
    return 0;}
return 1;
}

