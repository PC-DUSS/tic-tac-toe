
/*
AUTHOR: PIERRE-CHARLES DUSSAULT
DATE: 2018/02/03
ABOUT:
This is a tic tac toe games where 2 players play against each other by picking the number of the field
that they wish to replace with their attributed symbol (O or X).
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


// Constants
#define PLAYER_1 1
#define PLAYER_2 2


// Function declarations
int checkIfWin(char table[]);
void displayBoard(char table[]);
void turnToPlay(char table[], int player);


int main(void) {
	int turn = 0;
	int winner;
	int someoneWins;
	char matrix[9] = {
		'1','2','3',
		'4','5','6',
		'7','8','9' };

	displayBoard(matrix);

	// Pattern for the first 4 rotations (the first 8 total turns)
	do {
		turnToPlay(matrix, PLAYER_1);
		displayBoard(matrix);
		someoneWins = checkIfWin(matrix);
		if (someoneWins == 1) {
			winner = 1;
			break;
		}

		turnToPlay(matrix, PLAYER_2);
		displayBoard(matrix);
		someoneWins = checkIfWin(matrix);
		if (someoneWins == 1) {
			winner = 2;
			break;
		}

		turn++;
		// Do this for the first 4 turns if no one wins
	} while (turn < 4 && someoneWins == 0);

	if (someoneWins == 1) {
		printf("\nPlayer %d wins. End of match\n", winner);
		getchar();
	} else {
		// Do one more turn, for player 1 only (the last available spot on the
		// grid)
		turnToPlay(matrix, PLAYER_1);
		displayBoard(matrix);
		someoneWins = checkIfWin(matrix);

		if (someoneWins == 1) {
			winner = 1;
			printf("\nPlayer %d wins. End of match\n", winner);
			getchar();
		} else {
			printf("Stalemate! Please enter any key to end the match");
			getchar();
		}
	}

	printf("Press ENTER to continue");
	getchar();
	return EXIT_SUCCESS;
}

void displayBoard(char table[]) {

	printf("\n\n %c | %c | %c\n ", table[0], table[1], table[2]);
	printf("--|---|--\n");
	printf(" %c | %c | %c\n ", table[3], table[4], table[5]);
	printf("--|---|--\n");
	printf(" %c | %c | %c\n ", table[6], table[7], table[8]);

}

int checkIfWin(char table[]) {
	int someoneWins = 0;
	if (
	    (table[0] == table[1] && table[1] == table[2]) //Full row win condition
	 || (table[3] == table[4] && table[4] == table[5])
	 || (table[6] == table[7] && table[7] == table[8])
	) {
		someoneWins = 1;
	} else if (
			(table[0] == table[3] && table[3] == table[6]) //Full column win condition
	 || (table[1] == table[4] && table[4] == table[7])
	 || (table[2] == table[5] && table[5] == table[8])
	) {
		someoneWins = 1;
	} else if (
			(table[0] == table[4] && table[4] == table[8]) //Full diagonal win condition
	 || (table[2] == table[4] && table[4] == table[6])
	) {
		someoneWins = 1;
	}

	return someoneWins;
}

void turnToPlay(char table[], int player) {
	char symbol;
	int field;

	//Determine what symbol to use as filler depending on who's turn it is
	if (player == 1)
		symbol = 'X';
	else
		symbol = 'O';

	//Ask the player which field he wants to fill with his symbol (X or O)
	printf("\nPlayer %d's turn!\nPlease select the number of the field that you wish to replace with %c \n", player, symbol);
	// Keep asking until the player selects a valid field
	do {
		scanf("%d", &field);
		if (field<1 || field>9)
			printf("\nField invalid. Player %d, please choose a valid field\n", player);
	} while (field<1 || field>9);

	//Replace the corresponding field with the player's symbol
	table[field - 1] = symbol;
}
