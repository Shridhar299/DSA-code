#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void bubbleSort(int arr[], int x) {
    for(int i = 0; i < x - 1; i++) {
        for(int j = 0; j < x - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int x) {
    for(int i = 0; i < x - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < x; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int x) {
    int key;

    for(int i = 0; i < x; i++) {
        int j = i - 1;
        key = arr[i];
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    FILE *input_file, *log_file;
    int arr[MAX_SIZE], x, i;
    int choice;

    // Open input file for reading
    input_file = fopen("Input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file!");
        return 1;
    }

    // Open log file for writing
    log_file = fopen("log.txt", "w");
    if (log_file == NULL) {
        printf("Error opening log file!");
        return 1;
    }

    // Read the value of X from user
    printf("Enter the value of X: ");
    scanf("%d", &x);

    // Read X elements from input file
    for (i = 0; i < x; i++) {
        fscanf(input_file, "%d", &arr[i]);
    }

    printf("Choose a sorting technique:\n");
    printf("1. Insertion Sort\n");
    printf("2. Merge Sort\n");
    printf("3. Bubble Sort\n");
    printf("4. Selection Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    clock_t start, end;
    double cpu_time_used;
    switch(choice) {
        case 1:
            start = clock();
            insertionSort(arr, x);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            fprintf(log_file, "Insertion Sort, %d, %f\n", x, cpu_time_used);
            break;
        /*case 2:
            mergeSort(arr, x);
            break;*/
        case 3:
            start = clock();
            bubbleSort(arr, x);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            fprintf(log_file, "Bubble Sort, %d, %f\n", x, cpu_time_used);
            break;
        case 4:
            start = clock();
            selectionSort(arr, x);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            fprintf(log_file, "Selection Sort, %d, %f\n", x, cpu_time_used);

    }
    // Close files
    fclose(input_file);
    fclose(log_file);

    printf("The data is successfully written to log.txt!");

    return 0;
}
