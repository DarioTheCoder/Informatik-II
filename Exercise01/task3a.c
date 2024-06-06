#include <stdio.h>

void bubbleSort(int array[], int length) {
    for (int i=length-1; i > 0; i--){
        for (int j=0; j<i; j++) {
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
}


int main(){
    int array[] = {4,3,2,5,1};
    int length = 5;
    bubbleSort(array, length);
    return 0;
    }