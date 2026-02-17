#include <stdio.h>
#include <string.h>
void swap(void *, void *, int);
int comp_int(void *, void *);
int comp_float(void *, void *);
int comp_string(void *, void *);
void bubble_sort(void *, int, int, int (*comp)(void *, void *));

int main()
{
    char array[][100] = {"Kathmandu", "Delhi", "Berlin","Tokyo","New York","Cape town","Beijing"};
    int n = sizeof(array) / sizeof(array[0]);
    bubble_sort(array, n, sizeof(array[0]), comp_string);
    for (int i = 0; i < n; i++)
    {
        printf("%s\t", array[i]);
    }
    return 0;
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