#include<stdio.h>
#include<stdlib.h>
int n=0;

typedef struct {
    char name[100];
    int age;
    int class;
    int roll_no;
    float gpa;
}student_record;//struc of size 112 bytes

int add_record(student_record *);
void display_record(student_record *);
void search_record(student_record *);
void delete_record(student_record *);



int main(){
    student_record *pstudent;
    int choice;
    while(1){
        printf("1.Add\n2.Display\n3.Search\n4.Delete\nPress\"0\" to exit\nEnter your choice: ");
        if(scanf("%d",&choice)!=1){
            printf("invalid input!");
            while(getchar()!='n');
        }
        if(choice==0){
         free(pstudent);//freed the allocated memory
    pstudent=NULL;//dangling pointer avoided
        break;}
        switch(choice){
            case 1:add_record(pstudent);break;
            case 2:display_record(pstudent);break;
            case 3:search_record(pstudent);break;
            case 4:delete_record(pstudent);break;
            default:
            printf("invalid!");
        }
    }
        return 0;
    }
int add_record(student_record *pstudent){
    printf("Number of students: ");
    scanf("%d",&n);
    pstudent=(student_record*)malloc(n*sizeof(student_record));//struct student_record now is a user defined data type
    if(pstudent==NULL){//check if sufficient memory not allocated
    printf("memory allocation error!\n");
    return -1;
    }
    for(int i=0;i<n;i++){
        printf("Student %d\n",i+1);
        printf("enter your name: ");
        scanf(" %s",pstudent[i].name);
        printf("enter your age: ");
        scanf(" %d",&pstudent[i].age);
        printf("enter your class: ");
        scanf(" %d",&pstudent[i].class);
        printf("enter your roll number: ");
        scanf(" %d",&pstudent[i].roll_no);
        printf(" enter your gpa:");
        scanf(" %f",&pstudent[i].gpa);
    }
}   
    
void display_record(student_record *pstudent)//displys the record
{
    printf("s.n|\tName\t|\tage\t|\tclass\t|\trollno\t|\tgpa\t|\n");
    for(int i=0;i<n;i++){
    printf("%d|\t%s\t|\t%d\t|\t%d\t|\t%d\t|\t%f\t|\n",i+1,
                                       pstudent[i].name,
                                       pstudent[i].age,
                                       pstudent[i].class,
                                       pstudent[i].roll_no,
                                       pstudent[i].gpa);
    }
}

void search_record(student_record *student){

    
}

void delete_record(student_record *student){
    
}
