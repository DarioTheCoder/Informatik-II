#include <stdio.h>

int zeroSubarray(int array[], int length) {
    for (int i=0; i < length; i++) {
        int sum = 0;
        for (int j = i; j<length; j++) {
            sum += array[j];
            if (sum == 0) {
                return 1;
            }

        }
    }
    return 0;
}


int main(){
    int array[] = {-2, 4, -1, 5, 9, -12};
    int length = 6;
    int value = zeroSubarray(array, length);
    printf("%d", value);
    return 0;
    }