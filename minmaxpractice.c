#include<stdio.h>
#include<math.h>
#include<string.h>
#define SIZE 50
int A[SIZE];
void MaxMin(int A[], int i, int j, int *max, int *min)
{
    int max1, min1, max2, min2, mid;
    if(i == j)
    {
        *max = *min = A[i];
    }
    else if(i == j - 1)
    {
        if(A[i] < A[j])
        {
            *min = A[i];
            *max = A[j];
        }
        else
        {
            *min = A[j];
            *max = A[i];
        }
    }
    else{
        mid = (i + j) / 2;
        MaxMin(A, i, mid, &max1, &min1);
        MaxMin(A, mid + 1, j, &max2, &min2);

        *max =  (max1 > max2) ?  max1 : max2;
        *min =  (min1 > min2) ?  min2 : min1;

    }

}

#define SIZE 50
int main()
{
    int n, max, min;
    printf("Enter the no of elements:");
    scanf("%d", &n);
    printf("Enter the elements of array:");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("\n");

    MaxMin(A, 0, n - 1, &max, &min);
    printf("Maximum element is : %d\n", max);
    printf("Minimum element is : %d\n", min);


return 0;
}