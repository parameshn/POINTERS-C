#include <stdio.h>
#include <stdlib.h>
main()
{

    /*Using the calloc Function
    The calloc function will allocate and clear memory at the same time.Its prototype follows:*/

    void *calloc(size_t numElements, size_t elementSize); // To clear memory means its contents are set to all binary zeros.

    /*The function will allocate memory determined by the product of the numElements and
elementSize parameters. A pointer is returned to the first byte of memory. If the func‐
tion is unable to allocate memory, NULL is returned. Originally, this function was used
to aid in the allocation of memory for arrays.
If either numElements or elementSize is zero, then a null pointer may be returned. If
calloc is unable to allocate memory, a null pointer is returned and the global variable,
errno, is set to ENOMEM (out of memory). This is a POSIX error code and may not be
available on all systems.
Consider the following example where pi is allocated a total of 20 bytes, all containing
zeros:*/

    int *pi = calloc(5, sizeof(int));

    /*Instead of using calloc, the malloc function along with the memset function can be
used to achieve the same results, as shown below*/

    int *pi = malloc(5 * sizeof(int));
    memset(pi, 0, 5 * sizeof(int));

    /*The memset function will fill a block with a value. The first argument is
a pointer to the buffer to fill. The second is the value used to fill the
buffer, and the last argument is the number of bytes to be set*/

    // Use calloc when memory needs to be zeroed out. However, the execution of calloc may take longer than using malloc.
}
