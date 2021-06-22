/* Author: Pierre-Charles Dussault
 * Date: June 22, 2021
 *
 * How to use multidimensional arrays in C:
 * 1) Using array type.
 * 2) Using memory blocks with malloc().
 *
 * Shows how to properly free memory after using malloc in a multidimensional
 * way.
 */

#include <stdio.h>
#include <stdlib.h>

// Function Prototypes:
void std_2d_array();
void mem_alloc_2d_array();

// ----------------------------------MAIN--------------------------------------
int main(void)
{
    std_2d_array();
    mem_alloc_2d_array();

    return EXIT_SUCCESS;
}

// --------------------------Function definitions------------------------------
void std_2d_array()
{
    /* Populate a 2D array with values, and then print all those values.*/

    int arr[5][5];
    int x = 2;

    // Go through the array, assigning a value to each index position.
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            arr[i][j] = x;
            // Double the value to assign on the next iteration.
            x *= 2;
        }
    }
    // Go through the array, printing the value held in each index position.
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%d\n", arr[i][j]);
        }
    }
}

void mem_alloc_2d_array()
{
    /* Allocate, and then populate, a 2D memory block with values, then print
     * all those values. Correctly free all of the memory afterwards.
     */

    int m = 5;
    int n = 5;
    int **arr; // of size m * n

    // Allocate a memory block in which each contained byte is another pointer.
    arr = malloc(sizeof(int*) * m);

    // Now create a block of normal integers to be assigned to each pointer.
    for(int i = 0; i < n; i++)
    {
        arr[i] = malloc(sizeof(int) * n);
    }

    // Step through each item in the 2D memory block, assigning a value.
    int x = 2;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = x;
            // Double the value to be assigned on the next iteration.
            x *= 2;
        }
    }

    // Step through the 2D memory block again, this time printing each value.
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d\n", arr[i][j]);
        }

        // Free the memory for each block of integers.
        free(arr[i]);
    }
    
    // Free the memory for the initial block of pointers.
    free(arr);
}
