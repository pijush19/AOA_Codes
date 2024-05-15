#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>

#define SIZE 100


void InsertionSort(int A[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i - 1;
        int x = A[i];
        while(j >= 0 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
    printf("The sorted array is:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

}

int main()
{
    int A[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        A[i] = rand() % 100;
    }
    // int size = sizeof(A) / sizeof(A[0]);
    int size = SIZE;
    clock_t start = clock();
    InsertionSort(A, size);
    clock_t end = clock();
    printf("\nTotal time required : %ld", ((double)(end - start)) / CLOCKS_PER_SEC);
return 0;
}