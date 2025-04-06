#include<stdio.h>
#include<stdlib.h>
//structure declaration
struct node
{
	int data;
	struct node *next;
};
//node create
struct node *createNode(){
	struct node *t;
	t = (struct node *)malloc(sizeof(struct node));
	return t;
}

void initNode(struct node *nn){
	int val;
	printf("\nEnter value to be stored: ");
	scanf("%d", &val);
	nn -> data = val;
	nn -> next = NULL;
}
//attach begin
int attachBegin(struct node **hptr, struct node *nn){
	struct node *fnode;
	if(*hptr == NULL){
		*hptr = nn;
		return 1;
	}
	else{
		nn -> next = *hptr;
		*hptr = nn;
		return 1;
	}
}
int main(){
	int status;
	int choice;
	struct node *head = NULL;
	struct node *tmp;
	//tmp = malloc(sizeof(struct node));
    //tmp = createNode();
		//initNode(tmp);

do{
	printf("\n1.Attach node at the beginning\n");
	printf("2.Dettach node from beginning\n");
	printf("3.Traverse the linked list\n");
	printf("4.Search from the linked list\n");
	printf("5.Attach node at the end\n");
	printf("6.Dettach node from the end\n");
	printf("7.Attach node at the middle\n");
	printf("8.Dettach node from the middle\n");
	printf("9.Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:{
			printf("\nAttach node at the beginning");
			tmp = malloc(sizeof(struct node));
            tmp = createNode();
		    initNode(tmp);
		    status = attachBegin(&head , tmp);
	           if(status == 1){
		         printf("Node attached successfully!!\n");
		    }
			break;
		}
		case 2:{
			printf("\nDettach node from beginning");
			break;
		}
		case 3:{
			printf("\nTraverse the linked list");
			break;
		}
		case 4:{
			printf("\nSearch from the linked list");
			break;
		}
		case 5:{
			printf("\nAttach node at the end");
			break;
		}
		case 6:{
			printf("\nDettach node from the end");
			break;
		}
		case 7:{
			printf("\nAttach node at the middle");
			break;
		}
		case 8:{
			printf("\nDettach node from the middle");
			break;
		}
		case 9:{
			printf("\nExiting.....!");
			break;
		}
	}
	
}while(choice != 9);
		
}
