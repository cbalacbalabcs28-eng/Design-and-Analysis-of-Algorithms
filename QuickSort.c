#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function: places pivot at correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // Choosing last element as pivot
    int i = low - 1;         // Index of smaller element
    int j;

    for (j=low;j<high;j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);  // Return pivot index
}

// Quick Sort function (Divide and Conquer)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Divide: partition the array
        int pi = partition(arr, low, high);

        // Conquer: recursively sort subarrays
        quickSort(arr, low, pi - 1);  // Left of pivot
        quickSort(arr, pi + 1, high); // Right of pivot
    }
}

// Function to print array
void printArray(int arr[], int size){
    int i;
    for(i=0;i<size;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100],i,n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
