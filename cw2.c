#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mastermind.h"
#include <stdbool.h>


/*

gcc -c -o mastermind.o mastermind.c -std=c99

gcc -c -o cw2.o cw2.c -std=c99

gcc -o cw2 cw2.o mastermind.o -std=c99

*/



int main(int argc, char ** argv)
{
    srand(time(0));

    mastermind = (struct Mastermind *) malloc(sizeof(struct Mastermind));

    mastermind->guesses = (struct Row *) malloc(sizeof(struct Row) * 3);
    mastermind->secret = (struct Row *) malloc(sizeof(struct Row));


    // int temp[3];

    // for (size_t i = 0; i < 3; i++)
    // {
    //     temp[i] = rand() % 3;
    // }
    

    int temp[3] = { 2, 1, 3 };
    
    struct Row * scrt = mastermind->secret;

    writeRow(scrt, temp);

    printf("secret: %d %d %d\n", scrt->colours[0], scrt->colours[1], scrt->colours[2]);
    
    bool win = false;
    int attempts =0;

    for (size_t i = 0; i < 1; i++)
    {
        
        int colours[3];

        // ask user for the each colour row values
        // assign coulour to guess pointer

        printf("\n\nGuess%lu: ", i + 1);
        scanf("%d %d %d", &colours[0], &colours[1], &colours[2]);
        // printf("You entered %d, %d, and %d.\n", x[0], x[1], x[2]);
        
        writeRow(&mastermind->guesses[i], colours);

        printf("\ncurrent guess: %d %d %d", mastermind->guesses[i].colours[0], mastermind->guesses[i].colours[1], mastermind->guesses[i].colours[2]);
        
        // calculate amount of colours in right position
        printf("\nValues in correct position: %d\n", coloursRightPos(&mastermind->guesses[i]));

        // calculate amount of colours in wrong position
        printf("\nValues in wrong position: %d\n", coloursWrongPos(&mastermind->guesses[i]));

        // add guess to mastermind guesses array
        
        attempts = i + 1;

        if ( (coloursRightPos(&mastermind->guesses[i]) == 3) && (coloursWrongPos(&mastermind->guesses[i]) == 0) )
        {
            win = true;
        }

        // if guess is correct, finish the game
        // guess is correct if colours right position amount is 3
        // and wrong position amount is 0
    }



    if ( win )
    {
        printf("YOU WON\nGame finished in %d moves\n", attempts);
    } 
    else
    {
        printf("YOU LOST\nGame finished in %d moves\n", attempts);
    }
    


    // create function to print row, perhaps
    




    return 0;
}