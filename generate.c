/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // if argument comand line does not have a 2nd and 3rd comand,
    // then repromt the user and quit the program
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Get 2nd command line argument and convert it to an int. call it n.
    int n = atoi(argv[1]);

    // if there are 3 arguments
    // then take the 2nd argument, convert it to an int and randomize the sequence of #'s using srand48
    // else, seed the internal buffer with time(NULL) to change the random vlaue.
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // for i = 0, and i < n, increment i
    // print random number after it is multiplied by the limit
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}