#include<stdio.h>
#include<stdlib.h>
//structure declaration
struct node{
	int data;
	struct node *next;
};
//push function
int push(struct node **tptr, int data){
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	
	if(tmp == NULL){
		return 0;
	}
	else{
		tmp -> data = data;
		tmp -> next = *tptr;
		*tptr = tmp;
		return(1);
	}
}
//pop function
struct node *pop(struct node **tptr){
	struct node *tmp;
	if(*tptr == NULL){
		return NULL;
	}
	else{
		tmp = *tptr;
		*tptr = tmp -> next;
		return (tmp);
	}
}

int main(){
	struct node *top = NULL;
	int choice;
	int status;
	struct node *retnode;
	
	do{
		printf("\n1.Store data in the stack.\n");
		printf("2.Delete the data from the stack.\n");
		printf("3.Exit\n");
		
		printf("Enter your choice:\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:{
				printf("Store the data in the stack.\n");
				int dval;
				printf("Enter the data to be stored in the stack: ");
				scanf("%d",&dval);
				status = push(&top, dval);
				if(status == 1){
					printf("Data placed successfully!!\n");
				}
				else{
					printf("Data could not be placed \n stack overflow.\n");
				}
				break;
			}
			
			case 2:{
				printf("Delete the data from the stack.\n");
				retnode = pop(&top);
				if(retnode == NULL){
					printf("Stack empty!!");
				}
				else{
					printf("Data popped successfully!!\n");
					printf("Popped data: %d\n",retnode -> data);
					free(retnode);
				}
				break;
			}
			
			case 3:{
				printf("Exiting.....!\n");
				break;
			}
			
			default:
				printf("Please enter the valid number.\n");
		}
		
	}while(choice != 3);
	
}
