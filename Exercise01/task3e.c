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
    printf("%d\n", count); 
}

int main() {
    int length = 100000;
    bubbleSort(array, length);
    return 0;
}