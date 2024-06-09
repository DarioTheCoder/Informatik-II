#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
    struct node *prev;};

    
void printList(struct node *node) {
    while (node != NULL) {
        printf(" %d ", node->val);
        node = node->next;
    }
}


struct node *reverse(struct node *head){
    if (head == NULL || head->next == NULL){
        return head;
    } 

    struct node *temp = NULL;
    struct node *current = head;

    while (current !=NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // because inverted
    }

    // At the end of the loop, temp will be pointing to the last node processed
    // and since it was swapped, it is actually the new head of the reversed list.

    printf("current %d\n", current ? current->val : -1);
    printf("temp %d\n", temp ? temp->val : -1);
    printf("head %d\n", head ? head->val : -1);

    return temp->prev;
}


int main() {
    /* Init list */
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    struct node* fourth = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));

    head->val = 1;
    head->next = second;
    /* head->next = NULL; */
    head->prev = NULL;

    second->val = 2;
    second->next = third;
    second->prev = head;

    third->val = 3;
    third->next = fourth;
    third->prev = second;

    fourth->val = 5;
    fourth->next = NULL;
    fourth->prev = third;

    printf("Original Doubly linked list:\n");
    printList(head); printf("\n");

    /* REVERSING CALL(S) */
    head = reverse(head);       /* assign new head */
    /* head = reverseRecursive(head); */

    printf("\nReversed Doubly linked list \n");
    printList(head);
    printf("\ndone\n");

    return 0;
}