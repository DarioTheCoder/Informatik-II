#include <stdio.h>
#include <stdlib.h> //important for malloc
#include <stdbool.h>

// arrays
#define max 20
int array[max];
int t;

void new(){
    t = 0;
}

bool isempty(){
    return (t==0);
}

int pop(){
    if (t==0){
        return -1;}
    t--;
    return array[t];
}

bool push(int x){
    if (t == max){
        return 0;
    }
    array[t] = x;
    t++;
    return 1;
}

// linked lists 

struct node{
    int val;
    struct node *next;
};

struct node *root;

void new(){
    root = NULL;
}

bool isempty(){
    return (root == NULL);
}

int pop(){
    if (isempty() == 1){
        return -1;
    }
    if (root->next == NULL){
        int temp = root->val;
        root = NULL;
        return temp;
    } else {
        int topvalue = root->val;
        struct node *temp = root;
        root = root->next;
        free(temp);
        return topvalue;
    }
}

void push(int x){
    if (isempty){
        root = malloc(sizeof(struct node));
        root->val = x;
        root->next = NULL;
    } 
    else{
        struct node *new = malloc(sizeof(struct node));
        new->val = x;
        new->next = root;
        root = new;
    }
}

// for multiple linked lists 

struct node{
    int val;
    struct node *next;
};


struct node** new(){
    struct node **newroot = malloc(sizeof(struct node));
    *newroot = NULL;
    return newroot;
}

bool isempty(struct node** check){
    return (*check == NULL);
}

int pop(struct node** stack){
    if (isempty() == 1){
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