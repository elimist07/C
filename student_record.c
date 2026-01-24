#include <stdio.h>
#include <stdlib.h>

void clear_buffer()
{
    printf("invalid input!");
    while (getchar() != '\n')
        ;
}
typedef struct
{
    char name[100];
    int age;
    int class;
    int roll_no;
    float gpa;
} student_record; // struc of size 112 bytes

void add_record(student_record *, int, int);
void display_record(student_record *, int);
void search_record(student_record *);
void delete_record(student_record *);

int main()
{
    int total = 0, num = 0;
    student_record *student = NULL;
    int choice;
    while (1)
    {
        printf("1.Add\n2.Display\n3.Search\n4.Delete\nPress\"0\" to exit\nEnter your choice: ");
        if (scanf("%d", &choice) != 1)
            clear_buffer();
        if (choice == 0)
        {
            free(student);  // freed the allocated memory
            student = NULL; // dangling pointer avoided
            break;
        }
        switch (choice)
        {
        case 1:
            printf("Number of students: ");
            if (scanf("%d", &num) != 1)
            {
                clear_buffer();
            }
            else if (num <= 0)
            {
                printf("Must be greater than 0!\n");
                continue;
            }
            student_record *temp_student = (student_record *)realloc(student, sizeof(student_record) * total); // struct student_record now is a user defined data type
            if (temp_student == NULL)
            { // check if sufficient memory not allocated
                printf("memory allocation error!\n");
                return -1;
            }
            else
                student = temp_student;
            total = num + total;
            add_record(student, num, total);
            break;
        case 2:
            display_record(student, total);
            break;
        case 3:
            search_record(student);
            break;
        case 4:
            delete_record(student);
            break;
        default:
            printf("invalid!\n");
        }
    }
    return 0;
}
void add_record(student_record *student, int num, int total){
for (int i = total - num; i < total; i++)
{
    printf("Student %d\n", i + 1);
            printf("enter your name: ");
            scanf(" %s", student[i].name);
            printf("enter your age: ");
            scanf(" %d", &student[i].age);
            printf("enter your class: ");
            scanf(" %d", &student[i].class);
            printf("enter your roll number: ");
            scanf(" %d", &student[i].roll_no);
            printf(" enter your gpa:");
            scanf(" %f", &student[i].gpa);
        }
    }


void display_record(student_record *student, int total) // displys the record
{
    
        if (total== 0)
        {
            printf("no data\n");
        }
        else
        {
    // student_record new_student=(student_record *)realloc(student,sizeof(student_record)*1);
    printf("s.n|\tName\t|\tage\t|\tclass\t|\trollno\t|\tgpa\t|\n");
    for (int i = 0; i < total; i++)
    {
        printf("%d\t%s\t\t%d\t\t%d\t\t%d\t\t%f\t\n", i + 1, student[i].name, student[i].age, student[i].class, student[i].roll_no, student[i].gpa);
    }
}
}

void search_record(student_record *student)
{
}

void delete_record(student_record *student)
{
}
