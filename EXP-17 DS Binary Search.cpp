#include <stdio.h>
void BubbleSort(int arr[], int Length);
void swap(int arr[], int m, int n);
int search_value(int arr[], int target, int Length)
{
    int low, high, mid;
    low = 0;
    high = Length - 1;
    mid = (low + high) / 2;
    while(low<=high)
    {
        if (arr[mid] == target)
            return mid;
        else
            if (target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        mid = (low + high) / 2;
    }
    return -1;
}
void BubbleSort(int arr[], int Length)
{
    int i, j;
    for(i=0;i<Length-1;i++)
    {
        for(j=0;j<Length-i-1;j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr, j, j+1);
        }
    }
}
void swap(int arr[], int m, int n)
{
    int t = arr[m];
    arr[m] = arr[n];
    arr[n] = t;
}
int main()
{
     
    int search_list[] = { 3, 1, 9, 8, 7, 12, 56, 23, 89 };
    int n, result, i, elements_count;
    elements_count=sizeof(search_list)/sizeof(int);
    
    printf("Array Elements: ");
    for(i=0;i<elements_count;i++) 
        printf("%d ", search_list[i]);
    printf("\n\n");
    
    BubbleSort(search_list, elements_count);
    printf("Sorted Array: ");
    for(i=0;i<elements_count;i++) 
        printf("%d ", search_list[i]);
    printf("\n\n");
    
    printf("Enter a value to search: ");
    scanf("%d", &n);
    result = search_value(search_list, n, elements_count);
    if (result != -1)
        printf("The target value %d is found at position %d", n, (result+1));
    else
        printf("Target not found!");
    return 0;
}