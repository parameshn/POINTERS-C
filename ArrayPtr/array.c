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