#include <stdio.h>
#include <stdlib.h> //important for malloc
#include <stdbool.h>


// singly linked lists
// mutiple lists
// now wrong was techniclly correct once

struct node {
    int val;
    struct node *next;
};

struct Queue {
    struct node **head, **tail;
};


struct Queue new(){
    struct Queue newqueue;
    newqueue.head = malloc(sizeof(struct node*));
    newqueue.tail = malloc(sizeof(struct node*));
    *(newqueue.head) = *(newqueue.tail) = NULL;
    return newqueue;
}

bool is_empty(struct Queue *queue){
    return (*(queue->head)==NULL && *(queue->tail) ==NULL);
}

void enqueue(struct Queue *q, int x){
    if (is_empty(q)){
        struct node *new = malloc(sizeof(struct node));
        new->val = x ;
        new->next = NULL;
        *(q->head) = new;
        *(q->tail) = new;
    } else {
        struct node *new = malloc(sizeof(struct node));
        new->val = x;
        new->next = NULL;
        (*(q->tail))->next = new;
        *(q->tail) = new;

    }
}

int dequeue(struct Queue *q){
    if (is_empty(q)){
        return -1;
    }
    if (*(q->head) == *(q->tail)){
        int value = (*(q->head))->val;
        free(*(q->head));
        *(q->head) = NULL;
        *(q->tail) = NULL;
        return value;
    } else {
        int value = (*(q->head))->val;
        struct node *temp = *(q->head);
        *(q->head) = (*(q->head))->next;
        free(temp);
        return value;
    }
}

void print_queue(struct Queue q, char *name) {
    if (is_empty(q)) {
        printf("The queue %s is empty.\n", name);
        return;
    }

    printf("The queue %s is (from head to tail): ", name);
    for (struct node *node = *(q.head); node != NULL; node = node->next) {
        printf("%d ", node->val);
    }
    printf("\n");
}

int main() {
    struct Queue q1 = new();
    printf("The queue q1 is empty: %d\n", is_empty(q1));
    printf("I now enqueue the values 3, 4 and 2\n");
    enqueue(q1, 3);
    enqueue(q1, 4);
    enqueue(q1, 2);
    print_queue(q1, "q1");
    printf("I now dequeue (remove from the head)\n");
    printf("Dequeued value: %d\n", dequeue(q1));
    print_queue(q1, "q1");
    printf("Dequeued value: %d\n", dequeue(q1));
    print_queue(q1, "q1");
    printf("Enqueued value: 10\n");
    enqueue(q1, 10);
    print_queue(q1, "q1");
    printf("Enqueued value: 20\n");
    enqueue(q1, 20);
    print_queue(q1, "q1");
    printf("Dequeued value: %d\n", dequeue(q1));
    print_queue(q1, "q1");
    printf("Dequeued value: %d\n", dequeue(q1));
    print_queue(q1, "q1");
    printf("Dequeued value: %d\n", dequeue(q1));
    print_queue(q1, "q1");
    printf("Dequeued value: %d\n", dequeue(q1));

    printf("\nNow I create another queue\n");
    struct Queue q2 = new();
    enqueue(q2, 12);
    enqueue(q2, 7);
    enqueue(q2, 9);
    print_queue(q2, "q2");

    printf("\nNow I transfer one element from q2 to q1:\n");
    enqueue(q1, dequeue(q2));
    print_queue(q1, "q1");
    print_queue(q2, "q2");
    return 0;
}