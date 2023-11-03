// think of the heap as just one big heap of free memory stacked up in a pile.

/*The heap is the collection of unused memory in your computer. The memory left over—after your program, your program’s
variables, and your operating system’s workspace—comprises your computer’s available heap
space,
Many times you’ll want access to the heap, because your program will need more memory than you
initially defined in variables and arrays

You don’t assign variable names to heap memory. The only way to access data stored in heap memory
is through pointer variables


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
The free heap memory is called free heap or unallocated heap memory. The part of the
heap in use by your program at any one time is called the allocated heap. Your program
might use varying amounts of heap space as the program executes. */

/*you’ll understand the heap much better if you think of the heap of
memory like you think of the heap of dirt: You have no idea exactly where the memory you allocate
and deallocate will come from or go back to. You know only that the memory comes and goes from
the heap.

If you allocate 10 bytes of heap memory at once, those 10 bytes will be contiguous. The important
thing to know is that the next section of heap memory you allocate will not necessarily follow the
first, so you shouldn’t count on anything like that.


Your operating system uses heap memory along with your program. If you work on a networked
computer or use a multitasking operating environment such as Windows, other tasks might be grabbing
heap memory along with your program. Therefore, another routine might have come between two of
your heap-allocation statements and allocated or deallocated memory.


You have to keep track of the memory you allocate. You do this with pointer variables. For instance,
if you want to allocate 20 integers on the heap, you use an integer pointer. If you want to allocate 400
floating-point values on the heap, you use a floating-point pointer. The pointer always points to the
first heap value of the section you just allocated. Therefore, a single pointer points to the start of the
section of heap you allocate. If you want to access the memory after the first value on the heap, you
can use pointer notation or array notation to get to the rest of the heap section you allocated

Remember, you must define all variables before you use
them. If you define an array to hold 100 customer IDs, but the user has 101 customers to enter, your
program can’t just expand the array at runtime. Some programmers (like you) have to change the array
definition and recompile the program before the array can hold more values.
With the heap memory, however, you don’t have to know in advance how much memory you need.
Similar to an accordion, the heap memory your program uses can grow or shrink as needed. If you
need another 100 elements to hold a new batch of customers, your program can allocate that new
batch at runtime without needing another compilation.
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*The heap enables your program to use only as much memory as it needs. When your
user needs more memory (for instance, to enter more data), your program can allocate
the memory. When your user is finished using that much memory (such as clearing a
document to start a new one in a word processor), you can deallocate the memory,
making it available for other tasks that might need it.*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*You must learn only two new functions to use the heap. The malloc() (for memory allocate)

function allocates heap memory, and the free() function deallocates heap memory.

Be sure to include the stdlib.h header file in all the programs you write that use
malloc() and free().

*/