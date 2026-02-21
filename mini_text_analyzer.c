#include <stdio.h>
#include <errno.h>
#include <string.h>
extern int errno;
int character_count(char **);
int line_count(char **);
int word_count(char **);
int frequent_characters();
int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        fprintf(stdout, "No of Characters: %d\n", character_count(argv));
        fprintf(stdout, "No of Lines: %d\n", line_count(argv));
    }
    else{
        fprintf(stdout, "Invalid Syntax");
        return -1;
    }
    return 0;
}

int character_count(char *argv[])
{
    FILE *file = fopen(argv[1], "rb");
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
    FILE *file = fopen(argv[1], "rb");
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

int word_count(char *argv[]){
FILE *file=fopen(argv[1],"rb");
if(file==NULL){
    fprintf(stderr,"%s",strerror(errno));
    return -1;
}
int words=0,byte;
while((byte=fgetc(file)!=EOF)){
   words++; 
}
fclose(file);
return words;
}