
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

int h(int k, int n) { return (7 * k) % n; }

int detectCycle(struct Node *l) {
    int n = 10;
    int HT[n];
    struct Node *p = l;
    int probe;

    for (int i = 0; i<10; i++){
        HT[i] = -1;
    }

    while (p){
        printf("at %d\n", p->val);
        probe = h(p->val, n);
        while (HT[probe] != -1){
            if (HT[probe] == p->val){
                printf("Cycle detected");
                return 1;
                }
            probe++;
        }
        HT[probe] = p->val;
        p = p->next;
        }
    printf("NO Cycle");
    return 0;
}

int main(int argc, char *argv[]) {
    struct Node *head;

    head = malloc(sizeof(struct Node));
    head->val = 1;

    head->next = malloc(sizeof(struct Node));
    head->next->val = 2;

    head->next->next = malloc(sizeof(struct Node));
    head->next->next->val = 3;

    head->next->next->next = malloc(sizeof(struct Node));
    head->next->next->next->val = 4;

    /* without cycle */
    head->next->next->next->next = malloc(sizeof(struct Node));
    head->next->next->next->next->val =
        11; /* maps to same slot, but should not trigger cycle */

    /* with cycle */
    /* head->next->next->next->next = head->next; */

    detectCycle(head);

    return 0;
}
