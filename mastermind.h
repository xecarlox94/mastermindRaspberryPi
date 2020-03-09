

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