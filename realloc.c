/*Using the realloc Function
Periodically, it may be necessary to increase or decrease the amount of memory allocated
to a pointer. This is particularly useful when a variable size array is needed, as will be
demonstrated in Chapter 4. The realloc function will reallocate memory. Its prototype
follows:
*/

#include <stdio.h>
#include <stdlib.h>
main()
{
    void *realloc(void *ptr, size_t size);

    /*The function realloc returns a pointer to a block of memory. The function takes two
arguments. The first is a pointer to the original block, and the second is the requested
size. The reallocated block’s size will be different from the size of the block referenced
by the first argument. The return value is a pointer to the reallocated memory.
The requested size may be smaller or larger than the currently allocated amount. If the
size is less than what is currently allocated, then the excess memory is returned to the
heap. There is no guarantee that the excess memory will be cleared. If the size is greater
than what is currently allocated, then if possible, the memory will be allocated from the
region immediately following the current allocation. Otherwise, memory is allocated
from a different region of the heap and the old memory is copied to the new region.
If the size is zero and the pointer is not null, then the pointer will be freed. If space
cannot be allocated, then the original block of memory is retained and is not changed.
However, the pointer returned is a null pointer and the errno is set to ENOMEM.*/

    /*In the following example, we use two variables to allocate memory for a string. Initially,
    we allocate 16 bytes but only use the first 13 bytes (12 hexadecimal digits and the null
    termination character (0)):*/

    char *string1;
    char *string2;

    string1 = (char *)malloc(16);
    strcpy(string1, "0123456789AB");

    /*Next, we use the realloc function to specify a smaller region of memory. The address
and contents of these two variables are then displayed:*/

    string2 = realloc(string1, 8);
    printf("string1 Value: %p [%s]\n", string1, string1);
    printf("string2 Value: %p [%s]\n", string2, string2);

    /*The output follows:
     string1 Value: 00000266c7c21420 [0123456789AB]
string2 Value: 00000266c7c21420 [0123456789AB]*/

    /*The heap manager was able to reuse the original block, and it did not modify its contents.
    However, the program continued to use more than the eight bytes requested. That is,
    we did not change the string to fit into the eight-byte block. In this example, we should
    have adjusted the length of the string so that it fits into the eight reallocated bytes. The
    simplest way of doing this is to assign a NUL character to address 507. Using more space
    than allocated is not a good practice and should be avoided*/
}