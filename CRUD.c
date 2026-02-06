#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[128];
    float gpa;
} record;

int append_data(char *, record *);
record *read_data(char *, int *);
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
            while (getchar() != '\n')
                ;
        }
        if (choice == 5)
        {
            printf("Have a good day!\n");
            return 0;
        }
        switch (choice)
        {
        case 1:
            record *student;
            student = malloc(sizeof(record));
            if (append_data("student.bin", student) == 1)
            {
                printf("Data written successfully\n");
            }
            else
            {
                printf("Error writing data\n");
            }
            free(student);
            student = NULL;
            break;
        case 2:
            record *file_data;
            file_data = read_data("student.bin", &total);
            if (file_data == NULL)
            {
                printf("error reading data\n");
                free(file_data);
                return 0;
            }

            printf("data read OK\n");
            printf("id\t\tname\t\tgpa\n");
            for (int i = 0; i < total; i++)
                printf("%d\t\t%s\t\t%.2f\n", file_data[i].id, file_data[i].name, file_data[i].gpa);
            free(file_data);
            break;
        case 3:
            int id;
            printf("Enter the id you want to update: ");
            scanf(" %d", &id);
            if (update_data("student.bin", id))
                printf("Data updated successfully\n");
            else
                printf("Error updating data!\n");

            break;
        case 4:
            int idno;
            printf("Enter the id you want to delete: ");
            scanf(" %d", &idno);
            if (delete_data("student.bin", idno) == 1)
                printf("Data deletion success!\n");
            else
                printf("Error deleting data\n");
            break;

        default:
            printf("Choose within given option\n");
        }
    }
}

int append_data(char *file_name, record *data)
{
    FILE *file;
    file = fopen(file_name, "ab");
    if (file == NULL)
    {
        printf("error opening file\n");
        return 0;
    }
    printf("Enter your id: "); // id input
    if (scanf(" %d", &data[0].id) != 1)
    {
        printf("enter valid input!\n");
        while (getchar() != '\n')
            ;
        fclose(file);
        return 0;
    }
    else if (data[0].id <= 0) // cant be less than  or 0;
    {
        printf("Enter valid id no\n");
        fclose(file);
        return 0;
    }
    printf("Enter your name: "); // name input
    scanf(" %127s", data[0].name);
    printf("Enter your gpa: "); // gpa input
    if (scanf(" %f", &data[0].gpa) != 1)
    {
        printf("enter valid input!\n");
        while (getchar() != '\n')
            ;
        fclose(file);
        return 0;
    }
    else if (data[0].gpa < 0 || data[0].gpa > 4) // cant be less than  or 0 and cant be greater than 4;
    {
        printf("Enter gpa between 0 to 4 \n");
        fclose(file);
        return 0;
    }
    if (fwrite(&data[0], sizeof(record), 1, file) != 1)
    {
        fclose(file);
        return 0;
    }
    printf("\n");

    fclose(file);
    return 1;
}

record *read_data(char *file_name, int *total)
{
    FILE *file;
    file = fopen(file_name, "rb");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 0;
    }
    fseek(file, 0, SEEK_END);
    *total = (ftell(file)) / sizeof(record);
    fseek(file, 0, SEEK_SET);
    record *data = malloc(sizeof(record) * (*total));
    if (data == NULL)
    {
        printf("error\n");
        free(data);
        fclose(file);
        return 0;
    }
    for (int i = 0; i < *total; i++)
    {
        if (fread(&data[i], sizeof(record), 1, file) != 1)
        {
            printf("error reading data");
            free(data);
            fclose(file);
            return 0;
        }
    }
    fclose(file);
    return data;
}

int update_data(char *file_name, int id)
{
    FILE *file;
    file = fopen(file_name, "rb");
    if (file == NULL)
    {
        printf("error opening file");
        return 0;
    }
    FILE *temp_file;
    char *temp_filename = "temp_filename.bin";
    temp_file = fopen(temp_filename, "wb");
    if (temp_file == NULL)
    {
        printf("error|\n");
        return 0;
    }
    record update;
    int not_found = 1;
    while (fread(&update, sizeof(record), 1, file) == 1)
    {
        if (update.id == id)
        {
            printf("Enter new id: ");
            if (scanf(" %d", &update.id) != 1 || update.id <= 0)
            {
                printf("enter valid new id");
                fclose(file);
                fclose(temp_file);
                remove(temp_filename);
                return 0;
            }
            printf("Enter new name: ");
            scanf(" %127s", update.name);
            printf("Enter new gpa: ");
            if (scanf(" %f", &update.gpa) != 1 || update.gpa < 0 || update.gpa > 4)
            {
                printf("enter valid gpa\n");
                fclose(file);
                fclose(temp_file);
                remove(temp_filename);
                return 0;
            }

            not_found = 0;
        }
        fwrite(&update, sizeof(record), 1, temp_file);
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
        printf("Error renaming temporary file\n");
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
    record delete;
    int found = 0;
    while (fread(&delete, sizeof(record), 1, file) == 1)
    {
        if (delete.id != id)
            fwrite(&delete, sizeof(record), 1, temp_file);
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