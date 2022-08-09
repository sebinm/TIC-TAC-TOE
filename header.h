#ifndef _NONAME_
#define _NONAME_

#define TRUE 1
#define FALSE 0

void resetBoard();

void Board();

int proveYorN(char prove);

void ErrorScenario();

int checkFreeSpaces();

void playerMove();

void computerMove();

char checkWinner();

void printWinner(char winner);

#endif