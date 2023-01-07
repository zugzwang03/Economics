#include <stdio.h>
#include <stdlib.h>

int par(int index)
{
    int parent = (index - 1) / 2;
    if (index != 0)
        return parent;
    else
        return -1;
}
void heapify(int index, int arr[], int n)
{
    if (index >= 0 && par(index) >= 0 && arr[par(index)] < arr[index])
    {
        int val = arr[par(index)];
        arr[par(index)] = arr[index];
        arr[index] = val;
        heapify(par(index), arr, n);
    }
}

void preorder(int arr[], int index, int n)
{
    if (index < n)
    {
        printf("%d -> ", arr[index]);
        preorder(arr, 2 * index + 1, n);
        preorder(arr, 2 * index + 2, n);
    }
}

void inorder(int arr[], int index, int n)
{
    if (index < n)
    {
        inorder(arr, 2 * index + 1, n);
        printf("%d -> ", arr[index]);
        inorder(arr, 2 * index + 2, n);
    }
}

void postorder(int arr[], int index, int n)
{
    if (index < n)
    {
        postorder(arr, 2 * index + 1, n);
        postorder(arr, 2 * index + 2, n);
        printf("%d -> ", arr[index]);
    }
}



int main()
{
    int n = 10;
    int *arr = (int *)malloc(sizeof(int) * n);
    int size = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        int x;
        printf("Enter the value of x: ");
        scanf("%d", &x);
        arr[i] = x;
        heapify(size, arr, n);
        size++;
    }
    printf("After insertion, and heapifying, the array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    inorder(arr, 0, n);
    printf("\n");
    preorder(arr, 0, n);
    printf("\n");
    postorder(arr, 0, n);
    printf("\n");
}

// 5 4 2 1 3
//   5
// 4   2
//1 3

// 10 9 6 7 8 2 5 1 4 3
//        10
//     9      6
//   7  8   2   5
// 1  4 3