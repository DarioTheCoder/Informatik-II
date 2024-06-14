#include <stdio.h>
#include <stdlib.h> //important for malloc
#include <stdbool.h>


#define max 10
int array[10];
int head;
int tail;

void new(){
    head = 0;
    tail = 0;
}

void is_empty(){
    return (head==tail);
}

int dequeue(){
    if (is_empty){
        return -1;
    }
    int temp = array[head];
    head = (head + 1) % max;
    return temp;
}

void enqueue(x){
    int next_tail = (tail + 1) % max;
    if (next_tail == head){
        return -1;
    }
    array[tail] = x;
    tail = next_tail;
}