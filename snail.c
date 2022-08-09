#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


int main(void)
{
    int depth;
    int sum = 0;
    short int index = 0;

    
    printf("the depth of wall: ");
    scanf("%d", &depth);

    while(++index)
    {   
        sum = sum + 7; // melcul urca 7m pe timpul zilei

        if(sum >= depth)
        {
            break;
        }
        else
        {
            sum = sum - 2;
            // melcul coboara 2 m pe timpul notpii
        }
    }

    printf("\n\nno of days: %d\n", index);

    return 0;   
}