
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


struct Row
{
    short int colours[3];
};



struct Mastermind
{
    struct Row * secret;

    struct Row * guesses;
} * mastermind;


void writeRow(struct Row * row, int colours[3]);

int coloursRightPos(struct Row * guess);

int coloursWrongPos(struct Row * guess);


void startGame();
