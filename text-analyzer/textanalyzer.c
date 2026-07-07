#include "textanalyzer.h"
size_t character_count(char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "%s", strerror(errno));

        return -1;
    }
    size_t characters = 0;int byte;

    while ((byte = fgetc(file)) != EOF)
        characters++;
    fclose(file);
    return characters;
}

size_t line_count(char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "%s", strerror(errno));

        return -1;
    }
    size_t lines = 0;int byte;
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
size_t word_count(char *argv[])
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
    size_t characters[256] = {0};int byte;

    while ((byte = fgetc(file)) != EOF)
    {
        if(!isthisspace(byte))
        characters[byte] = characters[byte] + 1;
    }
    fclose(file);
    size_t max_frequency = 0;int max_character = 0;
    for (int i = 0; i < 256; i++)
    {
        if (characters[i] > max_frequency)
        {
            max_character = i;
            max_frequency = characters[i];
        }
    }
    return (max_character);
}