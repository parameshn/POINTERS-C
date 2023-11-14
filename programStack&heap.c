// Program Stack and Heap

/*The program stack and the heap are important runtime elements of C. In this section,
we will carefully examine the structure and use of the program stack and heap. We will
also look at the stack frame’s structure, which holds local variables.
*/

/*Program Stack
The program stack is an area of memory that supports the execution of functions and
is normally shared with the heap. That is, they share the same region of memory. The
program stack tends to occupy the lower part of this region, while the heap uses the
upper part.
The program stack holds stack frames, sometimes called activation records or activation
frames. Stack frames hold the parameters and local variables of a function. The heap
manages dynamic memory and is discussed in “Dynamic Memory Allocation” on page
34.
Figure 3-1 illustrates how the stack and heap are organized conceptually. This illustra‐
tion is based on the following code sequence:*/

#include <stdio.h>
#include <stdlib.h>
void function2()
{
    int *var1 = 123;
    int var2;
    printf("Program Stack Example\n");
}
void function1()
{
    int *var3 = 542;
    function2();
}
int main()
{
    int var4;
    function1();
}

/*As functions are called, their stack frames are pushed onto the stack and the stack grows
“upward.” When a function terminates, its stack frame is popped off the program stack.
The memory used by the stack frame is not cleared and may eventually be overridden
by another stack frame when it is pushed onto the program stack.


When memory is dynamically allocated, it comes from the heap, which tends to grow
“downward.” The heap will fragment as memory is allocated and then deallocated. Al‐
though the heap tends to grow downward, this is a general direction. Memory can be
allocated from anywhere within the heap.
*/

/*Organization of a Stack Frame



A stack frame consists of several elements, including:
Return address
The address in the program where the function is to return upon completion
Storage for local data
Memory allocated for local variables
Storage for parameters
Memory allocated for the function’s parameters
Stack and base pointers
Pointers used by the runtime system to manage the stack
The typical C programmer will not be concerned about the stack and base pointers used
in support of a stack frame. However, understanding what they are and how they are
used provides a more in-depth understanding of the program stack.
A stack pointer usually points to the top of the stack. A stack base pointer (frame pointer)
is often present and points to an address within the stack frame, such as the return
address. This pointer assists in accessing the stack frame’s elements. Neither of these
pointers are C pointers. They are addresses used by the runtime system to manage the
program stack. If the runtime system is implemented in C, then these pointers may be
real C pointers.*/

/*Consider the creation of a stack frame for the following function. This function has
passed an array of integers and an integer representing the array’s size. Three printf
statements are used to display the parameter’s and the local variable’s addresses:
*/

float average(int *arr, int size)
{
    int sum;
    printf("arr: %p\n", &arr);
    printf("size: %p\n", &size);
    printf("sum: %p\n", &sum);

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return (sum * 1.0f) / size;
}

/*When executed, you get output similar to the following:
arr: 0x500
size: 0x504
sum: 0x480
The gap in the addresses between the parameters and the local variables is due to other
elements of the stack frame used by the runtime system to manage the stack.
When the stack frame is created, the parameters are pushed onto the frame in the op‐
posite order of their declaration, followed by the local variables. This is illustrated in
Figure 3-2. In this case, size is pushed followed by arr. Typically, the return address
for the function call is pushed next, followed by the local variables. They are pushed in
the opposite order in which they were listed.

Conceptually, the stack in this example grows “up.” However, the stack frame’s param‐
eters and local variables and new stack frames are added at lower memory addresses.
The actual direction the stack grows is implementation-specific.

The variable i used in the for statement is not included as part of this stack frame. C
treats block statements as “mini” functions and will push and pop them as appropriate.
In this case, the block statement is pushed onto the program stack above the average
stack frame when it is executed and then popped off when it is done.

While the precise addresses can vary, the order usually will not. This is important to
understand, as it helps explain how memory is allocated and establishes the relative
order of the parameters and variables. This can be useful when debugging pointer
problems. If you are not aware of how the stack frame is allocated, the assignment of
addresses may not make sense.

As stack frames are pushed onto the program stack, the system may run out of memory.
This condition is called stack overflow and generally results in the program terminating
abnormally. Keep in mind that each thread is typically allocated its own program stack.*/
