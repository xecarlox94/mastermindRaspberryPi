#include <stdio.h>
#include <stdlib.h>

#include "mastermind.h"

struct Mastermind * mastermind;


int main(int argc, char ** argv)
{
    mastermind = (struct Mastermind *) malloc(sizeof(struct Mastermind));

    mastermind->guesses = (struct Row *) malloc(sizeof(struct Row) * 3);
    mastermind->secret = (struct Row *) malloc(sizeof(struct Row));

    int temp[] = {2,3,1};

    writeRow(mastermind->secret, temp);

    printf("secret 1: %d\n", mastermind->secret->colours[0]);
    printf("secret 2: %d\n", mastermind->secret->colours[1]);
    printf("secret 3: %d\n", mastermind->secret->colours[2]);




    return 0;
}