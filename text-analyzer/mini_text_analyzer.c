#include"textanalyzer.h"
int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        fprintf(stdout, "No of Characters: %ld\n", character_count(argv));
        fprintf(stdout, "No of words: %ld\n", word_count(argv));
        fprintf(stdout, "No of Lines: %ld\n", line_count(argv));
        fprintf(stdout, "Most frequent character: %c", frequent_characters(argv));
    }
    else
    {
        fprintf(stdout, "Invalid Syntax");
        return -1;
    }
    return 0;
}
