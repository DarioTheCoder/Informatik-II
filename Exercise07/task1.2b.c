#include <stdio.h>
#include <stdlib.h> //important for malloc
#include <stdbool.h>


// singly linked lists

struct node {
    int val;
    struct node *next;
};

struct node *head, *tail;

void new(){
    head = tail = NULL;
}

bool is_empty(){
    return (head==NULL && tail ==NULL);
}

void enqueue(int x){
    if (is_empty){
        struct node *new = malloc(sizeof(struct node));
        new->val = x ;
        new->next = NULL;
        head == tail == new;
    } else {
        struct node *new = malloc(sizeof(struct node));
        new->val = x;
        new->next = NULL;
        tail->next = new;
        tail = new;

    }
}

int dequeue(){
    if (is_empty){
        return -1;
    }
    if (head == tail){
        int value = head->val;
        free(head);
        head == tail == NULL;
        return value;
    } else {
        int value = head->val;
        struct node *temp = head;
        head = head->next;
        free(temp);
        return value;
    }
}
void print_queue() {
    if (is_empty()) {
        printf("The queue is empty.\n");
        return;
    }

    printf("The queue is (from head to tail): ");
    for (struct node *node = head; node != NULL; node = node->next) {
        printf("%d ", node->val);
    }
    printf("\n");
}

int main() {
    new();
    printf("The initial queue is empty: %d\n", is_empty());
    printf("I now enqueue the values 3, 4 and 2\n");
    enqueue(3);
    enqueue(4);
    enqueue(2);
    print_queue();
    printf("I now dequeue (remove from the head)\n");
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Enqueued value: 10\n");
    enqueue(10);
    print_queue();
    printf("Enqueued value: 20\n");
    enqueue(20);
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    return 0;
}