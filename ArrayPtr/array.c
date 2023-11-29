// Pointers and Arrays

/*An array is a fundamental data structure built into C. A thorough understanding of
arrays and their use is necessary to develop effective applications. Misunderstandings
of array and pointer usage can result in hard-to-find errors and less than optimal per‐
formance in applications. Array and pointer notations are closely related to each other
and can frequently be used interchangeably in the right context.
A common misconception is that an array and a pointer are completely interchangeable.
An array name is not a pointer. Although an array name can be treated as a pointer at
times, and array notation can be used with pointers, they are distinct and cannot always
be used in place of each other. Understanding this difference will help you avoid incor‐
rect use of these notations. For example, although the name of an array used by itself
will return the array’s address, we cannot use the name by itself as the target of an
assignment.
Arrays support many parts of an application and can be single or multidimensional. In
this chapter, we will address the fundamental aspects of arrays as they relate to pointers
to provide you with a deep understanding of arrays and the various ways they can be
manipulated with pointers. You will see their use in more advanced contexts throughout
the book.
We start with a quick review of arrays and then examine the similarities and differences
between array and pointer notation. Arrays can be created using malloc type functions.
These functions provide more flexibility than that afforded by traditional array decla‐
rations. We will see how the realloc function can be used to change the amount of
memory allocated for an array.
Dynamically allocating memory for an array can present challenges, especially when
we are dealing with arrays with two or more dimensions, as we have to ensure that the
array is allocated in contiguous memory
We will also explore problems that can occur when passing and returning arrays. In
most situations, the array’s size must be passed so the array can be properly handled in
a function. There is nothing inherent in an array’s internal representation that deter‐
mines its length. If we do not pass the length, the function has no standard means of
knowing where the array ends. We will also examine how to create jagged arrays in C,
although they are infrequently used. A jagged array is a two-dimensional array where
each row may have a different number of columns.
To demonstrate these concepts, we will use a vector for single-dimensional arrays and
a matrix for two-dimensional arrays. Vectors and matrices have found extensive use in
many areas, including analyzing electromagnetic fields, weather prediction, and in
mathematics*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Quick Review of Arrays
An array is a contiguous collection of homogeneous elements that can be accessed using
an index. By contiguous, we mean the elements of the array are adjacent to one another
in memory with no gaps between them. By homogeneous, we mean they are all of the
same type. Array declarations use a set of brackets and can possess multiple dimensions.
Two-dimensional arrays are common, and we typically use the terms rows and columns
to describe the position of an array’s element. Arrays with three or more dimensions
are not as common but can be quite useful in some applications. A two-dimensional
array is not to be confused with an array of pointers. They are similar but behave slightly
differently*/

// Pointer Notation and Arrays

/*Array notation and pointer notation can be used somewhat interchangeably.
However, they are not exactly the same */
#include <stdio.h>
void main()
{
    /*When an array name is used by itself, the array’s address is returned. We can assign this
address to a pointer as illustrated below:*/

    int vector[5] = {1, 2, 3, 4, 5};
    int *pv = vector;
    int i;
    printf("%d\n%d \n%d\n%d \n", *(vector + 2), vector[2], *(pv + 2), pv[2]); // 3 3 3 3

    /*The variable pv is a pointer to the first element of the array and not the array itself. When
we first assigned a value to pv, we assigned the address of the array’s first element*/

    /*We can use either the array name by itself or use the address-of operator with the array’s
    first element as illustrated below. These are equivalent and will return the address of
    vector. Using the address-of operator is more verbose but also more explicit:
    */
    printf("%p\n", vector);
    printf("%p\n", &vector[0]);

    // we can also use array subscripts with pointers effectively the notation pv[i] is evaluated as

    *(pv + i);

    /*The pointer pv contains the address of a block of memory. The bracket notation will
take the address contained in pv and adds the value contained in the index i using
pointer arithmetic. This new address is then dereferenced to return its contents.*/

    /* adding an integer to a
    pointer will increment the address it holds by the product of the integer and the data
    type’s size. The same is true if we add an integer to the name of an array. The following
    two statements are equivalent:*/

    *(pv + i);
    *(vector + i);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////shift and dereference

    /*When we add 1 to the array address we effectively add 4, the size of an integer, to the
address since this is an array of integers. With the first and last operations, we addressed
locations outside the array’s bounds. While this is not a good practice, it does emphasize
the need to be careful when using indexes or pointers to access elements of an array.
Array notation can be thought of as a “shift and dereference” operation. The expression
vector[2] means start with vector, which is a pointer to the beginning of the array, shift
two positions to the right, and then dereference that location to fetch its value. Using
the address-of operator in conjunction with array notation, as in &vector[2], essentially
cancels out the dereferencing. It can be interpreted as go left two positions and then
return that address.*/

    // This operation takes a value and multiplies it against each element of the vector:
    pv = vector;
    int value = 3;
    for (int i = 0; i < 5; i++)
    {
        *pv++ *= value;
    }
}