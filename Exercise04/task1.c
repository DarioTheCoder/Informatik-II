#include <stdio.h>
#include <stdlib.h>

int closestNumber(int A[],int left, int right, int target){
    if (left == right) {
        return A[left];
    }
    else if (target <= A[left]) {
        return A[left];
    }
    else if (target >= A[right]) {
        return A[right];
    }
    
    int m = left + (right-left)/2;

    int leftclosests = closestNumber(A, left, m, target);
    int rightclosests = closestNumber(A, m+1, right, target);

    if (abs(A[m]-target) < abs(leftclosests - target) && abs(A[m]-target) < abs(rightclosests - target)) {
        return A[m];
    } else if (abs(leftclosests- target) < abs(rightclosests - target)) {
        return leftclosests;
    } else {return rightclosests;}
}


int main(){
    int array[] = {2, 5, 10, 12, 15, 24, 32};
    int left = 0;
    int length = 7;
    int target = 33;

    printf("%d",closestNumber(array, left, length-1, target));
    return 0;
    }