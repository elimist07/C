#include <stdio.h>
#include<string.h>
#include <stdlib.h>

void clear_buffer()
{
    printf("invalid input!");
    while (getchar() != '\n');
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
void search_record(student_record *,int);
int delete_record(student_record *,int);

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
            total = num + total;
            student_record *temp_student = (student_record *)realloc(student, sizeof(student_record) * total); // struct student_record now is a user defined data type
            if (temp_student == NULL)
            { // check if sufficient memory not allocated
                printf("memory allocation error!\n");
                return -1;
            }
            else
                student = temp_student;
            add_record(student, num, total);
            break;
        case 2:
            display_record(student, total);
            break;
        case 3:
            search_record(student,total);
            break;
        case 4:
            total=delete_record(student,total);
            student_record* temp_student= realloc(student, total*sizeof(student_record));
            if(temp_student==NULL)
            printf("error\n");
            else 
            student=temp_student;
            break;
        default:
            printf("invalid!\n");
        }
    }
    return 0;
}
void add_record(student_record *student, int num, int total){
    if(student==NULL){
        printf("no data\n");
    }
for (int i = total - num; i < total; i++)
{
    printf("Student %d\n", i + 1);
            printf("enter your name: ");
            scanf(" %.99s", student[i].name);
            printf("enter your age: ");
            if(scanf(" %d", &student[i].age)!=1)
            clear_buffer();
            printf("enter your class: ");
            if(scanf(" %d", &student[i].class)!=1)
            clear_buffer();
            printf("enter your roll number: ");
            if(scanf(" %d", &student[i].roll_no)!=1)
            clear_buffer();
            printf(" enter your gpa:");
            if(scanf(" %f", &student[i].gpa)!=1)
            clear_buffer();
        }
    }


void display_record(student_record *student, int total) // displys the record
{
    
        if (total== 0)
        {
            printf("no data\n");
            return;
        }
        else
        {
    // student_record new_student=(student_record *)realloc(student,sizeof(student_record)*1);
    printf("s.n|\tName\t|\tage\t|\tclass\t|\trollno\t|\tgpa\t|\n");
    for (int i = 0; i < total; i++)
    {
        printf("%d\t%s\t\t%d\t\t%d\t\t%d\t\t%.2f\t\n", i + 1, student[i].name, student[i].age, student[i].class, student[i].roll_no, student[i].gpa);
    }
}
}

void search_record(student_record *student,int total)
{
    int rollno=0,i=0;
    if(student==NULL || total==0){
        printf("no data\n");
        return;
    }
    printf("Enter roll no of student: ");
    if(scanf("%d",&rollno)!=1){
        clear_buffer();
    }
   do{
    if(student[i].roll_no==rollno){
        printf("s.n|\tName\t|\tage\t|\tclass\t|\trollno\t|\tgpa\t|\n");
        printf("%d\t%s\t\t%d\t\t%d\t\t%d\t\t%.2f\t\n", i + 1, student[i].name, student[i].age, student[i].class, student[i].roll_no, student[i].gpa);
       return;
    }
    i++;
}while(i<total);
if(i==total)
printf("no data\n");
}


int delete_record(student_record *student,int total)
{
    if(total==0){
    printf("no data\n");
    return 0;
}
    int rollno,i=1;
    printf("Enter roll no of student you want to delete: ");
    if(scanf("%d",&rollno)!=1){
        clear_buffer();
    }
    do{
        if(student[i-1].roll_no==rollno){

            for(i;i<total;i++){
                student[i-1].age=student[i].age;
                student[i-1].class=student[i].class;
                student[i-1].roll_no=student[i].roll_no;
                strcpy(student[i-1].name,student[i].name);
                student[i-1].gpa=student[i].gpa;
            }
            return(total-=1);
        }
        i++;
    }
while(i<total);
if(i==total){
printf("student doesn't exist!\n");
return total;
}
}
