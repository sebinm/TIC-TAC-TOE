#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "header.h"

int main(void)
{
   char winner = ' ';
   char response = 'y';
   char trash;
   short int CHECK = TRUE;

    while (proveYorN(response) == 1)
    {
        winner = ' ';
        response = ' ';
        resetBoard();

        while((winner == ' ') && checkFreeSpaces())
        {
            Board();

            playerMove();
            winner = checkWinner();

            if((winner != ' ') || !checkFreeSpaces())
            {
                break;
            }

            computerMove();
            winner = checkWinner();

            if((winner != ' ') || !checkFreeSpaces())
            {
                break;
            }
        }

        Board();
        printWinner(winner);

        response = ' ';

        while(!proveYorN(response) || CHECK)
        {
            CHECK = FALSE;  

            printf("\nWould you like to play again? (y/n): ");
            scanf("%c", &trash);
            scanf("%c", &response);

            if (!proveYorN(response))
            {
                ErrorScenario();
                CHECK = TRUE;
            }
        } 
    }

   printf("Thanks for playing!");

   return 0;
}