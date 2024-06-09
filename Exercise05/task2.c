#include <stdio.h>

int counter = 0;
int innercounter = 0;

void swap(int array[], int l, int r){
    int temp = array[l];
    array[l] = array[r];
    array[r] = temp;
}

int hoarePartition(int array[], int leftIndex, int rightIndex){
    int pivot = array[rightIndex];
    int i = leftIndex-1;
    int j = rightIndex+1;

    while (1){
        do{
            j--;
            innercounter++;
        }
        while (array[j] > pivot);
        do{
            i++;
            innercounter++;
        }
        while (array[i] < pivot);
        if (i>=j){
            return i;}
        counter++;
        swap(array, i, j);}
}

void quicksort(int array[], int leftIndex, int rightIndex){
    if (leftIndex < rightIndex){
        int m = hoarePartition(array, leftIndex, rightIndex);
        quicksort(array, leftIndex, m-1);
        quicksort(array, m, rightIndex);
    }
}


void print_array(int A[], int n){
    for (int i = 0; i < n - 1; i++){
        printf("%d, ", A[i]);
    }
    printf("%d", A[n-1]);
}

int main(){
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(array)/sizeof(array[0]);
    int left = 0;

    // printf("%d", controlMaxHeap(array, currentIndex, length));
    quicksort(array, left, length-1);
    printf("%d\n", counter);
    printf("%d\n", innercounter);
    print_array(array, length);
    return 0;
    }