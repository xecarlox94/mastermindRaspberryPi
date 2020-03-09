

struct Row
{
    short int colour;
};



struct Mastermind
{
    struct Row secret;

    struct Row * guesses;
};