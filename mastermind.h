

struct Row
{
    short int colours[3];
};



struct Mastermind
{
    struct Row * secret;

    struct Row * guesses;
};


void writeRow(struct Row * row, int colours[3]);

int coloursRightPos();

int coloursWrongPos();