#include<stdio.h>
int addition();
int multiplication();
int transpose();

int two_matrices(int (*p)()){
int row,column;
printf("enter row of matrix:  ");
scanf(" %d",&row);
printf("enter column of matrix:  ");
scanf(" %d",&column);
if((row || column )<1)
{
    printf("invalid row or column\n");
    return 0;
}
else{
int matrix1[row][column],matrix2[row][column];
printf("Enter elements of Matrix 1\n");
for(int i=0;i<column;i++){
    for(int j=0;j<row;j++){
        printf("Element of i=%d,j=%d: ",i,j);
        scanf(" %d",&matrix1[i][j]);
    }
}
printf("\n");
printf("Enter elements of Matrix 1\n");

for(int i=0;i<column;i++){
    for(int j=0;j<row;j++){
         printf("Element of i=%d,j=%d: ",i,j);
        scanf(" %d",&matrix2[i][j]);
       
    }
} 
// for(int i=0;i<column;i++){
//     for(int j=0;j<row;j++){
//         printf("%d\t",matrix1[i][j]);
//     }
//     printf("\n");
// }

p();
}
 }
int main(){
    int choice=0;
printf("Matrix Operation Engine\n");
printf("1.Addition\n2.Multiplication\n3.Transpose\nEnter your option(0 to quit): ");
scanf("%d",&choice);
if(choice==0)
return 0;
switch(choice){
    case 1:two_matrices(addition);break;
    case 2:two_matrices(multiplication);break;
    case 3:transpose();break;
    default:
    printf("invalid option!\n");
}
return 0;
 }

 int addition(){
    return 0;

 }
 int multiplication(){
return 0;
 }
 int transpose(){
return 0;
 }