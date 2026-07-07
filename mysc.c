#include<string.h>
#include<stdio.h>
int character_count(char **);
int line_count(char **);
int word_count(char **);
int isthisspace(int);

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        printf("No of Characters: %d\n", character_count(argv));
        printf("No of words: %d\n", word_count(argv));
        printf("No of Lines: %d\n", line_count(argv));
            }
    else
    {
        printf("Invalid Syntax");
        return  1;
    }
    return 0;
}


int character_count(char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Cannot Open File\n");
        return  -1;
    }
    int characters = 0,byte;
    while ((byte = fgetc(file)) != EOF)
        characters++;
    fclose(file);
    return characters;
}

int line_count(char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Cannot Open File");
       return  -1;
    }
    int lines = 0, byte,last_byte=0;
    while ((byte = fgetc(file)) != EOF)
    {
        if (byte == '\n')
            lines++;
            last_byte= byte;
    }
 if (last_byte != '\n' && last_byte != 0)

        lines++;

    fclose(file);
    return lines;
}

int isthisspace(int byte)
{
    if (byte == ' ' || byte == '\n' || byte == '\f' || byte == '\r' || byte == '\t' || byte == '\v')
        return 1;
    return 0;
}
int word_count(char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Cannot open file\n");
        return  -1;
    }
    int words = 0, byte, whitespace = 1;
    while ((byte = fgetc(file)) != EOF)
    {
        if (whitespace && !isthisspace(byte))
        {
            whitespace = 0;
            words++;
        }
        else if (!whitespace && isthisspace(byte))
        {
            whitespace = 1;
        }
    }
    fclose(file);
    return words;
}