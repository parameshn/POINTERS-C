/*Passing and Returning by Pointer

In this section, we will examine the impact of passing and returning pointers to and
from functions. Passing pointers allows the referenced object to be accessible in multiple
functions without making the object global. This means that only those functions that
need access to the object will get this access and that the object does not need to be
duplicated.

If the data needs to be modified in a function, it needs to be passed by pointer. We can
pass data by pointer and prohibit it from being modified by passing it as a pointer to a
constant, as will be demonstrated in the section “Passing a Pointer to a Constant” on
page 63. When the data is a pointer that needs to be modified, then we pass it as a pointer
to a pointer. This topic is covered in “Passing a Pointer to a Pointer” on page 68.
Parameters, including pointers, are passed by value. That is, a copy of the argument is
passed to the function. Passing a pointer to an argument can be efficient when dealing
with large data structures. For example, consider a large structure that represents an
employee. If we passed the entire structure to the function, then every byte of the struc‐
ture would need to be copied, resulting in a slower program and in more space being
used in the stack frame. Passing a pointer to the object means the object does have to
be copied, and we can access the object through the pointer.*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Passing Data Using a Pointer


One of the primary reasons for passing data using a pointer is to allow the function to
modify the data. The following sequence implements a swap function that will inter‐
change the values referenced by its parameters. This is a common operation found in
a number of sorting algorithms. Here, we use integer pointers and dereference them to
affect the swap operation:*/

#include <stdlib.h>
#include <stdio.h>

void swapWithPtr(int *num1, int *num2)
{
    int temp;
    temp = num1;
    printf("%d\n", temp); // 1944062148
    temp = *num1;
    printf("%d", temp); // 15
    *num1 = *num2;
    *num2 = temp;
}
// The following code sequence demonstrates this function

int main()
{
    int m1 = 15;
    int m2 = 13;

    swapWithPtr(&m1, &m2);
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Passing Data by Value


If we do not pass them by pointers, then the swap operation will not occur. In the
following function, the two integers are passed by value:*/

void swap(int num1, int num2)
{
    int tmp;
    tmp = num1;
    num1 = num2;
    num2 = tmp;
}
// In the following code sequence, two integers are passed to the function : int main()
main()
{
    int n1 = 5;
    int n2 = 10;
    swap(n1, n2);
    return 0;
}
/*However, this will not work because the integers were passed by value and not by pointer.Only a copy of the arguments is stored in num1 and num2.If we modify num1, then the argument n1 is not changed.When we modify the parameters, we are not modifying the original arguments*/

/*Passing a Pointer to a Constant


Passing a pointer to constant is a common technique used in C. It is efficient, as we are
only passing the address of the data and can avoid copying large amounts of memory
in some cases. However, with a simple pointer, the data can be modified. When this is
not desirable, then passing a pointer to a constant is the answer.
In this example, we pass a pointer to a constant integer and a pointer to an integer.
Within the function, we cannot modify the value passed as a pointer to a constant:
*/

void passingAddressOfConstants(const int *num1, int *num2)
{
    *num2 = *num1;
}

int main()
{
    const int limit = 100;
    int result = 5;
    passingAddressOfConstants(&limit, &result);
    return 0;
}

/*No syntax errors will be generated, and the function will assign 100 to the variable
result. In the following version of the function, we attempt to modify both referenced
integers:
*/

void passingAddressOfConstants(const int *num1, int *num2)
{
    // *num1 = 100;
    *num2 = 200;
}

// This will cause a problem if we pass the constant limit to the function twice:
const int limit = 100;
// passingAddressOfConstants(&limit, &limit);

/*This will generate syntax errors that complain of a type mismatch between the second
parameter and its argument. In addition, it will complain that we are attempting to
modify the presumed constant referenced by the first parameter.
The function expected a pointer to an integer, but a pointer to an integer constant was
passed instead. We cannot pass the address of an integer constant to a pointer to a
constant, as this would allow a constant value to be modified. This is detailed in the
section “Constants and Pointers” on page 27.
An attempt to pass the address of an integer literal as shown below will also generate a
syntax error:
*/

// passingAddressOfConstants(&23, &23);

/*In this case, the error message will indicate that an lvalue is required as the address-of
operator’s operand. The concept of an lvalue is discussed in “Dereferencing a Pointer
Using the Indirection Operator” on page 11.*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Returning a Pointer


Returning a pointer is easy to do. We simply declare the return type to be a pointer to
the appropriate data type. If we need to return an object from a function, the following
two techniques are frequently used:
• Allocate memory within the function using malloc and return its address. The
caller is responsible for deallocating the memory returned

• Pass an object to the function where it is modified. This makes the allocation and
deallocation of the object’s memory the caller’s responsibility.

First, we will illustrate the use of malloc type functions to allocate the memory returned.
This is followed by an example where we return a pointer to a local object. This latter
approach is not recommended. The approach identified in the second bullet is then
illustrated in the section“Passing Null Pointers” on page 67.
In the following example, we define a function that is passed the size of an integer array
and a value to initialize each element. The function allocates memory for an integer
array, initializes the array to the value passed, and then returns the array’s address:*/

int *allocateArray(int size, int value)
{
    int *arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        arr[i] = value;
    }
    return arr;
}

