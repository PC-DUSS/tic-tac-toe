/* Author: Pierre-Charles Dussault
 * Date: June 22, 2021
 *
 * Scenarios of how to handle manipulation of arrays.
 * 1) Modify the state of an array inside of some scope (here in main()).
 * 2) Return a dynamically allocated block of memory
 * */


#include <stdio.h>
#include <stdlib.h>


void ask_for_input(char* input)
{
    // Modify a passed array. This is the best practice in most cases.

    printf("Please enter your input:\n>>");
    scanf("%s", &input[0]); // Begin storing the string at the starting address of the input array
}

char* return_input()
{
    // Dynamically allocate memory to create and then return an array. Avoid doing this.
    // DON'T FORGET TO FREE THE MEMORY AFTERWARDS (with 'free()' ).

    char* input = malloc(100 * sizeof(char)); // Pointer to the start of a memory block of size = 100 * sizeof(char).
    printf("Please enter your input:\n>>");
    scanf("%s", &input[0]);

    return &input[0];
}

int main(void)
{
    // Using the safe way.
    char user_input[100]; // Remember that the array's variable name is a pointer to its starting address.
    ask_for_input(&user_input[0]);
    printf("Here is your input:\n%s\n\n", user_input);

    // Using the dangerous dynamic way.
    char* returned_input = return_input();
    printf("Here is your returned input:\n%s\n\n", &returned_input[0]);

    // Now, let's print the length of each array.
    size_t len_user_input = sizeof(user_input) / sizeof(user_input[0]);

    // GOTCHA! You cannot return the length of dynamically allocated memory. You need to store it somewhere yourself in your program.
    // This would not work...
    //size_t len_returned_input = sizeof(returned_input) / sizeof(returned_input[0]);

    printf("len of safe: %zu\n", len_user_input);

    free(returned_input);
    return EXIT_SUCCESS;
}
