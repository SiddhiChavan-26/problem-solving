#include<stdio.h>
//shiftdown function
void shiftDown(int ar[] , int spos, int lpos)
{
	int cur_pos;
	cur_pos = lpos;
	
	while(cur_pos >= spos)
		{
			ar[cur_pos+1] = ar[cur_pos];
			cur_pos --;
		}
}

//insertion function
int insert(int data,int pos,int lar[] , int lsz, int*lpos)
{
	
	if(*lpos == -1 ){
		if(pos == 0){
			lar[pos] = data;
			(*lpos) ++;
			return 1;
		}
		else{
				return 0;
		}
		
	}
	else
	{
		if(*lpos < lsz -1 )
		{
			
			if(pos == *lpos +1)
			{
				lar[pos] = data;
				(*lpos)++;
				return 1;
			}
			else
			{
				if(pos < *lpos){
					shiftDown(lar , pos , *lpos);
					lar[pos] = data;
					(*lpos )++;
					return 1;
				}
				else{
					return 0;
				}
					
			}
		}
	}
}

//shiftup function
void shiftUp(int ar[] , int spos, int lpos){
	int cur_pos;
	cur_pos = spos;
	while(cur_pos <= lpos){
		ar[cur_pos] = ar[cur_pos + 1];
		cur_pos ++;
	} 
}

//delettion function
int delete(int lar[] , int pos, int *lpos){
	if(*lpos == -1){
		return 0;
	}
	else{
		if(pos == *lpos){
			(*lpos )--;
			return 1;
		}else{
			if(pos < *lpos ){
				shiftUp(lar , pos , *lpos);
				(*lpos) --;
				return 1;
			}else{
				return 0;
			}
		}
	}
}

//function for traverse the list
void traverse(int lar[] , int lpos){
	int cur_pos;
	if(lpos != -1){
		cur_pos = 0;
		
		while(cur_pos <= lpos){
			printf("%d\n",lar[cur_pos]);
			cur_pos ++;
		}
	}
}

//search function
int search(int ar[], int lpos, int data_search) {
    int cur_pos;

    if (lpos == -1) {
        return -1; // List is empty
    }

    for (cur_pos = 0; cur_pos <= lpos; cur_pos++) { // Include lpos
        if (ar[cur_pos] == data_search) {
            return cur_pos; // Data found at this position
        }
    }

    return -1; // Data not found
}

int main()
{
	int listar[100] = {0};
	int  size, value, index,last = -1, status, i,choice,data_find;
	
	//read the size of list from user
	printf("Enter the size of list : ");
	scanf("%d",&size);
	
do{
	printf("\n\n1.Insert in the list.");
	printf("\n2.Delete from the list.");
	printf("\n3.Traverse the list.");
	printf("\n4.search from the list.");
	printf("\n5.Exit.");
     //read choice of user
	printf("\nEnter your choice: ");
	scanf("%d",&choice);
	
	switch(choice){
		
		case 1:{
			printf("\n Insertion operation:");
			printf("\n\nEnter the value to be stored in list : ");
			scanf("%d",&value);
			printf("\nEnter position in which data to be stored: ");
			scanf("%d", &index);
	
			status = insert(value , index, listar, size, &last );
			if (status)
			{
				printf("value inserted successfully!!\n");
			}else {
				printf("insertion failed!\n");
			}
	
			printf("Last position: %d\n", last);
			printf("list display:\n");
			for(i = 0; i <= last; i++){
				printf("%d\n",listar[i]);	
			}
				break;
		}
		
		case 2:{
			printf("\n Deletion operation: ");
			printf("\n\nEnter the position from where the data is to be deleted: ");
			scanf("%d", &index);
			printf("The last position is: %d",last);
			
			status = delete(listar , index, &last);
			if(status){
				printf("\nData deleted successfully!!\n");
			}else{
				printf("\nDeletion failed!\n");
			}
			
			printf("The last position after deletion operation is: %d",last);
			break;
		}
		
		case 3:{
			printf("\nTraverse operation:\n");;
			traverse(listar , last);
			break;
		}
		
		case 4: {
			printf("\nSearch operation: ");
			printf("\n\nEnter the data to be search in the list : ");
			scanf("%d", &data_find);
			
			status = search(listar, last, data_find);
			if(status >= 0){
				printf("Data found successfully at position %d\n",status);
			}else{
				printf("\nSearch failed!");
			}
			break;
		}
		
		case 5: {
			printf("Exiting...");
			break;
		}
		
		
		default: printf("Please enter a valid number between 1 to 5.");	
	}
	
	
 }while( choice != 5);
	
}

