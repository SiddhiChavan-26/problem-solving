#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* BSTInsert(struct Node* root, int key) {

    if (root == NULL) {
        return createNode(key);
    }
    
    if (key < root->key) {
        root->left = BSTInsert(root->left, key);
    }
    
    else if (key > root->key) {
        root->right = BSTInsert(root->right, key);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

int main() {
	int i;
    struct Node* root = NULL;
    int elements[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(elements) / sizeof(elements[0]);

    for (i = 0; i < n; i++) {
        root = BSTInsert(root, elements[i]);
    }

    printf("In-order Traversal:\n");
    inorder(root);

    printf("\nPre-order Traversal:\n");
    preorder(root);

    printf("\nPost-order Traversal:\n");
    postorder(root);

    return 0;
}