// The following illustrates how this function can be used:

main()
{
    int *vector = allocateArray(4, 45);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", vector[i]);
    }
}
/*illustrates how memory is allocated for this function. The Before image
shows the program’s state right before the return statement is executed. The After image
shows the program’s state after the function has returned. The variable vector now
contains the address of the memory allocated in the function. While the arr variable
went away when the function terminated, the memory referenced by the pointer does
not go away. This memory will eventually need to be freed.

Although the previous example works correctly, several potential problems can occur
when returning a pointer from a function, including:

• Returning an uninitialized pointer
• Returning a pointer to an invalid address
• Returning a pointer to a local variable
• Returning a pointer but failing to free it

The last problem is typified by the allocateArray function. Returning dynamically
allocated memory from the function means the function’s caller is responsible for deal‐
locating it. Consider the following example:
*/
free(vector);

// We must eventually free it once we are through using it. If we don’t, then we will have a memory leak.

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pointers to Local Data

/*Returning a pointer to local data is an easy mistake to make if you don’t understand
how the program stack works. In the following example, we rework the allocateAr
ray function used in the section “Returning a Pointer” on page 64. Instead of dynami‐
cally allocating memory for the array, we used a local array*/

int *allocateArray(int size, int value)
{
    int array[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = value;
    }
    return array;
}

/*Unfortunately, the address of the array returned is no longer valid once the function
returns because the function’s stack frame is popped off the stack. While each array
element may still contain a 45, these values may be overwritten if another function is
called. This is illustrated with the following sequence. Here, the printf function is
invoked repeatedly, resulting in corruption of the array:
*/
main()
{
    int *vector = allocateArray(5, 55);
    for (int i = 0; i < 5; i++)
        printf("%d", vector[i]);
}

/*illustrates how memory is allocated when this happens. The dashed box
shows where other stack frames, such as those used by the printf function, may be
pushed onto the program stack, thus corrupting the memory held by the array. The
actual contents of that stack frame are implementation-dependent.

An alternative approach is to declare the arr variable as static. This will restrict the
variable’s scope to the function but allocate it outside of the stack frame, eliminating the
possibility of another function overwriting the variable’s value:
*/
int *allocateArray(int size, int value)
{
    static int array[5];

    for (int i = 0; i < size; i++)
    {
        array[i] = value;
    }
    return array;
}

/*However, this will not always work. Every time the allocateArray function is called,
it will reuse the array. This effectively invalidates any previous calls to the function. In
addition, the static array must be declared with a fixed size. This will limit the function’s
ability to handle various array sizes.
If the function returns only a few possible values and it does not hurt to share them,
then it can maintain a list of these values and return the appropriate one. This can be
useful if we are returning a status type message, such as an error number that is not
likely to be modified. In the section “Returning Strings” on page 126, an example of using
global and static values is demonstrated.*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Passing Null Pointers


In the following version of the allocateArray function, a pointer to an array is passed
along with its size and a value that it will use to initialize each element of the array. The
pointer is returned for convenience. Although this version of the function does not
allocate memory, later versions will allocate memory:*/

int *allocatArray(int *arr, int size, int value)
{
    if (arr != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = value;
        }
    }
    return arr;
}

/*When a pointer is passed to a function, it is always good practice to verify it is not null
before using it.
The function can be invoked as follows*/

main()
{
    int *vector = (int *)malloc(5 * sizeof(int));
    allocatArray(vector, 5, 55);
}
/*If the pointer is NULL, then no action is performed and the program will execute
without terminating abnormally.*/