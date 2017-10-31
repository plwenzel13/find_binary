/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

// bool search(int value, int values[], int n);
// void sort(int values[], int n);
// int main()
// {
    
// }
bool binary_search(int value, int values[], int min, int max)
{
    int mid = (min + max) / 2;

    

    if (max > min)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    //printf("min: %i, max: %i, mid: %i, value; %i\n", min, max, mid, values[mid]);
    // base case
    // cutting array down to the size of 1 (number of things I'm looking at)
    if (min == max)
    {
        // check to see if it is our number
        if (values[mid] == value)
        {
            // return true
            return 1;  
        }
        else
        {
            return 0;
        }
    }
    // not base case, cutting in half    
    else 
    {
        // asking for number at the mid point is it grater than value?
        if (value <= values[mid])
        {
           // search right side
           // forget middle number and all to the left
           return binary_search(value, values, min, mid - 1);
        }
        
        else
        {
            // search right side
            // forget middle number and all to the left
            return binary_search(value, values, mid + 1, max);
        }
    }
    return 0;
}




/**
 * Returns true if value is in array of n values, else false.
 */
// value I'm looking for, collection of values to look in, number of things inside the colleciton
bool search(int value, int values[], int n)
{
    //if not in array, return 0
    for (int i = 0; i <= n; i++)
    {
        if (values[i] == value)     /* if required element found */
        {
            return binary_search (value, values, 0, n + 1);
        }
    
    } 
    return false;

}


/**
 * Sorts array of n values.
 */
 //bubble sort
void sort(int values[], int n)
{
    int swaps;
    do
    {
        swaps = 0;
        for(int i = 0; i < n; i++)
        {
            if(values[i] > values[i + 1])
            {
                int temp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = temp;
                swaps++;
            }
        }
    }
    while(swaps != 0);
    return;
}