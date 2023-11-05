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
#include <stdlib.h>
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

    /*The malloc function single argument specifies the number of bytes to allocate. If suc‐
cessful, it returns a pointer to memory allocated from the heap. If it fails, it returns a
null pointer*/

    *pi = (int *)malloc(10 * 4);
    *pi = 6;
    printf("*pi: %d\n", *(pi + 1));
    printf("*pi: %d\n", *(pi));
    printf("*pi: %d\n", (pi));

    /**pi = (int *)malloc(10 * 4);: This line allocates memory for an array of 10 integers (4 bytes each) using malloc and stores the pointer to the first element in the variable pi. pi is a pointer to an integer.

*pi = 6;: This line assigns the value 6 to the first element of the integer array, which is equivalent to *(pi + 0).

printf("*pi: %d\n", *(pi + 1));: Here, you are trying to print the value at the second element of the array by using *(pi + 1). However, there are a couple of issues with this:

a. You haven't allocated memory for the array elements beyond the first one. So, accessing *(pi + 1) and trying to print its value is undefined behavior. You've only allocated memory for one integer.

b. The value you assigned to the first element is 6 (*pi = 6;), and you are trying to print the value at the second element, which doesn't exist in your current setup.*/

    /*However, the size of an integer can vary, depending on the memory model used. A
portable approach is to use the sizeof operator. This will return the correct size re‐
gardless of where the program is executing.*/

    /*A common error involving the dereference operator is demonstrated
    below:*/
    int *pi;
    *pi = (int *)malloc(sizeof(int));
    /*The problem is with the lefthand side of the assignment operation. We
    are dereferencing the pointer. This will assign the address returned by
    malloc to the address stored in pi. If this is the first time an assignment
    is made to the pointer, then the address contained in the pointer is
    probably invalid. The correct approach is shown below:*/
    pi = (int *)malloc(sizeof(int));
    free(pi);
    // The dereference operator should not be used in this situation.

    /*The error occurs when you attempt to dereference the uninitialized pointer pi and assign the result of malloc to the address it points to. This will lead to undefined behavior because pi doesn't point to valid memory, and dereferencing it will overwrite whatever memory it currently points to.*/

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*Once memory has been freed, it should not be accessed again. Normally, you would not
intentionally access it after it had been deallocated. However, this can occur accidentally.
The system behaves in an implementation-dependent manner when this happens. A common practice is to always
assign NULL to a freed pointer*/

    /*When memory is allocated, additional information is stored as part of a data structure
    maintained by the heap manager. This information includes, among other things, the
    block’s size, and is typically placed immediately adjacent to the allocated block. If the
    application writes outside of this block of memory, then the data structure can be cor‐
    rupted. This can lead to strange program behavior or corruption of the heap*/

    /*Consider the following code sequence. Memory is allocated for a string, allowing it to
hold up to five characters plus the byte for the NUL termination character. The for loop
writes zeros to each location but does not stop after writing six bytes. The for statement’s
terminal condition requires that it write eight bytes. The zeros being written are binary
zeros and not the ASCII value for the character zero:*/

    char *pc = (char *)malloc(6);
    for (int i = 0; i < 8; i++)
    {
        pc[i] = 0;
    }

    /*extra memory has been allocated at the end of the six-byte string. This
represents the extra memory used by the heap manager to keep track of the memory
allocation. If we write past the end of the string, this extra memory will be corrupted.
The extra memory is shown following the string in this example. However, its actual
placement and its original content depend on the compiler*/
}
