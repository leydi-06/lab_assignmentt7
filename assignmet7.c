#include<stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int array[], int num, int swaps[]) {
    int i, j;
    for (i = 0; i < num - 1; i++) {
        for (j = 0; j < num - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                swaps[array[j]]++;
                swaps[array[j + 1]]++;
            }
        }
    }
}
void selectionSort(int array[], int num, int swaps[]) {
    int e, d, index2;
    for (e = 0; e < num - 1; e++) {
        index2 = e;
        for (d = e + 1; d < num; d++) {
            if (array[d] < array[index2]) {
                index2 = d;
            }
        }
        if (index2 != e) {
            int temp = array[e];
            array[e] = array[index2];
            array[index2] = temp;
            swaps[array[e]]++;
            swaps[array[index2]]++;
        }
    }
}

int main() {
    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int swaps1[100] = {0};
    int swaps2[100] = {0};

    bubbleSort(arr1, n1, swaps1);
    bubbleSort(arr2, n2, swaps2);
    
    printf("array1 bubble sort:\n");
    for (int i = 0; i < n1; i++) {
        printf("%d: %d\n", arr1[i], swaps1[arr1[i]]);
    }
    printf("total # of swaps: %d\n", swaps1[0]);

    printf("\narray2 bubble sort:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d: %d\n", arr2[i], swaps2[arr2[i]]);
    }
    printf("total # of swaps: %d\n", swaps2[0]);

    for (int i = 0; i < 100; i++) {
        swaps1[i] = 0;
        swaps2[i] = 0;
    }
    //Initialize the array as it used to be, meaning is 0.
    int arr3[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr4[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int swaps3[100] = {0};
    int swaps4[100] = {0};

    selectionSort(arr3, n1, swaps3);
    selectionSort(arr4, n2, swaps4);

  printf("array1 selection sort:\n");
    for (int e = 0; e < n1; e++) {
        printf("%d: %d\n", arr1[e], swaps3[arr1[e]]);
    }
    printf("total # of swaps: %d\n", swaps3[0]);

    printf("array2 selection sort:\n");
    for (int e = 0; e < n2; e++) {
        printf("%d: %d\n", arr2[e], swaps4[arr2[e]]);
    }
    printf("total # of swaps: %d\n", swaps4[0]);

    return 0;
}