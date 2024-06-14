#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//a. 


#define max 1000
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

bool push(char x){
    if (t == max){
        return 0;
    }
    array[t] = x;
    t++;
    return 1;
}

bool validate_parenthesis(char *s){
    char lastparent;
    new();
    for (int i=0; s[i] != '\0';i++){
        if (s[i] == '(' || s[i] == '['){
            push(s[i]);
        } else if (s[i] == ')'){
            if (isempty() || pop() != '('){
                return 0;
            }
        } else if (s[i] == ']'){
            if (isempty() || pop() != '['){
                return 0;
            }
        }   
    }
    return isempty();
}

int main() {
    char *s1 = "(())()", *s2 = "(()()))", *s3 = "(()()", *s4 = "[()([])]", *s5 = "([)]";
    printf("sequence: %s - function return: %d\n", s1, validate_parenthesis(s1));
    printf("sequence: %s - function return: %d\n", s2, validate_parenthesis(s2));
    printf("sequence: %s - function return: %d\n", s3, validate_parenthesis(s3));
    printf("sequence: %s - function return: %d\n", s4, validate_parenthesis(s4));
    printf("sequence: %s - function return: %d\n", s5, validate_parenthesis(s5));
    return 0;
}