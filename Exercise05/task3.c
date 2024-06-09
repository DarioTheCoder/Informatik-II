#include <stdio.h> 

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
        }
        while (array[j] > pivot);
        do{
            i++;
        }
        while (array[i] < pivot);
        if (i>=j){
            return i;}
        swap(array, i, j);}
}

int recursiveMedian(int array[], int left, int right, int medianIndex){
    if (left >= right){
        return array[left];
    }
    int m = hoarePartition(array,left, right);
    if (medianIndex < m){
        recursiveMedian(array, left, m-1, medianIndex);
        }
    else {
        recursiveMedian(array, m, right, medianIndex);

    }
}

float findMedian(int array[], int n){
    if (n % 2 == 0){
        int smallMedian = recursiveMedian(array, 0, n-1, (n-1)/2);
        int largerMedian = array[n/2];
        for (int i=n/2 +1; i < n; i++){
            if (largerMedian > array[i]){
                largerMedian = array[i];
            }
        }
        return (float) (smallMedian + largerMedian) / 2;
    }
    return (float) recursiveMedian(array, 0, n-1, (n-1)/2);
}

void print_array(int A[], int n){
    for (int i = 0; i < n - 1; i++){
        printf("%d, ", A[i]);
    }
    printf("%d", A[n-1]);
}

int main(){
    int array[] = {5, 2, 8, 3, 7};
    int length = sizeof(array)/sizeof(array[0]);
    int left = 0;

    // printf("%d", controlMaxHeap(array, currentIndex, length));
    printf("%0.1f",findMedian(array, length));
    print_array(array, length);
    return 0;
    }