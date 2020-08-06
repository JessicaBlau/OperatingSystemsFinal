#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>

char globBuf[65536];            /* 1. BSS */
int primes[] = { 2, 3, 5, 7 };  /* 2. data  */

static int square(int x)                   /* 3. text */
{
    int result;                 /* 4. stack */

    result = x * x;
    return result;              /* 5. result is passed from stack to the caller and saved in the stack*/
}

static void doCalc(int val)                 /* 6. text */
{
    printf("The square of %d is %d\n", val, square(val));

    if (val < 1000) {
        int t;                 /* 7. stack */

        t = val * val * val;
        printf("The cube of %d is %d\n", val);
    }
}

int main(int argc, char* argv[])    /* 8. text */
{
    static int key = 9973;      /* 9. data */
    static char mbuf[10240000]; /* 10. BSS */
    char* p;                    /* 11. stack */


    doCalc(key);

    exit(EXIT_SUCCESS);
}