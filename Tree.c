#include <stdio.h>
#include <stdlib.h>

#define MAX 10
struct Stack {
    int items[MAX];
    int top;
};

void createStack(struct Stack* s) {
    s->top = -1;
}
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        s->items[++s->top] = value;
    }
}

int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return s->items[s->top--];
    }
}

void DFS(int A[MAX][MAX], int STR, int N) {
    struct Stack S;
    createStack(&S);
    int i;

    int visited[MAX]; 

    for ( i = 0; i < N; i++) {
        visited[i] = 0;
    }

    push(&S, STR);
    visited[STR] = 1;

    while (!isEmpty(&S)) {
        int V = pop(&S);
        int J;
        printf("Visited node: %d\n", V);

        for ( J = 0; J < N; J++) {
            if (V != J && A[V][J] != 0 && visited[J] == 0) {
                push(&S, J);
                visited[J] = 1; 
            }
        }
    }
}

int main() {
    int N;            
    int A[MAX][MAX]; 
	int i;
	int j;
    printf("Enter the number of nodes: ");
    scanf("%d", &N);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int STR;
    printf("Enter the start node: ");
    scanf("%d", &STR);
    
    DFS(A, STR, N);

    return 0;
}
