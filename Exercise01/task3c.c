#include <stdio.h>

void bubbleSort(int array[], int length) {
    int count = 0;
    for (int i=length-1; i > 0; i--){
        for (int j=0; j<i; j++) {
            count++;
            if (array[j] < array[j+1]){
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;

            }
        }
    }
    for (int i = 0; i < length; i++) { 
        printf("%d ", array[i]); 
    }
    printf("\n");
    printf("%d\n", count); 
}


void selectionSort(int array[], int length) {
    int key;
    int count = 0;
    for (int i=length-1; i > 0; i--){
        key = 0;
        for (int j=0; j<i; j++) {
            count++;
            if (array[key] > array[j+1]){
                key = j+1;
            }
        int temp = array[i];
        array[i] = array[key];
        array[key] = temp;
        }
    }
    for (int i = 0; i < length; i++) { 
        printf("%d ", array[i]); 
    }
    printf("\n");
    printf("%d \n", count); 
}

void insertionSort(int array[], int length) {
    int count = 0;
    for (int i=1; i < length; i++){
        int j = i-1;
        int current = array[i];
        while (j >= 0 && array[j] > current) {
            count++;
            array[j+1] = array[j];
            j--;
            }
        array[j+1] = current;
    }

    for (int i = 0; i < length; i++) { 
        printf("%d ", array[i]); }
    printf("\n");
    printf("%d\n", count); 
} 



int main(){
    //int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int array[] = {0, 1, 2, 3, 4, 5 , 6, 7, 8, 9};
    // int array[] = {0, 1, 3, 4, 2, 8, 9, 5, 6, 7};
    int length = 10;
    bubbleSort(array, length);
    int array1[] = {0, 1, 2, 3, 4, 5 , 6, 7, 8, 9};

    selectionSort(array1, length);
    int array2[] = {0, 1, 2, 3, 4, 5 , 6, 7, 8, 9};

    insertionSort(array2, length);
    return 0;
    }