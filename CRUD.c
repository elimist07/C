#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[128];
    float gpa;
} uni;

int append_data(char *, uni *, int);
uni *read_data(char *, int *);
int update_data(char *, int);
int delete_data(char *, int);

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
            if (scanf(" %d", &total) != 1)
            {
                printf("Enter valid input!\n");
                while (getchar() != '\n')
                    ;
            }
            if(total<=0){
                printf("Enter valid input\n");
                 while (getchar() != '\n')
                    ;
            }
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
            int id;
            printf("Enter the id you want to update: ");
            scanf(" %d", &id);
            if (update_data("student.bin", id))
                printf("Data updated successfully");
            else
                printf("Error updating data!");

            break;
        case 4:
            int idno;
            printf("Enter the id you want to delete: ");
            scanf(" %d", &idno);
            if (delete_data("student.bin", idno) == 1)
                printf("data deletion success!\n");
            else
                printf("error deleting data\n");
            break;

        default:
            printf("Choose within given option\n");
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
        return 0;
    }

    for (int i = 0; i < total; i++)
    {
        printf("Enter your id: ");//id input
        if (scanf(" %d", &data[i].id) != 1)
        {
            printf("enter valid input!\n");
            while (getchar() != '\n')
                ;
                return 0;
        }
        else if (data[i].id <= 0)//cant be less than  or 0;
        {
            printf("Enter valid id no\n");
            return 0;
        }
        if (fwrite(&data[i].id, sizeof(int), 1, file) != 1)
            return 0;
        printf("Enter your name: ");//name input
        scanf(" %127s", data[i].name);
        if (fwrite(data[i].name, sizeof(char), 128, file) != 128)
            return 0;
        printf("Enter your gpa: ");//gpa input
        if(scanf(" %f", &data[i].gpa)!=1)
        {
            printf("enter valid input!\n");
            while (getchar() != '\n')
                ;
                return 0;
        }
        else if (data[i].gpa <= 0 || data[i].gpa>4)//cant be less than  or 0 and cant be greater than 4;
        {
            printf("Enter valid id no\n");
            return 0;
        }
        if (fwrite(&data[i].gpa, sizeof(float), 1, file) != 1)
            return 0;
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
        free(data);
        fclose(file);
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

int update_data(char *file_name, int id)
{
    FILE *file;
    file = fopen(file_name, "rb");
    if (fopen == NULL)
    {
        printf("error opening file");
        return 0;
    }
    FILE *temp_file;
    char *temp_filename = "temp_filename";
    temp_file = fopen(temp_filename, "wb");
    if (temp_file == NULL)
    {
        printf("error|\n");
        return 0;
    }
    uni update;
    int not_found = 1;
    while (fread(&update, sizeof(uni), 1, file) == 1)
    {
        if (update.id == id)
        {
            printf("Enter new id: ");
            scanf(" %d", &update.id);
            fwrite(&update.id, sizeof(int), 1, temp_file);
            printf("Enter new name: ");
            scanf(" %s", update.name);
            fwrite(&update.name, sizeof(update.name), 1, temp_file);
            printf("Enter new gpa: ");
            scanf(" %f", &update.gpa);
            fwrite(&update.gpa, sizeof(float), 1, temp_file);
            not_found = 0;
        }
        fwrite(&update, sizeof(uni), 1, temp_file);
    }
    fclose(file);
    fclose(temp_file);
    if (remove(file_name) != 0)
    {
        printf("error deleting orginal record\n");
        remove(temp_filename);
        return 0;
    }
    if (rename(temp_filename, file_name) != 0)
    {
        printf("error renaming temporary file\n");
        return 0;
    }
    if (not_found)
    {
        printf("Id %d doesnt exit\n", id);
        return 0;
    }
    return 1;
}

int delete_data(char *file_name, int id)
{
    FILE *file;
    FILE *temp_file;
    file = fopen(file_name, "rb");
    if (file == NULL)
    {
        printf("error opening file\n");
        return 0;
    }
    char *temp_filename = "temp.bin";
    temp_file = fopen(temp_filename, "wb");
    if (temp_file == NULL)
    {
        printf("error\n");
        return 0;
    }
    uni delete;
    int found = 0;
    while (fread(&delete, sizeof(uni), 1, file) == 1)
    {
        if (delete.id != id)
            fwrite(&delete, sizeof(uni), 1, temp_file);
        else
            found = 1;
    }
    fclose(file);
    fclose(temp_file);
    if (remove(file_name) != 0)
    {
        printf("error deleting  original record!\n");
        remove(temp_filename);
        return 0;
    }
    if (rename(temp_filename, file_name) != 0)
    {
        printf("error renaming temporary file\n");
        return 0;
    }
    if (!found)
    {
        printf("record with id %d not found!\n", id);
        return 0;
    }
    return 1;
}