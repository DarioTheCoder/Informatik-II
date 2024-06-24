
#include <stdio.h>
#include <stdlib.h>

#define N 10

int h1(int k) { return k % N; }

int h2(int k) { return (int)(.1 * k) % N; }

void printT(int *T) {
    for (int i = 0; i < N; ++i) {
        printf("%d,", T[i]);
    }
    printf("\n");
}

int cuckooInsert(int *T1, int *T2, int k) {
    int i = 0;
    int probe = h1(k);
    int temp;
    while (i < 30){
        printf("T1: Inserted %d at 1.%d", k, h1(k));
        if (T1[probe] == -1){
            T1[probe] = k;
            printf("\n");
            return 1;
        }

        temp = T1[probe];
        T1[probe] = k;
        probe = h2(temp);

        printf(" pushed %d out\n", temp);
        printf("T2: Inserted %d at 2.%d", temp, h2(temp));

        if (T2[probe] == -1){
            T2[probe] = temp;
            printf("\n");
            return 2;
        }
        k = T2[probe];
        T2[probe] = temp;
        probe = h1(k);
        printf(" pushed %d out\n", k);
        i++;
    }
    printf("infinite loop\n");
    return 0;

}

void cukooSearch(int *T1, int *T2, int k) {
    if (T1[h1(k)] == k){
        printf("In HT 1 and index %d\n", h1(k));
    }
    else if (T2[h2(k)] == k){
        printf("In HT 1 and index %d\n", h2(k));
    }
    else {
        printf("not in any HT");
    }
    

}

int main(int argc, char *argv[]) {
    int T1[N];
    int T2[N];

    /* init tables */
    for (int i = 0; i < N; ++i) {
        T1[i] = -1;
        T2[i] = -1;
    }

    int n = 4;
    /* int vals[] = {44, 236, 36, 136}; /\* other example infinite loop *\/ */
//    int vals[] = {12, 112, 1112};
    int vals[] = {123, 112, 189, 12};

    printf("T1: ");
    printT(T1);
    printf("T2: ");
    printT(T2);

    printf("inserting...\n");

    for (int i = 0; i < n; ++i) {
        cuckooInsert(T1, T2, vals[i]);
    }

    printf("T1: ");
    printT(T1);
    printf("T2: ");
    printT(T2);

    cukooSearch(T1, T2, 236);

    return 0;
}
