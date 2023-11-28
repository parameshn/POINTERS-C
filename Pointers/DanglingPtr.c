/*Dangling Pointers

If a pointer still references the original memory after it has been freed, it is called a
dangling pointer. The pointer does not point to a valid object. This is sometimes referred
to as a premature free.

The use of dangling pointers can result in a number of different types of problems,
including:

• Unpredictable behavior if the memory is accessed
• Segmentation faults when the memory is no longer accessible
• Potential security risks
These types of problems can result when:
• Memory is accessed after it has been freed
• A pointer is returned to an automatic variable in a previous function call */

#include <stdio.h>
#include <stdlib.h>
main()
{
    /*Dangling Pointer Examples
    Below is a simple example where we allocate memory for an integer using the malloc
    function. Next, the memory is released using the free function:*/
    int *pi = (int *)malloc(sizeof(int));
    *pi = 5;
    printf("*pi: %d\n", *pi);
    free(pi);

    /*The variable pi will still hold the integer’s address. However, this memory may be reused
by the heap manager and may hold data other than an integer. Figure 2-11 illustrates
the program’s state immediately before and after the free function is executed. The pi
variable is assumed to be part of the main function and is located at address 100. The
memory allocated using malloc is found at address 500.
When the free function is executed, the memory at address 500 has been deallocated
and should not be used. However, most runtime systems will not prevent subsequent
access or modification. We may still attempt to write to the location as shown below.
The result of this action is unpredictable.
*/

    free(pi);
    *pi = 10;

    /*A more insidious example occurs when more than one pointer references the same area
of memory and one of them is freed. As shown below, p1 and p2 both refer to the same
area of memory, which is called pointer aliasing. However, p1 is freed:*/

    int *p1 = (int *)malloc(sizeof(int));
    *p1 = 5;

    int *p2;
    p2 = p1;

    free(p1);

    *p2 = 10; // Dangling pointer

    /*A subtle problem can occur when using block statements, as shown below. Here pi is
assigned the address of tmp. The variable pi may be a global variable or a local variable.
However, when tmp’s enclosing block is popped off of the program stack, the address is
no longer valid:*/

    int *pi;

    {
        int tmp = 5;
        pi = &tmp;
    }
    // pi is now a dangling pointer
    foo();

    /*Most compilers will treat a block statement as a stack frame. The variable tmp was al‐
located on the stack frame and subsequently popped off the stack when the block state‐
ment was exited. The pointer pi is now left pointing to a region of memory that may
eventually be overridden by a different activation record, such as the function foo*/

    /*Dealing with Dangling Pointers


    Debugging pointer-induced problems can be difficult to resolve at times. Several ap‐
    proaches exist for dealing with dangling pointers, including:

    • Setting a pointer to NULL after freeing it. Its subsequent use will terminate the ap‐
    plication. However, problems can still persist if multiple copies of the pointer exist.
    This is because the assignment will only affect one of the copies, as illustrated in
    the section “Double Free” on page 48.

    • Writing special functions to replace the free function (see “Writing your own free
    function” on page 70).

    • Some systems (runtime/debugger) will overwrite data when it is freed (e.g.,
    0xDEADBEEF - Visual Studio will use 0xCC, 0xCD, or 0xDD, depending on what
    is freed). While no exceptions are thrown, when the programmer sees memory
    containing these values where they are not expected, he knows that the program
    may be accessing freed memory.

    • Use third-party tools to detect dangling pointers and other problems.
    Displaying pointer values can be helpful in debugging dangling pointers, but you need
    to be careful how they are displayed. We have already discussed how to display pointer
    values in “Displaying Pointer Values” on page 9. Make sure you display them consistently
    to avoid confusion when comparing pointer values. The assert macro can also be
    useful, as demonstrated in “Dealing with Uninitialized Pointers” on page 162.
    */
}