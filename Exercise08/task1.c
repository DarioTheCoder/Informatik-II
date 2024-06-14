#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};




struct TreeNode* insert(struct TreeNode** root, int val){

    struct TreeNode* new = malloc(sizeof(struct TreeNode));
    new->val = val;
    new->left = NULL;
    new->right = NULL;

    struct TreeNode* parent = NULL;
    struct TreeNode* current = *root;

    while (current != NULL) {
        parent = current;
        if (current->val < val){
            current = current->right;
        } else {
            current = current->left;
        }
    }
    if (parent == NULL){
        *root = new;
    } else if (parent->val < new->val){
        parent->right = new;
    } else if (parent->val > new->val){
        parent->left = new;
    }
    return *root;
}

struct TreeNode* delete(struct TreeNode** root, int val){
    struct TreeNode* parent = NULL;
    struct TreeNode* current = *root;

    while (current != NULL) {
        if (current->val < val){
            parent = current;
            current = current->right;
        } else if (current->val > val){
            parent = current;
            current = current->left;
        } else {break;} }

    if (current == NULL){
        return;
    }

    if (current->left == NULL && current->right == NULL){
        if (current == *root){
            *root = NULL;
        }
        else {
            if (parent->left == current){
                parent->left = NULL; }
            else {
                parent->right = NULL;
            }
            free(current);
        }
        return *root;

    }
    else if (current->left == NULL || current->right == NULL){
        if (current->left == NULL){
            if (parent->left == current){
                parent->left = current->right;
            }
            else {
                parent->right = current->right;
            }
            free(current);
        } 
        else {
            if (parent->left == current){
                parent->left = current->left;
            }
            else {
                parent->right = current->left;
            }
            free(current);
        }
        return *root;

} else {
    struct TreeNode* largestLeft = current->left;
    struct TreeNode* largestparent = current;

    while (largestLeft->right != NULL){
        largestparent = largestLeft;
        largestLeft = largestLeft->right;
    }

    current->val = largestLeft->val;
    if (largestparent->right == largestLeft){
        largestparent->right = largestLeft->left;
    }
    else {
        largestparent->left = largestLeft->left;
    }
    free(largestLeft);
    }
    return *root;
}

void printTreeRecursive(struct TreeNode* root, int level){
    if (root == NULL){
        return;
    }
    if (root->left != NULL){
        printf("%d -- %d : %d\n", root->val, root->left->val, level);
    }
    if (root->right != NULL){
        printf("%d -- %d : %d\n", root->val, root->right->val, level);
    }
    printTreeRecursive(root->left, level+1);
    printTreeRecursive(root->right, level+1);
}


void printTree(struct TreeNode* root){
    printf("Output:\n");
    printTreeRecursive(root, 1);
}

void traverseTree(struct TreeNode* root){
    if (root->left != NULL){
        traverseTree(root->left);
    }
    printf("%d ", root->val);
    if (root->right != NULL){
        traverseTree(root->right);
    }
}

// 4e) stack traversal
struct StackNode {
    struct TreeNode* node;
    struct StackNode *next;
};

void push(struct StackNode** top, struct TreeNode* node){
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->node = node;
    stackNode->next = *top;
    *top = stackNode;
}

struct TreeNode* pop(struct StackNode** top){
    if (*top == NULL){
        return NULL;
    }
    struct TreeNode* node = (*top)->node;
    struct StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
    return node;

}

int isEmpty(struct StackNode* top){
    return (top==NULL);
}


void stack_intraverseTree(struct TreeNode* root){
    if (root == NULL){
        return;
    }
    struct StackNode* stack = NULL;
    struct TreeNode* current = root;

    while (current != NULL || !isEmpty(stack)){
        while (current != NULL){
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        printf("%d ", current->val);
        current = current->right;
    }
}


void stack_traverseTree(struct TreeNode* root){

    printf("Intraversal:\n");
    stack_intraverseTree(root);
    printf("\n");

}


int main() {
   struct TreeNode* root = NULL;
   printf("Inserting: 9, 3, 10, 6, 12, 1, 8 sequentially\n");
   insert(&root, 9);
   insert(&root, 3);
   insert(&root, 10);
   insert(&root, 6);
   insert(&root, 12);
   insert(&root, 1);
   insert(&root, 8);
   printTree(root);
   printf("traverse: \n");
   traverseTree(root);
   printf("Deleting: 23, 1, 3, 9\n");
   delete (&root, 23);   // Case 0: node does not exist
   delete (&root, 1);   // Case 1: node has 0 children
   delete (&root, 3);  // Case 2: node has 1 child
   delete (&root, 9);   // Case 3: node has 2 children
   printTree(root);
   printf("traverse: \n");
   stack_traverseTree(root);
   return 0;
}