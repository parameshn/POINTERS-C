/*If we underestimate the size, we are forced to either recompile the application
with a larger size or to take other approaches. If we overestimate the size, then we will
waste space. The ability to dynamically allocate memory also helps when dealing with
data structures using a variable number of elements, such as a linked list or a queue.*/
/*The basic steps used for dynamic memory allocation in C are:
1. Use a malloc type function to allocate memory
2. Use this memory to support the application
3. Deallocate the memory using the free function
*/

#include <stdio.h>
main()
{
    /*While there are some minor variations to this approach, this is the most common tech‐
nique. In the following example, we allocate memory for an integer using the malloc
function. The pointer assigns five to the allocated memory, and then the memory is
released using the free function:
*/

    int *pi = (int *)malloc(sizeof(int));
    *pi = 5;
    printf("*pi: %d\n", *pi);
    free(pi);

    // When this sequence is executed, it will display the number 5.
}