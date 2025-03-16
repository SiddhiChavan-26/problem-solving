#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50 

void initialize(int tree[]) {
	int i;
    for (i = 0; i < MAX_SIZE; i++) {
        tree[i] = -1; 
    }
}

void BSTInsert(int tree[], int index, int key) {
    if (index >= MAX_SIZE) {
        printf("Index out of bounds.\n");
        return;
    }
    if (tree[index] == -1) {
        tree[index] = key;
    } 
    else if (key < tree[index]) {
        BSTInsert(tree, 2 * index + 1, key);
    } 
    else if (key > tree[index]) {
        BSTInsert(tree, 2 * index + 2, key); 
    }
}

void inorder(int tree[], int index) {
    if (index < MAX_SIZE && tree[index] != -1) {
        inorder(tree, 2 * index + 1); 
        printf("%d ", tree[index]);  
        inorder(tree, 2 * index + 2); 
    }
}

void preorder(int tree[], int index) {
    if (index < MAX_SIZE && tree[index] != -1) {
        printf("%d ", tree[index]);   
        preorder(tree, 2 * index + 1); 
        preorder(tree, 2 * index + 2); 
    }
}

void postorder(int tree[], int index) {
    if (index < MAX_SIZE && tree[index] != -1) {
        postorder(tree, 2 * index + 1);
        postorder(tree, 2 * index + 2);
        printf("%d ", tree[index]);    
    }
}

int main() {
	int i;
    int tree[MAX_SIZE]; 
    initialize(tree);   
    int elements[] = {50, 30, 20, 40, 70, 60, 80}; 
    int n = sizeof(elements) / sizeof(elements[0]);

    for (i = 0; i < n; i++) {
        BSTInsert(tree, 0, elements[i]);
    }

    printf("In-order Traversal:\n");
    inorder(tree, 0); 

    printf("\nPre-order Traversal:\n");
    preorder(tree, 0);

    printf("\nPost-order Traversal:\n");
    postorder(tree, 0);

    return 0;
}

