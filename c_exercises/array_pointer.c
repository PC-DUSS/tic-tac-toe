/* Author: Pierre-Charles Dussault
 * Date: June 22, 2021
 *
 * How to work with arrays and their pointers.
 * */

#include <stdio.h>

int main(void)
{
    int somenumbers[5];
    int *ptr;
    ptr = somenumbers; // Same as: ptr = &somenumbers[0];
    int v = 2;

    for(; ptr <= &somenumbers[4]; ptr++)
    {
        *ptr = v;
        v *= 2;
    }

    for(ptr = &somenumbers[0]; ptr <= &somenumbers[4]; ptr++)
    {
        printf("Address: %x value: %d\n", ptr, *ptr);
    }

    return 0;
}
