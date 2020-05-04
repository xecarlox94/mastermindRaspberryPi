#include "mastermind.h"
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>



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
        bool isRepeat = false;

        for (size_t k = i - 1; 0 >= k; k--)
        {
            if ( guess->colours[i] == guess->colours[k] ) isRepeat = true;
        }

        if ( isRepeat ) continue;

        for (size_t j = 0; j < 3; j++)
        {
            isRepeat = false;
            

            for (size_t k = j - 1; 0 >= k; k--)
            {
                if ( scrt->colours[j] == scrt->colours[k] ) isRepeat = true;
            }

            if ( isRepeat ) break;

            if ( i == j ) continue;

            if ( scrt->colours[j] == guess->colours[i])
            {
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
