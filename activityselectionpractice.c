#include <stdio.h>
#include <math.h>
#include <string.h>
#define SIZE 50

void printActivities(int s[], int f[], int n)
{


    printf("The activities selected are:");
    int i, j;
    i = 0;
    printf("A%d ", i);


    for(j = 1; j < n; j++)
    {
        if(s[j] >= f[i])
        {
            printf("A%d ", j);
            i = j;
        }
        
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}
int main()
{
    int s[SIZE], f[SIZE], n;
    printf("Enter no of activities:");
    scanf("%d", &n);
    printf("Enter the start time of activities:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }

    printf("Enter the finish time of activities:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &f[i]);
    }

    //Sorting the array according to finish time
    int temp;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(f[j] > f[j + 1])
            {
                swap(&f[j], &f[j + 1]);
                swap(&s[j], &s[j + 1]);
            }

        }
    }

    printActivities(s, f, n);


    return 0;
}