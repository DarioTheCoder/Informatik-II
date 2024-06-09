#include <stdio.h>



int leftchild(int currentIndex){
    return currentIndex * 2 + 1;
}
int rightchild(int currentIndex){
    return currentIndex * 2 + 2;
}

int controlMaxHeap(int array[], int currentIndex, int length){
    int left = leftchild(currentIndex);
    int right =  rightchild(currentIndex);

    if (left < length){
        if (array[left] > array[currentIndex]){
            return currentIndex;
        }
        int leftviolation = controlMaxHeap(array, left, length);
        if (leftviolation != -1) {
            return leftviolation;
        }
    }
    if (right < length){
        if (array[right] > array[currentIndex]){
            return currentIndex;
        }
        int rightviolation = controlMaxHeap(array, right, length);
        if (rightviolation != -1) {
            return rightviolation;
        }
    }
    return -1;
}

int heapify(int array[], int currentIndex, int length){
    int temp = currentIndex;
    int left = leftchild(currentIndex);
    int right =  rightchild(currentIndex);
    if (left < length && array[left] > array[currentIndex]){
        temp = left;
        }
    if (right < length && array[right] > array[currentIndex] && array[right] > array[temp]){
        temp = right;
        }
    if (temp != currentIndex){
        int temporary = array[currentIndex];
        array[currentIndex] = array[temp];
        array[temp] = temporary;
        heapify(array, temp, length);
    }
}
/*
int fixHeap(int array[], int length){
    for (int i=length/2 -1; i >= 0;i){
        if (controlMaxHeap(array, i, length) != -1){
            heapify(array, i, length);
        }
    }
}
*/
int fixHeap(int array[], int length){
    int problemIndex = controlMaxHeap(array, 0, length);
    while (problemIndex != -1){
        heapify(array, problemIndex, length);
        problemIndex = controlMaxHeap(array, 0, length);
    }
}

void print_array(int A[], int n){
    for (int i = 0; i < n - 1; i++){
        printf("%d, ", A[i]);
    }
    printf("%d", A[n-1]);
}

int main(){
    int array[] = {4, 10, 3, 5, 1};
    int length = 5;
    int currentIndex = 0;

    // printf("%d", controlMaxHeap(array, currentIndex, length));
    fixHeap(array, length);
    print_array(array, 5);
    return 0;
    }