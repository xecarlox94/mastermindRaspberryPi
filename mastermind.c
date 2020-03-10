#include "mastermind.h"
#include <stddef.h>
#include <stdio.h>



int coloursRightPos(struct Row * guess)
{
    struct Row * scrt = mastermind->secret;
    int clrsRightPos = 0;

    if( guess->colours[0] == scrt->colours[0] ) clrsRightPos++;
    
    if( guess->colours[1] == scrt->colours[1] ) clrsRightPos++;
    
    if( guess->colours[2] == scrt->colours[2] ) clrsRightPos++;

    return clrsRightPos;
};

int coloursWrongPos(struct Row * guess)
{
    struct Row * scrt = mastermind->secret;
    int clrsWrongPos = 0;

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            

            if ( i == j ) continue;

            printf("\nguess (%d): %d, secret (%d): %d", j, guess->colours[j], i, scrt->colours[i]);
            if ( guess->colours[j] == scrt->colours[i] )
            {
                printf("\nwrong position");
                clrsWrongPos++;
                break;
            }
        }
    }
    
    return clrsWrongPos;
};


void writeRow(struct Row * row, int colours[3])
{
    row->colours[0] = colours[0];
    row->colours[1] = colours[1];
    row->colours[2] = colours[2];
};