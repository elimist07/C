#include <stdio.h>
#include <string.h>
int comp(void *a, void *b)
{
    return (*(int *)a - *(int *)b);//typecasted into integer pointer and defrenced their value for difference
}
void swap(void *a, void *b, size_t size)
{
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}
void bubble_sort(void *array, size_t n, size_t size)
{
    int comps = 0, swaps = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            void *a = (char *)array + j * size, *b = (char *)array + (j + 1) * size;//used char* as it helps in exact byte movement 
            comps++;
            if (comp(a, b) > 0)//return +ve if jth term is larger than (j+1)th term,if not then doesnt swap
            {
                swap(a, b, size);
                swaps++;
            }
        }
    }
    printf("No of comparisons:%d\nNo of swaps:%d\n",comps,swaps);
}

int main()
{
    int array[5] = {5, 3, 4, 2, 1};
    bubble_sort(array, 5, sizeof(int));
    for (int i = 0; i < 5; i++)
        printf("%d", array[i]);
    return 0;
}
