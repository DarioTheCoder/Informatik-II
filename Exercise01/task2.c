#include <stdio.h>
#include <string.h>

void rleCompression(char string[], int length) {
    int index = 0;
    int count = 0;
    char current;
    while (index <= length) {
        if (index == 0) {
            current = string[0];
        }
        if (string[index] == current){
            count++;
            index++;
        }
        else {
            printf("%d", count);
            printf("%c", current);
            count = 0;
            current = string[index];
        }
    }
}

int main() {
    char string[] = "AAABBAAAA";
    int length = (sizeof(string) / sizeof(string[0])) - 1;
    rleCompression(string, length);
    return 0;
}
