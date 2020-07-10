/**
 * For x86-64 gcc 10.1:
 *  $ g++ -O0 small.cpp
 *  $ ./a.out 
 *  42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 42 0 0 0 
 * 
 *  $ g++ -O3 small.cpp
 *  $ ./a.out 
 *  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 42 0 0 0
 * 
 *  Further investigation shows that the bug was introduced between x86-64 gcc 7.5 and x86-64 gcc 8.1.
 */

#include <stdio.h>

unsigned short arr_26 [20];
signed char arr_25 [2000];

unsigned char b;

int c(int d, int f) { return d > f ? d : f; }

void test() { 
    for (char e = c(b, 241) + 15; e < 17; e += 1)
        arr_26[e] = 42;
}

int main() {
    test();
    for (size_t i_0 = 0; i_0 < 20; ++i_0)
        printf("%d ", arr_26 [i_0]);
    printf("\n");
}