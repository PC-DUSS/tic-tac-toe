/* Author: Pierre-Charles Dussault
 * Date: June 22, 2021
 *
 * Basic use of pointers.
 * */

#include <stdio.h>


int main(void)
{
    int x = 7;
    printf("%d\n", x);

    x = 15;
    printf("%d\n", x);

    int* aptr = &x;
    printf("aptr is %x\n", aptr);
  
    printf("x is %d\n", *aptr);

    *aptr = 36;
    printf("aptr is %x\n", aptr);
    printf("x is %d(variable) is %d(dereferenced pointer)\n", x, *aptr);

    return 0;
}
