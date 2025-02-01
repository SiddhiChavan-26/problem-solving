#include<stdio.h>
//push function
int push(int star[], int *sttop, int stsize, int data){
	if(*sttop == (stsize - 1)){
		return (0);
	}
	else{
		(*sttop)++;
		star[*sttop] = data;
		return (1);
	}
}
//pop function
int pop(int star[], int *sttop, int *retval){
	int val;
	if(*sttop == -1){
		return (0);
	}
	else{
		val = star[*sttop];
		(*sttop)--;
		*retval = val;
		return (1);
	}
}
int main(){
    int n;
    printf("Enter the value of N:\n");
    scanf("%d",&n);

    int stack[n];
    int top = -1;
    int choice;
    int status;
	
	do{
		printf("\n1.Store the data in stack.\n");
		printf("2.Delete the data from stack.\n");
		printf("3.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:{
				printf("Store data in the stack.\n");
				int dval;
				printf("Enter the data to be stored in the stack: ");
				scanf("%d",&dval);
				status = push(stack, &top, n, dval);
				if(status == 1){
					printf("Data stored successfully at the top of stack!\n");
				}
				else{
					printf("Data could not be stored!\n");
				}
				break;
			} 
			case 2:{
				printf("Delete the data from the stack.\n");
				int retval = 0;
				status = pop(stack, &top, &retval);
				if(status == 1){
					printf("Data deleted successfully from the top of stack!\n");
					printf("Deleted data is :%d\n",retval);
				}
				else{
					printf("Data cannot be deleted!\n");
				}
				break;
			}
			case 3:{
				printf("Exiting.....!!\n");
				break;
			}
			default :
				printf("Please enter valid number.\n");
			
		};
	}while(choice != 3);
    
}
