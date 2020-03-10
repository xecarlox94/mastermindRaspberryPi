#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mastermind.h"



int main(int argc, char ** argv)
{
    srand(time(0));

    mastermind = (struct Mastermind *) malloc(sizeof(struct Mastermind));

    mastermind->guesses = (struct Row *) malloc(sizeof(struct Row) * 3);
    mastermind->secret = (struct Row *) malloc(sizeof(struct Row));


    int temp[3];

    for (size_t i = 0; i < 3; i++)
    {
        temp[i] = rand() % 3;
    }
    

    writeRow(mastermind->secret, temp);

    printf("secret 1: %d\n", mastermind->secret->colours[0]);
    printf("secret 2: %d\n", mastermind->secret->colours[1]);
    printf("secret 3: %d\n", mastermind->secret->colours[2]);


    // create row (guess) pointer

    for (size_t i = 0; i < 3; i++)
    {
        
        int colours[3];

        // ask user for the each colour row values
        // assign coulour to guess pointer

        printf("Guess%d: ", (i + 1));
        scanf("%d %d %d", &colours[0], &colours[1], &colours[2]);
        // printf("You entered %d, %d, and %d.\n", x[0], x[1], x[2]);
        
        printf("COLOURS SELECTED: %d %d %d \n\n", colours[0], colours[1], colours[2]);
        
        writeRow(mastermind->guesses[i]->colours, colours);


        // calculate amount of colours in right position
        // calculate amount of colours in wrong position

        // add guess to mastermind guesses array


        // if guess is correct, finish the game
        // guess is correct if colours right position amount is 3
        // and wrong position amount is 0
    }
    



    // create function to print row, perhaps
    




    return 0;
}