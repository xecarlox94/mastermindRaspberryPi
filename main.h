#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mastermind.h"
#include <stdbool.h>





/*

gcc -c -o as/mapm.o as/mapm.s
gcc -c -o as/openf.o as/openf.s
gcc -c -o as/closef.o as/closef.s

as -c -o as/aux/fclr.o as/aux/fclr.s
as -c -o as/aux/flev.o as/aux/flev.s
as -c -o as/aux/fsel.o as/aux/fsel.s
as -c -o as/aux/fset.o as/aux/fset.s

gcc -c -o mastermind.o mastermind.c -std=c99

gcc -c -o main.o main.c

gcc -o mastermind main.o mastermind.o as/aux/fset.o as/aux/fsel.o as/aux/flev.o as/aux/fclr.o as/closef.o as/openf.o as/mapm.o

*/




extern int openf(void);

extern void closef(int fd);

extern int mapm(int fd);

extern void fsel(int gpio, int pin, int mode);

extern void fset(int gpio, int pin, int bitValue);

extern void fclr(int gpio, int pin);

extern int flev(int gpio, int pin);