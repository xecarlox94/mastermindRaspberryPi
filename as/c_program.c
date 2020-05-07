
#include <stdio.h>
#include <stdlib.h>


/*
 * gcc -c -o mgpio.o mgpio.s
 * gcc -c -o mtimer.o mtimer.s
 * gcc -c -o openf.o openf.s
 * gcc -c -o closef.o closef.s
 * 
 * as -c -o aux/fclr.o aux/fclr.s
 * as -c -o aux/flev.o aux/flev.s
 * as -c -o aux/fsel.o aux/fsel.s
 * as -c -o aux/fset.o aux/fset.s
 * 
 * gcc -c -o c_program.o c_program.c
 * 
 * gcc -o program c_program.o aux/fset.o aux/fsel.o aux/flev.o aux/fclr.o closef.o openf.o mgpio.o
 * 
*/


extern int openf(void);

extern void closef(int fd);

extern int mgpio(int fd);

extern void fsel(int gpio, int pin, int mode);

extern void fset(int gpio, int pin, int bitValue);

extern void fclr(int gpio, int pin);

extern int flev(int gpio, int pin);





// DELETE
#include <time.h> 
void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
}




int main(void)
{
	int fd;
	
	//static volatile uint32_t *gpio;
	int gpio;
	
	
	fd = openf();
	
	
	//printf("file handler: %d\n", fd);
	
	
	gpio = mgpio(fd);
	
	
	//printf("gpio address: %d\n", (int) gpio);
	
	
	fsel(gpio, 19, 0);
	fsel(gpio, 13, 1);
	fsel(gpio, 5, 1);
	
	
	//fclr(gpio,13);
	//fclr(gpio,5);
	
	fset(gpio,13,1);
	fset(gpio,5,1);
	
	delay(500);
	printf("start\n");
	
	int i = 0;
	while (i <= 3)
	{
		int value = flev(gpio,19);
		if (value){
			i++;
			
			if (i % 2 == 0)
			{
				fset(gpio,13,1);
				fset(gpio,5,1);
			} else 
			{
				fclr(gpio,13);
				fclr(gpio,5);
			}
		}
		delay(100);
	}
	printf("\n");
	
	
	
	printf("finish\n");
	
	fclr(gpio,13);
	fclr(gpio,5);
	
	closef(fd);
	
}
