/**
 * For x86-64 clang 10.0.0:
 *  $ clang -std=c11 -Wall -O0 bug.c
 *  $ ./a.out
 *  [no output] 
 * 
 *  $ clang -std=c11 -Wall -O2 bug.c   // or -O3
 *  $ ./a.out
 *  x = 0
 * 
 * This bug comes with clang 3.1 (the version which clang begins to support c11 standard).
 */


#include <stdio.h>

void f(unsigned char x, unsigned char y)
{
    if (y == x)
        printf("x = %u\n", x);
}

int main()
{
    unsigned char x = 1;
    unsigned char y; // no trap representation possible
    (void)&y; // disarm C11, 6.3.2.1p2
    
    f(x, y);
}