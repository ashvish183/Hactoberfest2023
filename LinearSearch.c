#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int n, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &key);

    int result = linearSearch(arr, n, key);

    (result != -1) ? printf("%d found at index %d.\n", key, result) : printf("%d not found in the array.\n", key);

    return 0;
}
