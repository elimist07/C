#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int id;
    char name[128];
    float gpa;
} uni;

int append_data(char *, uni *, int);
uni *read_data(char *, int *);
int delete_data(char *, uni *, int);

int main()
{

    int choice;
    int total = 0;
    while (1)
    {
        printf("\n1.Add/Append data\n2.Read data\n3.Update data\n4.delete data\n5.exit\nChoose an option: ");
        if (scanf(" %d", &choice) != 1)
        {
            printf("invalid input\n");
            return 0;
        }
        if (choice == 5)
        {
            printf("Have a good day!\n");
            return 0;
        }
        switch (choice)
        {
        case 1:
            uni *student;
            printf("How many data to add?: ");
            scanf(" %d", &total);
            student = malloc(sizeof(uni) * total);
            append_data("student.bin", student, total);
            free(student);
            student = NULL;
            break;
        case 2:
            uni *file_data;
            file_data = read_data("student.bin", &total);
            if (file_data == NULL)
            {
                printf("error reading data\n");
                return 0;
            }

            printf("data read OK\n");
            printf("id\t\tname\t\tgpa\n");
            for (int i = 0; i < total; i++)
            {
                printf("%d\t\t", file_data[i].id);
                printf("%s\t\t", file_data[i].name);
                printf("%.2f\n", file_data[i].gpa);
            }
            break;
        case 3:
            break;
        case 4:
            uni *delete;
            int id;
            printf("Enter the id you want to delete: ");
            scanf(" %d", &id);
            if(delete_data("student.bin", delete, id)==1)
            printf("data deletion success!\n");
            else
            printf("error deleting data\n");
            return 0;

        default:
            printf("Choose within given option\n");
            return 0;
        }
    }
}

int append_data(char *file_name, uni *data, int total)
{
    FILE *file;
    file = fopen(file_name, "ab");
    if (file == NULL)
    {
        printf("error opening file\n");
        return false;
    }

    for (int i = 0; i < total; i++)
    {
        printf("Enter your id: ");
        scanf(" %d", &data[i].id);
        if (fwrite(&data[i].id, sizeof(int), 1, file) != 1)
            return false;
        printf("Enter your name: ");
        scanf(" %s", data[i].name);
        if (fwrite(data[i].name, sizeof(char), 128, file) != 128)
            return false;
        printf("Enter your gpa: ");
        scanf(" %f", &data[i].gpa);
        if (fwrite(&data[i].gpa, sizeof(float), 1, file) != 1)
            return false;
        printf("\n");
    }
    fclose(file);
    return 0;
}

uni *read_data(char *file_name, int *total)
{
    FILE *file;
    file = fopen(file_name, "rb");
    if (file == NULL)
    {
        printf("error opening file\n");
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    *total = (ftell(file)) / sizeof(uni);
    fseek(file, 0, SEEK_SET);
    uni *data = malloc(sizeof(uni) * (*total));
    if (data == NULL)
    {
        printf("error\n");
        return 0;
    }
    if (fread(data, sizeof(uni), *total, file) != *total)
    {
        free(data);
        return NULL;
    }
    fclose(file);
    return data;
}

int delete_data(char *file_name, uni *delete, int id)
{
    FILE *file;
    file = fopen(file_name, "ab");
    if (file == NULL)
    {
        printf("error opening file\n");
        return false;
    }
    fseek(file, 0, SEEK_END);
    int total = ftell(file) / sizeof(uni);
    printf("total=%d\n",total);
    delete = malloc(sizeof(uni) * total);
    fseek(file,0,SEEK_SET);
    printf("ftell=%ld\n",ftell(file));
   
    for (int i = 0; i < total; i++)
    {
         if(fread(delete,sizeof(uni),total,file)==total)
        printf("\n%d\n",delete[i].id);
        if (delete[i].id == id)
        {
            //printf("done");
                delete[i].id = -1;
                free(delete);
                fclose(file);
                return 1;
            
        }
    }

    free(delete);
    fclose(file);
    return 0;
}