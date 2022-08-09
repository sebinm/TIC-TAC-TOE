#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


#include "header.h"

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';


void resetBoard()
{
    int i, j;

    for(i = 0; i < 3; ++i)
    {
        for(j = 0; j < 3; ++j)
        {
           board[i][j] = ' ';
        }
    }
}

void Board()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkFreeSpaces()
{
   short int freeSpaces = 9;

   for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            if(board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

int proveYorN(char prove)
{
    if(prove == 'y')
    {
        return 1;
    }
    else if (prove == 'n')
    {
        return -1;
    }
    return 0;
}

void ErrorScenario()
{
    printf("\nOps, I think you missed something\n");
    printf("Keep calm, we can try it again:)\n\n");
}

void playerMove()
{
   int x;
   int y;

    do
    {
        printf("Enter row #(1-3): ");
        scanf("%d", &x);
        x--;

        printf("Enter column #(1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' ')
        {
        printf("Invalid move!\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
   } 
   while (board[x][y] != ' ');
}

void computerMove()
{
    // based on rand() funtion included in <stdlib.h>
    srand(time(NULL));
    int x;
    int y;

    if(checkFreeSpaces())
    {
        x = rand() % 3;
        y = rand() % 3;
        
        while (board[x][y] != ' ')
        {
            x = rand() % 3;
            y = rand() % 3;
        } 
      
        board[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' '); 
        // if computer don't have free spaces that's mean a draw
    }
}

char checkWinner()
{
    int i;

    //check rows
    for(i = 0; i < 3; ++i)
    {
        if((board[i][0] == board[i][1]) && (board[i][0] == board[i][2]))
        {
            return board[i][0];
        }
   }
   //check columns
    for(i = 0; i < 3; ++i)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

   //check diagonals
   if((board[0][0] == board[1][1]) && (board[0][0] == board[2][2]))
   {
        return board[0][0];
   }

   if((board[0][2] == board[1][1]) && (board[0][2] == board[2][0]))
   {
        return board[0][2];
   }

   return ' '; // no winner
}

void printWinner(char winner)
{
   if(winner == PLAYER)
   {
        printf("YOU WIN!");
   }
   else if(winner == COMPUTER)
   {
        printf("YOU LOSE!");
   }
   else
   {
        printf("IT'S A DRAW!");
   }
}