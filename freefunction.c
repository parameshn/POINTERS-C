// Deallocating Memory Using the free Function

#include <stdio.h>
#include <stdlib.h>
main()
{
    /*With dynamic memory allocation, the programmer is able to return memory when it
is no longer being used, thus freeing it up for other uses. This is normally performed
using the free function, whose prototype is shown below:
*/

    void free(void *ptr);

    /*The pointer argument should contain the address of memory allocated by a malloc type
function. This memory is returned to the heap. While the pointer may still point to the
region, always assume it points to garbage. This region may be reallocated later and
populated with different data.
In the simple example below, pi is allocated memory and is eventually freed:
*/
    int *pi = (int *)malloc(sizeof(int));
    free(pi);

    /*illustrates the allocation of memory immediately before and right after the
free function executes. The dashed box at address 500 that indicates the memory has
been freed but still may contain its value. The variable pi still contains the address 500.
This is called a dangling pointer

If the free function is passed a null pointer, then it normally does nothing. If the pointer
passed has been allocated by other than a malloc type function, then the function’s
behavior is undefined. In the following example, pi is allocated the address of num.
However, this is not a valid heap address:*/
    int num;
    int *pi = &num;
    free(pi); // Undefined behavior

    ////if a pointer is allocated within a function, deallocate it in the same function.

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Assigning NULL to a Freed Pointer

    /*Pointers can cause problems even after they have been freed. If we try to dereference a
freed pointer, its behavior is undefined. As a result, some programmers will explicitly
assign NULL to a pointer to designate the pointer as invalid. Subsequent use of such a
pointer will result in a runtime exception.*/

    int *pi = (int *)malloc(sizeof(int));
    free(pi);
    pi = NULL;

    /*This technique attempts to address problems like dangling pointers. However, it is better
to spend time addressing the conditions that caused the problems rather than crudely
catching them with a null pointer. In addition, you cannot assign NULL to a constant
pointer except when it is initialized.
*/
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*Double Free
    The term double free refers to an attempt to free a block of memory twice. A simple
    example follows:*/

    int *pi = (int *)malloc((sizeof(int)));
    *pi = 5;
    free(pi);
    free(pi);
    /*The execution of the second free function will result in a runtime exception. A less
obvious example involves the use of two pointers, both pointing to the same block of
memory. As shown below, the same runtime exception will result when we accidentally
try to free the same memory a second time:*/

    int p1;
    p1 = (int *)malloc(sizeof(int));
    int *p2 = p1;
    free(p1);
    free(p2);

    // When two pointers reference the same location, it is referred to as aliasing

    /*Unfortunately, heap managers have a difficult time determining whether a block has
already been deallocated. Thus, they don’t attempt to detect the same memory being
freed twice. This normally results in a corrupt heap and program termination. Even if
the program does not terminate, it represents questionable problem logic. There is no
reason to free the same memory twice.
It has been suggested that the free function should assign a NULL or some other special
value to its argument when it returns. However, since pointers are passed by value, the
free function is unable to explicitly assign NULL to the pointer. */

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*The Heap and System Memory


    The heap typically uses operating system functions to manage its memory. The heap’s
    size may be fixed when the program is created, or it may be allowed to grow. However,
    the heap manager does not necessarily return memory to the operating system when
    the free function is called. The deallocated memory is simply made available for sub‐
    sequent use by the application. Thus, when a program allocates and then frees up mem‐
    ory, the deallocation of memory is not normally reflected in the application’s memory
    usage as seen from the operating system perspective.*/

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*Freeing Memory upon Program Termination



The operating system is responsible for maintaining the resources of an application,
including its memory. When an application terminates, it is the operating system’s re‐
sponsibility to reallocate this memory for other applications. The state of the terminated
application’s memory, corrupted or uncorrupted, is not an issue. In fact, one of the
reasons an application may terminate is because its memory is corrupted. With an ab‐
normal program termination, cleanup may not be possible. Thus, there is no reason to
free allocated memory before the application terminates.
With this said, there may be other reasons why this memory should be freed. The con‐
scientious programmer may want to free memory as a quality issue. It is always a good
habit to free memory after it is no longer needed, even if the application is terminating.
If you use a tool to detect memory leaks or similar problems, then deallocating memory
will clean up the output of such tools. In some less complex operating systems, the
operating system may not reclaim memory automatically, and it may be the program’s
responsibility to reclaim memory before terminating. Also, a later version of the appli‐
cation could add code toward the end of the program. If the previous memory has not
been freed, problems could arise.

Thus, ensuring that all memory is free before program termination:
• May be more trouble than it’s worth
• Can be time consuming and complicated for the deallocation of complex structures
• Can add to the application’s size
• Results in longer running time
• Introduces the opportunity for more programming errors

Whether memory should be deallocated prior to program termination is application specific.
*/
}