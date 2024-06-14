#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



struct node{
    int val;
    struct node *next;
};


struct node** new(){
    struct node **newroot = malloc(sizeof(struct node*));
    *newroot = NULL;
    return newroot;
}

bool isempty(struct node** check){
    return (*check == NULL);
}

int pop(struct node** stack){
    if (isempty(stack)){
        return -1;
    }
    int topvalue = (*stack)->val;
    struct node *temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return topvalue;
    }
 
void push(struct node** stack, int x){
    struct node *new = malloc(sizeof(struct node));
    new->val = x;
    new->next = *stack;
    *stack = new;
}

struct node** sort_stack(struct node **stack){
    struct node **all = new();
    struct node **temp = new();
    int x, y;

    while (isempty(stack) == 0){
        push(all, pop(stack));
    }
    push(stack, pop(all));

    while (isempty(all)==0){
        x = pop(all);
        while (isempty(stack)==0){
            y = pop(stack);
            if (x > y){
                push(temp, y);
            } else {
                push(stack, y);
                break;
            }
        }
        push(stack, x);
        while (isempty(temp)==0){
            push(stack, pop(temp));
        }
    }
    return stack;
}



void print_stack_helper(struct node *node) {
    if (node != NULL) {
        print_stack_helper(node->next);
        printf("%d ", node->val);
    }
}

void print_stack(struct node **S, char *name) {
    if (isempty(S) == 0) {
        printf("Stack %s is (from bottom to top): ", name);
        print_stack_helper(*S);
        printf("\n");
    }
    else {
        printf("The stack %s is empty.\n", name);
    }
}

int main() {
    struct node **S = new();
    push(S, 1);
    push(S, 3);
    push(S, 2);
    push(S, 4);
    print_stack(S, "S");
    S = sort_stack(S);
    print_stack(S, "S");
    return 0;
}