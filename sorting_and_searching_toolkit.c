#include <stdio.h>
#include <string.h>
void swap(void *, void *, int);
int comp_int(void *, void *);
int comp_float(void *, void *);
int comp_string(void *, void *);
void bubble_sort(void *, int, int, int (*comp)(void *, void *));
void selection_sort(void *, int, int, int (*comp)(void *, void *));
void binary_search(void *, int, int, int , int (*comp)(void *, void *));

int main()
{
    // char array1[][100] = {"Kathmandu", "Delhi", "Berlin", "Tokyo", "New York", "Cape town", "Beijing"};
    // int n1 = sizeof(array1) / sizeof(array1[0]);
    // char array2[][100] = {"Kathmandu", "Delhi", "Berlin", "Tokyo", "New York", "Cape town", "Beijing"};
    // int n2 = sizeof(array2) / sizeof(array2[0]);
    // // int array[] = {5, 4, 10, 2, 1};
    // // int n = sizeof(array) / sizeof(array[0]);
    // selection_sort(array1, n1, sizeof(array1[0]), comp_string);
    // for (int i = 0; i < n1; i++)
    // {
    //     printf("%s\t", array1[i]);
    // }
    // printf("\n");
    // bubble_sort(array2, n2, sizeof(array2[0]), comp_string);
    // for (int i = 0; i < n2; i++)
    // {
    //     printf("%s\t", array2[i]);
    // }
    // return 0;
    int ar[] = {12, 13, 114, 17};
    int n = sizeof(ar) / sizeof(ar[0]);
    binary_search(ar, n, sizeof(ar[0]),1, comp_int);
}

void bubble_sort(void *array, int n, int size, int (*comp)(void *, void *))
{
    int no_of_swaps = 0, no_of_comp = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            no_of_comp++;
            void *a = (char *)array + j * size, *b = (char *)array + (j + 1) * size; // void* point to any data type,not limitd to single datatype
            if (comp(a, b) > 0)
            {
                swap(a, b, size);
                no_of_swaps++;
            }
        }
    }
    printf("No of comparisons=%d\nNo of swaps=%d\n", no_of_comp, no_of_swaps);
}

void selection_sort(void *array, int n, int size, int (*comp)(void *, void *))
{
    int no_of_comp = 0, no_of_swaps = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            void *a = (char *)array + min_index * size, *b = (char *)array + j * size;
            no_of_comp++;
            if (comp(a, b) > 0)
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            void *k = (char *)array + i * size, *l = (char *)array + min_index * size;
            swap(k, l, size);
            no_of_swaps++;
        }
    }
    printf("No of comparisons=%d\nNo of swaps=%d\n", no_of_comp, no_of_swaps);
}
void binary_search(void *array, int n, int size, int target, int (*comp)(void *, void *))
{
    int low = 0, high = n;
    int mid_index = low + (high - low) / 2;
    void *a = (char *)array, *mid = (char *)array + mid_index * size, *b = (char *)array + n * size;
    if (comp(a, &target) == -1 || comp(b, &target) == 1)
    {
        printf("Target not in array");
        return;
    }
    int re;
    while ((re = comp(&target, mid)) != 0)
    {
        if (re == 1)
        {
            swap(a, mid, size);
            low = mid_index;
            mid_index = low + (high - low) / 2;
            mid = (char *)array + mid_index * size;
        }
        if (re == -1)
        {
            swap(b, mid, size);
            high = mid_index;
            mid_index = low + (high - low) / 2;
            mid = (char *)array + mid_index * size;
        }
    }
    if (re == 0)
        printf("Target found at index %d\n", mid_index);
    else
        printf("Target not in array");
}
int comp_int(void *a, void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;
    if (*(int *)a < *(int *)b)
        return -1;
    return 0;
}
int comp_float(void *a, void *b)
{
    if (*(float *)a > *(float *)b)
        return 1;
    if (*(float *)a < *(float *)b)
        return -1;
    return 0;
}

int comp_string(void *a, void *b)
{
    char *str1 = (char *)a;
    char *str2 = (char *)b;
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 > *str2)
            return 1;
        if (*str1 < *str2)
            return -1;
        str1++;
        str2++;
    }
    if (*str1 == '\0' && *str2 == '\0')
        return 0;
    if (*str1 == '\0')
        return -1;
    return 1;
}

void swap(void *a, void *b, int size)
{
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}