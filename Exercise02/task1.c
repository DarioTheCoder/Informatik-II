#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Check the symbols in index i and index j
*/
int isPalindrome(char X[], int i, int j) {
    if (i>=j){
        return 1;} 
    if (X[i] == X[j]){
        return isPalindrome(X, i+1, j-1);}
    return 0;

}

int main() {
    char X[] = "1a_b3cD45t54Dc3b_a1";
    int length = strlen(X);
    int res = isPalindrome(X, 0, length-1);
    printf("%d", res);
    if (res) {
        printf("This is a Palindrome.");
    }
    else {
        printf("This is not a Palindrome.");
    }

    return 0;
}