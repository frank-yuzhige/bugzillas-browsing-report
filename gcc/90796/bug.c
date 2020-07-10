/**
 * For x86-64 gcc 9.2:
 *  $ gcc -O0 bug.c
 *  $ ./a.out 
 *  b[0] = 0
 *  b[0] = 9
 *  b[0] = 9
 *  ...
 *  b[0] = 9
 * 
 *  $ gcc -O3 bug.c
 *  $ ./a.out 
 *  b[0] = 0
 *  b[0] = 0
 *  b[0] = 0
 *  ...
 *  b[0] = 0
 * 
 *  This bug was introduced in x86-64 gcc 8.1, fixed in x86-64 gcc 9.3
 */

#include <stdio.h>
unsigned b[11];
unsigned c;
int d, e, f;
char en;
int main() {
  for (; e < 100; e += 3) {
    printf("b[0] = %u\n", b[0]);
    for (; c < 9; c++)
      for (d = 2; d < 11; d++) {
        f = b[c + 2] ^ 9;
        b[c] = f;
      }
  }
}