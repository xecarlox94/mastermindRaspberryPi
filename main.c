#include "main.h"



int main(int argc, char ** argv)
{
	
	int fd, gpio;
	int * timer;
	
	fd = openf();
	
	gpio = mgpio(fd);
	
	timer = mtimer(fd);
	
	startGame();
    printf("secret: %d %d %d\n", mastermind->secret->colours[0], mastermind->secret->colours[1], mastermind->secret->colours[2]);
    
    
    printf("size of int: %d, \t size of int32_t: %d", sizeof(int), sizeof(uint32_t) );
    
    bool win = false;
    int i = 0;
    
    fsel(gpio, 19, 0);
	fsel(gpio, 13, 1);
	fsel(gpio, 5, 1);

    while ( i < 3 )
    {
        
        int colours[3], clrsRighPos, clrsWrongPos,j = 0;
        
        printf("\n\nGuess %lu: ", i + 1);
        
        
        while ( j < 3 )
        {
			int ts  = *(timer + 1);
			int timeout = TIMEOUT * 5, cur, t;
			
			short guess = 0;
			while ( (cur = *(timer+1)) - ts < timeout)
			{
				int val = flev(gpio,19);
				
				if ( val ) guess++;
				
				t = *(timer + 1);
				while ( (cur = *(timer+1)) - t < (timeout / 10)) {}
			}
			guess %= 3;
			guess ++;
			
			// assign color to guess
			colours[j] = guess;
			
			
			// red blink
			// greeen blinks the ammount of times
			bool greenOn = false;
			
			fset(gpio,5,1);
			
			ts  = *(timer + 1);
			while ( (cur = *(timer + 1)) - ts < timeout)
			{
				
				
				t = *(timer + 1);
				while ( (cur = *(timer+1)) - t < (timeout / 6)) {}
				
				if ( guess > 0 )
				{
					if ( !greenOn )
					{
						fset(gpio,13,1);
					}
					else 
					{
						fclr(gpio,13);
						guess--;
					}
				}
			}
			
			fclr(gpio,13);
			fclr(gpio,5);
			j++;
		}
		
        writeRow(&mastermind->guesses[i], colours);

        //printf("\ncurrent guess: %d %d %d", mastermind->guesses[i].colours[0], mastermind->guesses[i].colours[1], mastermind->guesses[i].colours[2]);
                
        
        clrsRighPos = coloursRightPos(&mastermind->guesses[i]);
        
        
        clrsWrongPos = coloursWrongPos(&mastermind->guesses[i]);
        
        
        // calculate amount of colours in right position
        printf("\nValues in correct position: %d\n", clrsRighPos);

        // calculate amount of colours in wrong position
        printf("\nValues in wrong position: %d\n", clrsWrongPos);

        // add guess to mastermind guesses array
        
        i++;

        if ( clrsRighPos == 3 && clrsWrongPos == 0 )
        {
            win = true;
            break;
        }

        // if guess is correct, finish the game
        // guess is correct if colours right position amount is 3
        // and wrong position amount is 0
    }
    
    
	fclr(gpio,13);
	fclr(gpio,5);


    if ( win )
    {
        printf("YOU WON\nGame finished in %d moves\n", i);
    } 
    else
    {
        printf("YOU LOST\nGame finished in %d moves\n", i);
    }
    


    // create function to print row, perhaps
    
    
    
    
	
	closef(fd);


    return 0;
}
