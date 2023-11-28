/*Predefined Pointer-Related Types
Four predefined types are frequently used when working with pointers. They include:


size_t  == Created to provide a safe type for sizes

ptrdiff_t == Created to handle pointer arithmetic

intptr_t and uintprt_t == Used for storing pointer addresses


Understanding size_t
The type size_t represents the maximum size any object can be in C. It is an unsigned
integer since negative numbers do not make sense in this context. Its purpose is to
provide a portable means of declaring a size consistent with the addressable area of
memory available on a system. The size_t type is used as the return type for the sizeof
operator and as the argument to many functions, including malloc and strlen, among
others.


It is good practice to use size_t when declaring variables for sizes such
as the number of characters and array indexes. It should be used for
loop counters, indexing into arrays, and sometimes for pointer
arithmetic.

*/
/*The declaration of size_t is implementation-specific. It is found in one or more stan‐
dard headers, such as stdio.h and stdlib.h, and it is typically defined as follows*/

#ifndef __SIZE_T
#define __SIZE_T
typedef unsigned int size_t;
#endif
/*The define directives ensure it is only defined once. The actual size will depend on the
implementation. Typically, on a 32-bit system, it will be 32 bits in length, while on a 64-
bit system it will be 64 bits in length. Normally, the maximum possible value for size_t
is SIZE_MAX*/

/*Usually size_t can be used to store a pointer, but it is not a good idea
to assume size_t is the same size as a pointer.*/
#include <stdio.h>
main()
{
    /*Be careful when printing values defined as size_t. These are unsigned values, and if
you choose the wrong format specifier, you’ll get unreliable results. The recommended
format specifier is %zu. However, this is not always available. As an alternative, consider
using %u or %lu.
Consider the following example, where we define a variable as a size_t and then display
it using two different format specifiers:
*/

    size_t sizet = -5;
    printf("%d\n", sizet);
    printf("%zu\n", sizet);

    /*Since a variable of type size_t is intended for use with positive integers, using a negative
value can present problems. When we assign it a negative number and use the %d and
then the %zu format specifiers, we get the following output:
-5
4294967291
The %d field interprets size_t as a signed integer. It displays a –5 because it holds a –5.
The %zu field formats size_t as an unsigned integer. When –5 is interpreted as a signed
integer, its high-order bit is set to one, indicating that the integer is negative. When
interpreted as an unsigned number, the high-order bit is interpreted as a large power
of 2. This is why we saw the large integer when we used the %zu field specifier.
A positive number will be displayed properly as shown below:*/

    sizet = 5;
    printf("%d\n", sizet);  // Displays 5
    printf("%zu\n", sizet); // Displays 5

    // Since size_t is unsigned, always assign a positive number to a variable of that type.

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*Using the sizeof operator with pointers


The sizeof operator can be used to determine the size of a pointer. The following
displays the size of a pointer to char:
*/
    printf("Size of *char: %d\n", sizeof(char *)); // The output follows:  Size of *char: 4

    // Always use the sizeof operator when the size of a pointer is needed.

    /*The size of a function pointer can vary. Usually, it is consistent for a given operating
system and compiler combination. Many compilers support the creation of a 32-bit or
64-bit application. It is possible that the same program, compiled with different options,
will use different pointer sizes.
On a Harvard architecture, the code and data are stored in different physical memory.
For example, the Intel MCS-51 (8051) microcontroller is a Harvard machine. Though
Intel no longer manufactures the chip, there are many binary compatible derivatives
available and in use today. The Small Device C Complier (SDCC) supports this type of
processor. Pointers on this machine can range from 1 to 4 bytes in length. Thus, the size
of a pointer should be determined when needed, as its size is not consistent in this type
of environment.*/

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*Using intptr_t and uintptr_t


The types intptr_t and uintptr_t are used for storing pointer addresses. They provide
a portable and safe way of declaring pointers, and will be the same size as the underlying
pointer used on the system. They are useful for converting pointers to their integer
representation.
The type uintptr_t is the unsigned version of intptr_t. For most operations intptr_t
is preferred. The type uintptr_t is not as flexible as intptr_t. The following illustrates
how to use intptr_t:*/

    int num;
    intptr_t *pi = &num;

    // If we try to assign the address of an integer to a pointer of type uintptr_t as follows, we will get a syntax error:
    uintptr_t *pu = &num;

    // However, performing the assignment using a cast will work:
    intptr_t *pi = &num;
    uintptr_t *pu = (uintptr_t *)&num;
    // We cannot use uintptr_t with other data types without casting:
    char c;
    uintptr_t *pc = (uintptr_t *)&c;
}