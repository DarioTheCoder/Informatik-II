#include <stdio.h>
#include <stdlib.h> //important for malloc
#include <stdbool.h>


#define max 20
int array[max];
int head;
int tail;

void new(){
    head = 0;
    tail = 0;
}

bool is_empty(){
    return (head==tail);
}

int dequeue(){
    if (is_empty()){
        return -1;
    }
    int temp = array[head];
    head = (head + 1) % max;
    return temp;
}

int enqueue(int x){
    int next_tail = (tail + 1) % max;
    if (next_tail == head){
        return 0;
    }
    array[tail] = x;
    tail = (tail + 1) % max;
    return 1;
}


void generate(int n){
    int current;
    new();
    enqueue(1);
    for (int i=0; i < n; i++){
        current = dequeue();
        printf("%d\n", current);
        enqueue((3*current +1));
        enqueue(3*current+2);
    }
}



int main() {
    generate(10);
    return 0;
}