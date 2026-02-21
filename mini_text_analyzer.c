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

    while ((byte = fgetc(file)) != EOF)
    {
        if(!isthisspace(byte))
        characters[byte] = characters[byte] + 1;
    }
    fclose(file);
    int max_frequency = 0, max_character = 0;
    for (int i = 0; i < 256; i++)
    {
        if (characters[i] > max_frequency)
        {
            max_character = i;
            max_frequency = characters[i];
        }
    }
    fprintf(stdout,"Repeated %d time\n",max_frequency);
    return (max_character);
}