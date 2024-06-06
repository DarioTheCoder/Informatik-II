#include <stdio.h>


int maxOverlap(int A[], int l, int m, int r){
    int maxleft = 0;
    int maxright = 0;

    int left = -9999;
    int right = -9999;

    for (int i=m; i>=l;i--){
        maxleft += A[i];
        if (maxleft > left) {
            left = maxleft;
        } 
    }
    for (int i=m+1; i<=r;i++){
        maxright += A[i];
        if (maxright > right) {
            right = maxright;
        } 
    }
    return right + left;
}

int maxSubarray(int array[], int left, int right){
    if (left == right){
        return array[left];
    }
    if (left < right) {
        int mid = left + (right-left) / 2;

        int maxleft = maxSubarray(array, left, mid);
        int maxright = maxSubarray(array, mid+1, right);

        int maxoverlap = maxOverlap(array, left, mid, right);

        if (maxright > maxleft && maxright > maxoverlap) {
            return maxright;
        } else if (maxleft > maxright && maxleft > maxoverlap){
            return maxleft;
        } else {
            return maxoverlap;}
    }
}


int main(){
    int array[] = {-1, 2, -4, 1, 9, -6, 7, -3, 5};
    int left = 0;
    int length = 9;

    printf("%d",maxSubarray(array, left, length-1));
    return 0;
    }