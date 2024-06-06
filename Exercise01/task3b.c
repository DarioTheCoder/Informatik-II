#include <stdio.h>

void selectionSort(int array[], int length) {
    int key;
    for (int i=length-1; i > 0; i--){
        key = 0;
        for (int j=0; j<i; j++) {
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
}


int main(){
    int array[] = {4,3,2,5,1};
    int length = 5;
    selectionSort(array, length);
    return 0;
    }