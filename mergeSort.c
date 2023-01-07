#include <stdalign.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int mid, int high)
{
    int *temp = (int *)malloc(sizeof(int) * (high - l + 1));
    int i = l, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while(j <= high)
    {
        temp[k++] = arr[j++];
    }
    for(int p = l; p <= high; p++)
    {
        arr[p] = temp[p - l]; 
    }
}
void merge_sort(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}
int main()
{
    int arr[] = {2, 6, 9, 0, 23, 4, 87};    
    int n = sizeof(arr) / sizeof(int);
    printf("The array before merge sort ...");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    merge_sort(arr, 0, n - 1);
    printf("\n The array after merge sort ...");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}