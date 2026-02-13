#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <ctype.h>
extern int errno;
void help();
int number_ascii_check(char **);
int re_name(char **);
int copy_file(char **);
int move_file(char **);
int delete(char **);
void stat_file(char **);
void show_time(unsigned long);
void count(char **);
void reverse(char **);
void top_file(char **);
void bottom_file(char **);
void grep(char **);

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
    else if (strcmp(argv[1], "delete") == 0 && argc == 3)
    {
        if (delete(argv))
            printf("File deleted successfully\n");
        else
            printf("Error deleting file\n");
    }
    else if (strcmp(argv[1], "stat") == 0 && argc == 3)
    {
        stat_file(argv);
    }
    else if (strcmp(argv[1], "count") == 0 && argc == 3)
    {
        count(argv);
    }
    else if (strcmp(argv[1], "reverse") == 0 && argc == 3)
    {
        reverse(argv);
    }
    else if (strcmp(argv[1], "head") == 0 && argc == 4)
    {
        top_file(argv);
    }
    else if (strcmp(argv[1], "tail") == 0 && argc == 4)
        bottom_file(argv);
    else if (strcmp(argv[1], "grep") == 0 && argc == 4)
        grep(argv);
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
    printf("delete (eg delete filename)\n");
    printf("stat (eg stat filename)\n");
    printf("count (eg count filename)\n");
    printf("reverse (eg reverse)\n");
    printf("head (head filename N)\n");
    printf("tail (tail filename N)\n");
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
    if (remove(argv[2]) != 0)
    {
        fclose(filecopy);
        remove(argv[3]);
        return 0;
    }
    fclose(filecopy);
    return 1;
}

int delete(char *argv[])
{
    FILE *file = fopen(argv[2], "rb");
    if (file == NULL)
    {
        fprintf(stderr, "%s\n", strerror(errno));
        return 0;
    }
    if (remove(argv[2]) != 0)
    {
        fclose(file);
        return 0;
    }
    fclose(file);
    return 1;
}

void stat_file(char *argv[])
{
    const char *filename = argv[2];
    struct stat st;
    if (stat(filename, &st) != -1)
    {
        printf("Filename:%s\n", argv[2]);
        printf("Size: %ldbytes\n", st.st_blocks);
        show_time(st.st_mtime);
        printf("Permissions:%o", st.st_mode);
    }
    else
    {
        fprintf(stderr, "%s", strerror(errno));
    }
}
bool isleap(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

void show_time(unsigned long S)

{
    const unsigned long sec_per_day = 86400, days_per_year = 365, epoch_year = 1970;

    unsigned long days = S / sec_per_day;
    unsigned long sec_in_day = S % sec_per_day;

    unsigned long hours = sec_in_day / 3600;
    unsigned long minutes = (sec_in_day % 3600) / 60;
    unsigned long sec = sec_in_day % 60;

    int year = epoch_year;
    while (days >= (days_per_year + isleap(year)))
    {
        days = days - (days_per_year + isleap(year));
        year++;
    }

    int month_Days[12] = {31, 28 + isleap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int m = 0;
    while (days >= month_Days[m])
    {
        days = days - month_Days[m];
        m++;
    }

    int month = m + 1;
    int day = days + 1;

    printf("Last Modified: %02d/%02d/%04d %02lu:%02lu:%02lu\n", day, month, year, hours, minutes, sec);
}

void count(char *argv[])

{
    FILE *file = fopen(argv[2], "r");
    if (file == NULL)
    {
        fprintf(stderr, "%s", strerror(errno));
        return;
    }
    int byte;
    int whitespace = true;
    size_t lines = 0, words = 0, characters = 0;
    while ((byte = fgetc(file)) != EOF)
    {
        if (byte == 10)
            lines++;
        if (whitespace && !isspace(byte))
        {
            words++;
            whitespace = false;
        }
        else if (!whitespace && isspace(byte))
        {
            whitespace = true;
        }
        characters++;
    }
    fclose(file);
    printf("%ld %ld %ld %s", lines, words, characters, argv[2]);
}

void reverse(char *argv[])
{
    FILE *file = fopen(argv[2], "r");
    if (file == NULL)
    {
        fprintf(stderr, "%s", strerror(errno));
        return;
    }
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    for (long int i = size - 1; i >= 0; i--)
    {
        fseek(file, i, SEEK_SET);
        fprintf(stdout, "%c", fgetc(file));
    }
    fclose(file);
}

void top_file(char *argv[])
{
    FILE *file = fopen(argv[2], "r");
    if (file == NULL)
    {
        fprintf(stderr, "%s", strerror(errno));
        return;
    }
    int byte, lines = 0;
    while ((byte = fgetc(file)) != EOF)
    {
        if (byte == 10)
            lines++;
        if (lines == atoi(argv[3]))
            break;
        fprintf(stdout, "%c", byte);
    }
    fclose(file);
}

void bottom_file(char *argv[])
{
    FILE *file = fopen(argv[2], "r");
    if (file == NULL)
    {
        fprintf(stderr, "%s", strerror(errno));
        return;
    }
    int total_lines = 0, byte;
    while ((byte = fgetc(file)) != EOF)
    {
        if (byte == 10)
            total_lines++;
    }
    int check_line = 0;
    fseek(file, 0, SEEK_SET);
    while ((byte = fgetc(file)) != EOF)
    {
        if (byte == 10)
            check_line++;
        if (check_line >= (total_lines - atoi(argv[3])) && check_line <= total_lines)
            fprintf(stdout, "%c", byte);
    }
}

void grep(char *argv[])
{
    FILE *file = fopen(argv[3], "r");
    if (file == NULL)
    {
        fprintf(stderr, "%s", strerror(errno));
        return;
    }
    int length = strlen(argv[2]), i = 0, byte;
    int match = false, whitespace = true;
    char buffer[100], word[length];
    while ((byte = fgetc(file)) != EOF)
    {
        buffer[i] = byte;
        if (buffer[i] == word[i])
            match == true;
        if (whitespace && !isspace(byte))
        {
            if (match)
            {
                for (int j = 0; j <= 100; j++)
                    fprintf(stdout, "%c", buffer[j]);
                i = 0;
                match = false;
            }
            whitespace = false;
        }
        else if (!whitespace && isspace(byte))
        {
            whitespace = true;
        }
        i++;
    }
}