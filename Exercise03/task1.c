#include <stdio.h>
#include <time.h> // measuring run time

int n, t;
int A[100000000];

int linear_search(int A[], int n, int t) {
    for (int i=0; i < n-1; i++){
        if (A[i] == t) {return 1;}
    }
    return 0; // not found
}

int binary_search(int A[], int n, int t) {
    int left = 0;
    int right = n-1;
    int m;
    while (left <= right) {
        m = (int) ((right - left) / 2 + left);

        if (t == A[m]){
            return 1;
        }
        else if (t < A[m]){
            right = m-1;
        } else {
            left = m+1;
        }
    }
    return 0; // not found
}

int main() {
    clock_t start, end;
    printf("Enter an integer for n: ");
    scanf("%d", &n); 
    printf("Generate an array with %d distinct integers from 1 to %d.\n", n, n);
    for(int i = 0; i < n; i++) A[i] = i + 1;
    printf("Enter an integer for t: \n");
    scanf("%d", &t); 
    start = clock();
    linear_search(A, n, t); // your implementation
    end = clock();
    double run_time = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
    printf("Linear search takes : %f millseconds\n", run_time); 

    start = clock();
    binary_search(A, n, t); // your implementation
    end = clock();
    run_time = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
    printf("Binary search takes : %f millseconds\n", run_time); 
}