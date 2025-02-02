#include<stdio.h>
#define SIZE 5  

int enqueue(int queuear[], int *qrear, int *qfront, int qdata)
{
    if((*qrear + 1) % SIZE == *qfront) {  
        return 0; 
    } 
    else {
        if(*qfront == -1)  
            *qfront = 0;
        *qrear = (*qrear + 1) % SIZE;  
        queuear[*qrear] = qdata;
        return 1;
    }
}

// Dequeue function
int dequeue(int queuear[], int *qfront, int *qrear, int *retval)
{
    if(*qfront == -1) {  
        return 0;
    } 
    else {
        *retval = queuear[*qfront];
        if(*qfront == *qrear) {  
            *qfront = *qrear = -1;  
        } 
        else {
            *qfront = (*qfront + 1) % SIZE;  
        }
        return 1;
    }
}

int main() {
    int queue[SIZE];
    int front = -1, rear = -1;
    int status, choice;

    do {
        printf("\n\n1. Store the data in queue.\n");
        printf("2. Delete the data from queue.\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    
        switch(choice) {
            case 1: {
                printf("\nStore data in the queue.\n");
                int dval;
                printf("Enter the data to be stored in the queue: ");
                scanf("%d", &dval);
                
                status = enqueue(queue, &rear, &front, dval);
                if(status == 0) {
                    printf("Queue is full!\n");
                } 
                else {
                    printf("Data enqueued successfully!\n");
                }
                break;
            }
            case 2: {
                printf("Delete the data from the queue.\n");
                int retval = 0;
                status = dequeue(queue, &front, &rear, &retval);
                if(status == 1) {
                    printf("Data deleted successfully from the front of the queue!\n");
                    printf("Deleted data is: %d\n", retval);
                } 
                else {
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
        
    } while(choice != 3);
    
    return 0;
}

