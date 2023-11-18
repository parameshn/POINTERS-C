// Writing your own free function

/*Several issues surround the free function that encourage some programmers to create
their own version of this function. The free function does not check the pointer passed
to see whether it is NULL and does not set the pointer to NULL before it returns. Setting
a pointer to NULL after freeing is a good practice.
Given the foundation provided in the section “Passing and Returning by Pointer” on
page 61, the following illustrates one way of implementing your own free function that
assigns a NULL value to the pointer. It requires that we use a pointer to a pointer:*/
#include <stdlib.h>
#include <stdio.h>
void saferFree(void **pp)
{
    if (pp != NULL && *pp != NULL)
    {
        free(*pp);
        *pp = NULL;
    }
}

/*The saferFree function calls the free function that actually deallocates the memory.
Its parameter is declared as a pointer to a pointer to void. Using a pointer to a pointer
allows us to modify the pointer passed. Using the void type allows all types of pointers
to be passed. However, we get a warning if we do not explicitly cast the pointer type to
void when we call the function. If we explicitly perform the cast, then the warning goes
away.
The safeFree macro, shown below, calls the saferFree function with this cast and uses
the address-of operator, thus alleviating the need for a function’s user to perform the
cast and to pass the pointer’s address.
*/
#define safeFree(p) saferFree((void **)&(p))

// The next sequence illustrates the use of this macro:
int main()
{
    int *pi;
    pi = (int *)malloc(sizeof(int));
    *pi = 5;
    printf("Before: %p\n", pi);
    safeFree(pi);
    printf("After: %p\n", pi);
    safeFree(pi);
    return (EXIT_SUCCESS);
}

/*Assuming malloc returned memory from address 1000, the output of this sequence will
be 1000 and then 0. The second use of the safeFree macro with a NULL value does not
terminate the application, as the function detects and ignores it.
*/