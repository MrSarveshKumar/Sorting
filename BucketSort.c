#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(int arr[], int size, int numBuckets) {
  
    int buckets[numBuckets][size];
    int bucketSizes[numBuckets];

    for (int i = 0; i < numBuckets; ++i) {
        bucketSizes[i] = 0;
    }

    for (int i = 0; i < size; ++i) {
        int bucketIndex = arr[i] / numBuckets;
        buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
        bucketSizes[bucketIndex]++;
    }

    for (int i = 0; i < numBuckets; ++i) {
        insertionSort(buckets[i], bucketSizes[i]);
    }

    int index = 0;
    for (int i = 0; i < numBuckets; ++i) {
        for (int j = 0; j < bucketSizes[i]; ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int size, numBuckets;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the number of buckets: ");
    scanf("%d", &numBuckets);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, size, numBuckets);

    printf("Sorted array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
