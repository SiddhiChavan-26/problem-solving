#include <stdio.h>
#include <string.h>

#define ROWS 13
#define COLS 6

void initializeSeats(int seats[ROWS][COLS]) {
	int i,j;
    for ( i = 0; i < ROWS; i++) {
        for ( j = 0; j < COLS; j++) {
            seats[i][j] = 0; // 0 means the seat is unoccupied
        }
    }
}

void printSeatingArrangement(int seats[ROWS][COLS]) {
    printf("\nSeating Arrangement:\n");
		int i,j;
    for ( i = 0; i < ROWS; i++) {
        for ( j = 0; j < COLS; j++) {
            printf("%d ", seats[i][j]);
        }
        printf("\n");
    }
}

void bookSeat(int seats[ROWS][COLS], int row, int col) {
    if (seats[row][col] == 0) {
        seats[row][col] = 1; // 1 means the seat is booked
        printf("Seat booked successfully.\n");
    } else {
        printf("Seat is already booked. Please choose a different seat.\n");
    }
}

void countBookedSeats(int seats[ROWS][COLS]) {
    int firstClass = 0, businessClass = 0, economyClass = 0;
		int i,j;
    for ( i = 0; i < ROWS; i++) {
        for ( j = 0; j < COLS; j++) {
            if (seats[i][j] == 1) {
                if (i < 2) {
                    firstClass++;
                } else if (i < 7) {
                    businessClass++;
                } else {
                    economyClass++;
                }
            }
        }
    }

    printf("\nBooked Seats Report:\n");
    printf("First Class: %d\n", firstClass);
    printf("Business Class: %d\n", businessClass);
    printf("Economy Class: %d\n", economyClass);
}

int main() {
    int seats[ROWS][COLS];
    initializeSeats(seats);

    int choice;
    do {
        printf("\n1. Book a seat\n");
        printf("2. Show seating arrangement\n");
        printf("3. Show booked seats report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int row, col;
                printf("Enter the row number (1-13): ");
                scanf("%d", &row);
                printf("Enter the seat number (1-6): ");
                scanf("%d", &col);

                if (row < 1 || row > 13 || col < 1 || col > 6) {
                    printf("Invalid seat position.\n");
                } else {
                    bookSeat(seats, row - 1, col - 1);
                }
                break;
            }
            case 2:
                printSeatingArrangement(seats);
                break;
            case 3:
                countBookedSeats(seats);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

