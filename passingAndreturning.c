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