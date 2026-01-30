#include <stdio.h>
#include <stdlib.h>
int addition(int **, int **, int, int, int, int);
int multiplication(int **, int **, int, int, int, int);
int transpose(int **, int, int);

int two_matrices(int (*p)(int **,int **, int, int, int, int), int choice)
{
    int row1, row2, column1, column2;
    printf("No. of row and column of matrix 1?:  ");
    if (scanf(" %d %d", &row1, &column1) != 2)
    {
        printf("invalid input\n");
        while (getchar() != '\n')
            ;
    }
    printf("No. of row and column of matrix 2?:  ");
    if (scanf(" %d %d", &row2, &column2) != 2)
    {
        printf("invalid input\n");
        while (getchar() != '\n')
            ;
    }
    if ((choice == 1) && (row1 != row2 || column1 != column2))
    {
        printf("invalid dimension for addition!\n");
        two_matrices(addition, 1);
    }
    if (choice == 2 && column1 != row2)
    {
        printf("invalid dimension for Multiplication!\n");
        two_matrices(multiplication, 2);
    }
    int **arr1 = (int **)malloc(row1 * sizeof(int *)); // array of two pointers,row created
    for (int i = 0; i < row1; i++)
        arr1[i] = (int *)malloc(column1 * sizeof(int)); // each row i memory for column1 integers,column created

    int **arr2 = (int **)malloc(row2 * sizeof(int *));
    for (int i = 0; i < row2; i++)
        arr2[i] = (int *)malloc(column2 * sizeof(int));
    printf("MATRIX 1\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column2; j++)
        {
            printf("Enter element of Row%d Column %d: ", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("MATRIX 2\n");
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < column2; j++)
        {
            printf("Enter element of Row%d Column %d: ", i, j);
            scanf("%d", &arr2[i][j]);
        }
    }
    p(arr1, arr2, row1, column1, row2, column2);
    for(int i=0;i<row1;i++)
    free(arr1[i]);
    free(arr1);
    for(int i=0;i<row2;i++)
    free(arr2[i]);
    free(arr2);
    return 0;
}

int one_matrix(int (*p)(int **, int, int))
{
    int row, column;
    printf("No. of row and column of matrix ?:  ");
    if (scanf(" %d %d", &row, &column) != 2)
    {
        printf("invalid input\n");
        while (getchar() != '\n')
            ;
    }
    int **arr = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
        arr[i] = (int *)malloc(column * sizeof(int));
     
    printf("MATRIX\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("Enter element of Row%d Column %d: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }    

    p(arr, row, column);
    for(int i=0;i<row;i++)
    free(arr[i]);
    free(arr);
}
int main()
{
    int choice;
    char cont;
    while (1)
    {
        printf("\n\nMatrix Operation Engine\n");
        printf("1.Addition\n2.Multiplication\n3.Transpose\nEnter your option(0 to quit): ");
        if(scanf(" %d", &choice)!=1){
            printf("No such option!\n");
            while(getchar()!='\n');
        }
        if (choice == 0)
            break;
        switch (choice)
        {
        case 1:
            two_matrices(addition, choice);
            break;
        case 2:
            two_matrices(multiplication, choice);
            break;
        case 3:
            one_matrix(transpose);
            break;
        default:
            printf("Choose within given options!\n\n");
        }
        printf("Continue again?(y/n): ");
        scanf(" %c", &cont);
        if ((cont == 'n') || (cont == 'N'))
            break;
        else
            continue;
    }
    return 0;
}

int addition(int **arr1, int **arr2, int row1, int column1, int row2, int column2)
{
    printf("Result\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column2; j++)
        {
            printf("%d \t", arr1[i][j] + arr2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
int multiplication(int **arr1, int **arr2, int row1, int column1, int row2, int column2)
{
    return 0;
}
int transpose(int **arr, int row, int column)
{
int** swap_arr=(int**)malloc(column*sizeof(int *));//row becomes column
for(int i=0;i<column;i++)
swap_arr[i]=(int*)malloc(row*sizeof(int));//column beocmes row

for(int i=0;i<column;i++){
    for(int j=0;j<row;j++){
        swap_arr[i][j]=arr[j][i];
    }
}
for(int i=0;i<column;i++){
    for(int j=0;j<row;j++){
        printf("%d \t",swap_arr[i][j]);
    }
    printf("\n");
}

for(int i=0;i<column;i++)
free(swap_arr[i]);
free(swap_arr);
    return 0;
}