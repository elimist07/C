#include <stdio.h>
#include <errno.h>
#include <string.h>
extern int errno;
int character_count(char **);
int line_count(char **);
int word_count(char **);
int frequent_characters(char **);
int isthisspace(unsigned int);
/*isthisspace() checks  for  white-space  characters.   In  the  "C"  and "POSIX" locales, these are: space, form-feed ('\f'), newline ('\n'), carriage return
              ('\r'), horizontal tab ('\t'), and vertical tab ('\v').*/
int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        fprintf(stdout, "No of Characters: %d\n", character_count(argv));
        fprintf(stdout, "No of words: %d\n", word_count(argv));
        fprintf(stdout, "No of Lines: %d\n", line_count(argv));
        fprintf(stdout, "Most frequent character: %c", frequent_characters(argv));
    }
    else
    {
        fprintf(stdout, "Invalid Syntax");
        return -1;
    }
    return 0;
}

int character_count(char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "%s", strerror(errno));

        return -1;
    }
    int characters = 0, byte;

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
        fprintf(stderr, "%s", strerror(errno));

        return -1;
    }
    int lines = 0, byte;
    while ((byte = fgetc(file)) != EOF)
    {
        if (byte == '\n')
            lines++;
    }
    fclose(file);
    return lines;
}

int isthisspace(unsigned int byte)
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
        fprintf(stderr, "%s", strerror(errno));
        return -1;
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

int frequent_characters(char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "%s", strerror(errno));
        return -1;
    }
    int characters[256] = {0}, byte;
    for (int i = 0; i < 255; i++)
        characters[i] = 0;
    while ((byte = fgetc(file)) != EOF)
    {
        // printf("%c\n",byte);
        characters[byte] = characters[byte] + 1;
    }
    fclose(file);

    for (int i = 0; i < 255 - 1; i++)
    {
        for (int j = 0; j < 255 - i; j++)
        {
            if (characters[j] > characters[j + 1])
            {
                int temp = characters[j];
                characters[j] = characters[j + 1];
                characters[j + 1] = temp;
            }
        }
    }
    return (characters[256]);
}