#include "main.h"



int main(int argc, char ** argv)
{
    srand(time(0));

    mastermind = (struct Mastermind *) malloc(sizeof(struct Mastermind));

    mastermind->guesses = (struct Row *) malloc(sizeof(struct Row) * 3);
    mastermind->secret = (struct Row *) malloc(sizeof(struct Row));
    
    int temp[3], i = 0;
    
    while (i < 3)
    {
		int j = i, rnd = (rand() % 3) + 1;
		
		while ( j >= 0 )
		{
			if ( rnd == temp[j] )
			{
				j = i;
				rnd = (rand() % 3) + 1;;
			}
			j--;
		}
        temp[i] = rnd;
        i++;
    }
    
    struct Row * scrt = mastermind->secret;

    writeRow(scrt, temp);

    printf("secret: %d %d %d\n", scrt->colours[0], scrt->colours[1], scrt->colours[2]);
    
    bool win = false;
    i = 0;

    while ( i < 3 )
    {
        
        int colours[3], clrsRighPos, clrsWrongPos;
        
        
        printf("\n\nGuess %lu: ", i + 1);
        scanf("%d %d %d", &colours[0], &colours[1], &colours[2]);
        
		
        writeRow(&mastermind->guesses[i], colours);

        //printf("\ncurrent guess: %d %d %d", mastermind->guesses[i].colours[0], mastermind->guesses[i].colours[1], mastermind->guesses[i].colours[2]);
                
        
        clrsRighPos = coloursRightPos(&mastermind->guesses[i]);
        
        
        clrsWrongPos = coloursWrongPos(&mastermind->guesses[i]);
        
        
        // calculate amount of colours in right position
        printf("\nValues in correct position: %d\n", clrsRighPos);

        // calculate amount of colours in wrong position
        printf("\nValues in wrong position: %d\n", clrsWrongPos);

        // add guess to mastermind guesses array
        
        i++;

        if ( clrsRighPos == 3 && clrsWrongPos == 0 )
        {
            win = true;
            break;
        }

        // if guess is correct, finish the game
        // guess is correct if colours right position amount is 3
        // and wrong position amount is 0
    }



    if ( win )
    {
        printf("YOU WON\nGame finished in %d moves\n", i);
    } 
    else
    {
        printf("YOU LOST\nGame finished in %d moves\n", i);
    }
    


    // create function to print row, perhaps
    
    



    return 0;
}
