#include <stdio.h>
#define MAX_SIZE 1000

void bubbleSort(int arr[], int x){
    for(int i=0; i<x-1; i++){
        for(int j=0; j<x-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void selectionSort(int arr[], int x){
    for(int i=0; i<x-1; i++){
        int minIndex = i;
        for(int j=i+1; j<x; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
void insertionSort(int arr[],int x)
{
    int key;

 for(int i=0;i<x;i++)
  {
   int j=i-1;
   key=arr[i];
   while(j>=0&&arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
 }
}

int main()
 {
    FILE *input_file, *output_file;
    int arr[MAX_SIZE], x, i;
    int choice;

    // Open input file for reading
    input_file = fopen("Input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file!");
        return 1;
    }

    // Open output file for writing
    output_file = fopen("Output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file!");
        return 1;
    }

    // Read the value of X from user
    printf("Enter the value of X: ");
    scanf("%d", &x);

    // Read X arr from input file
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

    switch(choice){
        case 1:
            insertionSort(arr, x);
            break;
     /*   case 2:
            mergeSort(arr, x);
            break;  */
        case 3:
            bubbleSort(arr, x);
            break;
        case 4:
            selectionSort(arr, x);
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }


    // Write X arr to output file
    for (i = 0; i < x; i++) {
        fprintf(output_file, "%d ", arr[i]);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("Array successfully written to Output.txt!");

    return 0;
}
