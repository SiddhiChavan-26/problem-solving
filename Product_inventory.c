#include<stdio.h>
#define MAX_PRODUCT 100

typedef struct{
	int product_id;
	char product_name[50];
	float product_price;
	float gst;
} Product;

Product productList[MAX_PRODUCT];
int product_count = 0;  // Initialize to 0 instead of -1

// shiftDown function
void shiftDown(Product productList[], int spos, int lpos) {
	int cur_pos = lpos;

	while (cur_pos >= spos) {
		productList[cur_pos + 1] = productList[cur_pos];
		cur_pos--;
	}
}

// insert function
int insert(Product new_product, int index, Product productList[], int *product_count) {
	if (*product_count < MAX_PRODUCT) {
		if (index <= *product_count) {
			shiftDown(productList, index, *product_count);
			productList[index] = new_product;
			(*product_count)++;
			return 1;
		} else if (index == *product_count) {
			productList[index] = new_product;
			(*product_count)++;
			return 1;
		} else {
			return 0; // Invalid index
		}
	} else {
		return 0; // List is full
	}
}

//shiftup function
void shiftUp(Product productList[] , int spos, int lpos){
	int cur_pos;
	cur_pos = spos;
	while(cur_pos < lpos){
		productList[cur_pos] = productList[cur_pos + 1];
		cur_pos ++;
	} 
}

//delettion function
int delete(int index , Product productList[] , int *product_count ){
	if(*product_count == -1){
		return 0;
	}
	else{
		if(index == *product_count){
			(*product_count )--;
			return 1;
		}else{
			if(index < *product_count ){
				shiftUp(productList , index , *product_count);
				(*product_count) --;
				return 1;
			}else{
				return 0;
			}
		}
	}
}

//search function
int search (Product productList[] , int product_count , int id){
	int cur_pos ;
		cur_pos = 0;
		while(cur_pos <= product_count){
			if(productList[cur_pos].product_id == id){
				return cur_pos;
			}
			cur_pos ++;
		}
		return -1;

}

//function for traverse the list
void traverse(Product productList[] , int product_count){
	int cur_pos;
	if(product_count >= 0){
		cur_pos = 0;
		
		while(cur_pos < product_count){
			printf("Product ID: %d\t", productList[cur_pos].product_id);
        	printf("Product Name: %s\t", productList[cur_pos].product_name);
        	printf("Product Price: %.2f\t", productList[cur_pos].product_price);
        	printf("Product GST: %.2f\t", productList[cur_pos].gst); 
			cur_pos ++;
			printf("\n");
		}
	}
}

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        Product temp_product;
        while (fscanf(file, "%d %s %f %f", &temp_product.product_id, temp_product.product_name, &temp_product.product_price, &temp_product.gst) != EOF) {
            insert(temp_product, product_count, productList, &product_count);
        }
        fclose(file);
    } else {
        printf("Unable to open file.\n");
    }
}

void write_file(const char *filename) {
	int i;
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        for (i = 0; i < product_count; i++) {
            fprintf(file, "%d %s %.2f %.2f\n", productList[i].product_id, productList[i].product_name, productList[i].product_price, productList[i].gst);
        }
        fclose(file);
    } else {
        printf("Unable to open file.\n");
    }
}



int main() {
	
	read_file("products.txt");
	int choice, status, index ,id;

	do {
		printf("\n\nMenu: \n");
		printf("1. Add product\n");
		printf("2. Delete product\n");
		printf("3. Search product\n");
		printf("4. Display all products\n");
		printf("5. Save all products to file\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:{
				
				printf("\nAdd product to list:\n");

				Product new_product;
				printf("Enter product ID: ");
				scanf("%d", &new_product.product_id);
				printf("Enter Product Name: ");
				scanf("%s", new_product.product_name);
				printf("Enter Product Price: ");
				scanf("%f", &new_product.product_price);
				printf("Enter Product GST: ");
				scanf("%f", &new_product.gst);
				printf("Enter the position where the data should be entered: ");
				scanf("%d", &index);

				status = insert(new_product, index, productList, &product_count);

				if (status) {
					printf("Product inserted in list successfully!!\n");
				} else {
					printf("Insertion of product failed!!\n");
				}
				break;
			}

			case 2:{
				
				printf("\n Delete product:");
				
				printf("\nEnter product ID to delete:");
				scanf("%d", &id);
				
				index = search(productList , product_count , id);
				
				if( index != -1){
					status =  delete(index , productList , &product_count);
					if (status){
						printf("Product deleted successfully!!");
					}
				}else{
					printf("Product not found!");
				}
				
				break;
			}
				
			case 3: {
				printf("\nSearch product: ");
			
				printf("\nEnter product ID to search:");
				scanf("%d",&id);
				
				status = search(productList , product_count , id);
				if(status >= 0){
					printf("Product found at position : %d", status);
				}else{
					printf("Product not found!");
				}
				break;
			}
			case 4: {
				printf("\nDiplay all products: \n");
				traverse(productList , product_count);
				break;
			}

			case 5: {
				printf("Save all products to file");
				write_file("products.txt");
                break;
        	}
            case 6:{
				
            	printf("Exiting...!");
            	break;
            }
            default : {
            	printf("Inavlid choice. Please enter correct number.");
				break;
			}
			}
	} while (choice != 6);

	return 0;
}

