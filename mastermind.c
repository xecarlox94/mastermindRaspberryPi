#include "mastermind.h"



int coloursRightPos(struct Row * guess)
{
    struct Row * scrt = mastermind->secret;
    int clrsRightPos = 0;

    if(guess->colours[0] == scrt->colours[0])
    {
        clrsRightPos++;
    }
    else if(guess->colours[1] == scrt->colours[1])
    {
        clrsRightPos++;
    }
    else if(guess->colours[2] == scrt->colours[2])
    {
        clrsRightPos++;
    };

    return clrsRightPos;
};

int coloursWrongPos(struct Row * guess)
{
    struct Row * scrt = mastermind->secret;
    int clrsWrongPos = 0;

    if(guess->colours[0] == scrt->colours[0])
    {
        clrsWrongPos++;
    }
    else if(guess->colours[1] == scrt->colours[1])
    {
        clrsWrongPos++;
    }
    else if(guess->colours[2] == scrt->colours[2])
    {
        clrsWrongPos++;
    };
    
    return clrsWrongPos;
};


void writeRow(struct Row * row, int colours[3])
{
    row->colours[0] = colours[0];
    row->colours[1] = colours[1];
    row->colours[2] = colours[2];
};