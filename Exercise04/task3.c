#include <stdio.h>


int majority(int array[], int left, int right){
    if (left == right){
        return array[left];
    }
    int mid = left + (right-left)/2;

    int leftmajority = majority(array, left, mid);
    int rightmajority = majority(array, mid+1, right);

    if (leftmajority == rightmajority) {
        return leftmajority;
    }

    int countleft = 0;
    int countright = 0;

    for (int i = left; i <= right; i++){
        if (array[i] == leftmajority){
            countleft++;
        } else if (array[i] == rightmajority){
            countright++;
        }
    }
    if (countleft > countright){
        return leftmajority;
    }
    return rightmajority;
}

int main(){
    int array[] = {2, 1, 0, 0, 2, 2, 2, 1,0};
    int left = 0;
    int length = 9;

    printf("%d",majority(array, left, length-1));
    return 0;
    }