#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Enqueue function
int enqueue(struct Node **rear, struct Node **front, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        return 0; 
    }

    newNode->data = value;
    newNode->next = NULL;

    if (*front == NULL) {
        *front = newNode;
        *rear = newNode;
        (*rear)->next = *front; 
    } else {
        (*rear)->next = newNode; 
        *rear = newNode;         
        (*rear)->next = *front;  
    }
    
    return 1;
}

// Dequeue function
int dequeue(struct Node **front, struct Node **rear, int *retval) {
    if (*front == NULL) {
        return 0;
    }

    struct Node *temp = *front;
    *retval = temp->data;

    if (*front == *rear) {
        *front = *rear = NULL;
    } else {
        *front = (*front)->next;   
        (*rear)->next = *front;    
    }

    free(temp);
    return 1;
}

int main() {
    struct Node *front = NULL, *rear = NULL;
    int choice, status;

    do {
        printf("\n\n1. Store data in the queue.\n");
        printf("2. Delete data from the queue.\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("Store data in the queue.\n");
                int dval;
                printf("Enter the data to be stored in the queue: ");
                scanf("%d", &dval);

                status = enqueue(&rear, &front, dval);
                if (status == 0) {
                    printf("Memory allocation failed!\n");
                } else {
                    printf("Data enqueued successfully!\n");
                }
                break;
            }
            case 2: {
                printf("Delete the data from the queue.\n");
                int retval = 0;
                status = dequeue(&front, &rear, &retval);
                if (status == 1) {
                    printf("Data deleted successfully from the front of the queue!\n");
                    printf("Deleted data is: %d\n", retval);
                } else {
                    printf("Queue is empty, cannot delete!\n");
                }
                break;
            }
            case 3: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Please enter a valid number.\n");
            }
        }

    } while (choice != 3);

    return 0;
}

