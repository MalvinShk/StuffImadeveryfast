#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Function to initialize the field with * (LET THERE BE LIGHT)
void initializeField(char field[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            field[i][j] = '*';
        }
    }
}

// Function to print the field (Printer.exe stoped working)
void printField(char field[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", field[i][j]);
        }
        printf("\n");
    }
}

// Function to move x or + in a random direction (slide to the right, slide to the left, cris cross...)
void move(char field[SIZE][SIZE], int x, int y) {
    int direction = rand() % 4; // 0: up, 1: down, 2: left, 3: right

    if (direction == 0 && x > 0) { // up
        if (field[x - 1][y] == '+') {
            field[x - 1][y] = 'x';
        } else {
            field[x - 1][y] = field[x][y];
        }
        field[x][y] = '*';
    } else if (direction == 1 && x < SIZE - 1) { // down
        if (field[x + 1][y] == '+') {
            field[x + 1][y] = 'x';
        } else {
            field[x + 1][y] = field[x][y];
        }
        field[x][y] = '*';
    } else if (direction == 2 && y > 0) { // left
        if (field[x][y - 1] == '+') {
            field[x][y - 1] = 'x';
        } else {
            field[x][y - 1] = field[x][y];
        }
        field[x][y] = '*';
    } else if (direction == 3 && y < SIZE - 1) { // right
        if (field[x][y + 1] == '+') {
            field[x][y + 1] = 'x';
        } else {
            field[x][y + 1] = field[x][y];
        }
        field[x][y] = '*';
    }
}

// Function to check if 'x's or '+'s are present ("Marco" "Polo" "Marco" "Polo" "Marco" "Polo" "Marco" "Polo" "Marco" "Polo")
int checkPresence(char field[SIZE][SIZE], char character) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (field[i][j] == character) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char field[SIZE][SIZE];

    initializeField(field);

    // Place x's and +´s randomly on the field (RNJESUS BE PRAISED)
    for (int i = 0; i < 10; i++) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (field[x][y] == '*') {
            if (i % 2 == 0) {
                field[x][y] = 'x';
            } else {
                field[x][y] = '+';
            }
        } else {
            i--;
        }
    }

    // Simulate turns until one wins (WITH THE POWER OF FRIENDSHIP)
    int turn;
    for (turn = 0; turn < 100; turn++) { // 100 turns max
        printf("Turn %d:\n", turn + 1);
        printField(field);
        printf("\n");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (field[i][j] == 'x' || field[i][j] == '+') {
                    move(field, i, j);
                }
            }
        }

        // Check for presence of 'x's and '+'s (where you at bby girl?)
        if (!checkPresence(field, 'x')) {
            printf("+'s Win!\n");
            break;
        } else if (!checkPresence(field, '+')) {
            printf("x's Win!\n");
            break;
        }
    }

    if (turn == 100) {
        printf("Game ended in a draw!\n");
    }

    return 0;
}