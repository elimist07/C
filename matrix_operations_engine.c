#include <stdio.h>
#include <stdlib.h>
int addition(int **, int **, int, int, int, int);
int multiplication(int **, int **, int, int, int, int);
int transpose(int **, int, int);

int two_matrices(int (*p)(int **, int **, int, int, int, int), int choice)
{
    int row1, row2, column1, column2;
    // input rows and columns of matrix one and two
    printf("No. of row and column of matrix 1?:  ");
    if (scanf(" %d %d", &row1, &column1) != 2)
    {
        printf("invalid input\n");
        while (getchar() != '\n')
            ;return 0;
    }
    if (row1 < 1 || column1 < 1)
    {
        printf("not a valid dimension\n");
        return 0;
    }
    printf("No. of row and column of matrix 2?:  ");
    if (scanf(" %d %d", &row2, &column2) != 2)
    {
        printf("invalid input\n");
        while (getchar() != '\n')
            ;return 0;
    }
    if (row2 < 1 || column2 < 1)
    {
        printf("not a valid dimension\n");
        return 0;
    }
    // dimension validation for addition, multiplication

    if ((choice == 1) && (row1 != row2 || column1 != column2))
    {
        printf("invalid dimension for addition!\n");
        return 0;
    }
    if (choice == 2 && (column1 != row2))
    {
        printf("invalid dimension for Multiplication!\n");
        return 0;
    }
    int **arr1 = (int **)malloc(row1 * sizeof(int *)); // array of two pointers,row created
    if (arr1 == NULL)
    {
        printf("ERROR!\n");
        return -1;
    }
    for (int i = 0; i < row1; i++)
    {
        arr1[i] = (int *)malloc(column1 * sizeof(int)); // each row i memory for column1 integers,column created
        if (arr1[i] == NULL)
        {
            printf("ERROR!\n");
            for (int j = 0; j < i; j++)
                free(arr1[j]);
            free(arr1);
            return -1;
        }
    }
    int **arr2 = (int **)malloc(row2 * sizeof(int *));
    if (arr2 == NULL)
    {
        printf("ERROR!\n");
        return -1;
    }
    for (int i = 0; i < row2; i++)
    {
        arr2[i] = (int *)malloc(column2 * sizeof(int));
        if (arr2[i] == NULL)
        {
            printf("ERROR!\n");
            for (int j = 0; j < i; j++)
                free(arr2[j]);
            free(arr2);
            return -1;
        }
    }
    // entering elements of matrix
    printf("MATRIX 1\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column1; j++)
        {
            printf("Enter element of Row%d Column %d: ", i, j);
            if (scanf("%d", &arr1[i][j]) != 1)
            {
                printf("invalid input\n");
                while (getchar() != '\n')
                    ;
            }
        }
    }
    printf("MATRIX 2\n");
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < column2; j++)
        {
            printf("Enter element of Row%d Column %d: ", i, j);
            if (scanf("%d", &arr2[i][j]) != 1)
            {
                printf("invalid input\n");
                while (getchar() != '\n')
                    ;
            }
        }
    }
    p(arr1, arr2, row1, column1, row2, column2);
    for (int i = 0; i < row1; i++)
        free(arr1[i]);
    free(arr1);
    for (int i = 0; i < row2; i++)
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
            ;return 0;
    }
    if (row < 1 || column < 1)
    {
        printf("invalid dimension!\n");
        return 0;
    }
    int **arr = (int **)malloc(row * sizeof(int *));
    if (arr == NULL)
    {
        printf("ERROR!\n");
        return -1;
    }
    for (int i = 0; i < row; i++)
    {
        arr[i] = (int *)malloc(column * sizeof(int));
        if (arr[i] == NULL)
        {
            printf("ERROR!\n");
            for (int j = 0; j < i; j++)
                free(arr[j]);
            free(arr);
            return -1;
        }
    }

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
    for (int i = 0; i < row; i++)
        free(arr[i]);
    free(arr);
    return 0;
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n\nMatrix Operation Engine\n");
        printf("1.Addition\n2.Multiplication\n3.Transpose\nEnter your option(0 to quit): ");
        if (scanf(" %d", &choice) != 1)
        {
            printf("No such option!\n");
            while (getchar() != '\n')
                ;
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
    }
    return 0;
}

int addition(int **arr1, int **arr2, int row1, int column1, int row2, int column2)
{
    printf("Result\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column1; j++)
        {
            printf("%d \t", arr1[i][j] + arr2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
int multiplication(int **arr1, int **arr2, int row1, int column1, int row2, int column2)
{
    int **ans_arr = (int **)calloc(row1, sizeof(int *));
    if (ans_arr == NULL)
    {
        printf("ERROR!\n");
        return -1;
    }
    for (int i = 0; i < row1; i++)
    {
        ans_arr[i] = (int *)calloc(column2, sizeof(int));
        if (ans_arr[i] == NULL)
        {
            printf("ERROR!\n");
            for (int j = 0; j <= i; j++)
                free(ans_arr[j]);
            free(ans_arr);
            return -1;
        }
    }
    int sum = 0;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column2; j++)
        {
            for (int k = 0; k < row2; k++)
            {
                sum += arr1[i][k] * arr2[k][j];
            }
            ans_arr[i][j] = sum;
            sum = 0;
        }
    }
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column2; j++)
        {
            printf("%d\t", ans_arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < row1; i++)
        free(ans_arr[i]);
    free(ans_arr);
    return 0;
}
int transpose(int **arr, int row, int column)
{
    int **swap_arr = (int **)malloc(column * sizeof(int *));
    if (swap_arr == NULL)
    {
        printf("ERROR!\n");
        return -1;
    }
    for (int i = 0; i < column; i++)
    {
        swap_arr[i] = (int *)malloc(row * sizeof(int));
        if (swap_arr[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(swap_arr[j]);
            free(swap_arr);
            return -1;
        }
    }

    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            swap_arr[i][j] = arr[j][i];
        }
    }

    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("%d \t", swap_arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < column; i++)
        free(swap_arr[i]);
    free(swap_arr);
    return 0;
}