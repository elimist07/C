#include <stdio.h>
#include <stdlib.h>

int n= 0;
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

void add_record(student_record *);
void display_record(student_record *);
void search_record(student_record *);
void delete_record(student_record *);

int main()
{
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
            if (scanf("%d", &n) != 1)
            {
                clear_buffer();
            }
            else if (n <= 0)
            {
                printf("Must be greater than 0!\n");
                continue;
            }
            student_record *temp_student = (student_record *)realloc(student, sizeof(student_record) * n); // struct student_record now is a user defined data type
            if (temp_student == NULL)
            { // check if sufficient memory not allocated
                printf("memory allocation error!\n");
                return -1;
            }
            else
            student=temp_student;
            add_record(student);
            break;
        case 2:
            display_record(student);
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
void add_record(student_record *student)
{
    for (int i = 0; i < n; i++)
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

void display_record(student_record *student) // displys the record
{
    // student_record new_student=(student_record *)realloc(student,sizeof(student_record)*1);
    printf("s.n|\tName\t|\tage\t|\tclass\t|\trollno\t|\tgpa\t|\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t%d\t\t%d\t\t%d\t\t%f\t\n", i + 1, student[i].name, student[i].age, student[i].class, student[i].roll_no, student[i].gpa);
    }
}

void search_record(student_record *student)
{
}

void delete_record(student_record *student)
{
}
