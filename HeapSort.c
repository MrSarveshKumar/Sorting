#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int size, int rootIndex) {
    int largest = rootIndex;
    int leftChild = 2 * rootIndex + 1;
    int rightChild = 2 * rootIndex + 2;

    if (leftChild < size && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }

    if (rightChild < size && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    if (largest != rootIndex) {
        int temp = arr[rootIndex];
        arr[rootIndex] = arr[largest];
        arr[largest] = temp;

        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
