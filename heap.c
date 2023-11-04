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

/*We might as well get to the rough part. malloc() is not the most user-friendly function for
newcomers to understand. Perhaps looking at an example of malloc() is the best place to start.
Suppose you were writing a temperature-averaging program for a local weather forecaster. The more
temperature readings the user enters, the more accurate the correct prediction will be. You decide that
you will allocate 10 integers to hold the first 10 temperature readings. If the user wants to enter more,
your program can allocate another batch of 10, and so on.
You first need a pointer to the 10 heap values. The values are integers, so you need an integer pointer.
You need to define the integer pointer like this:*/

#include <stdlib.h>
void main()
{
    int *temps; /* Will point to the first heap value */

    // Here is how you can allocate 10 integers on the heap using malloc():
    temps = (int *)malloc(10 * sizeof(int)); /* Yikes! */

    /*That’s a lot of code just to get 10 integers. The line is actually fairly easy to understand when you see
it broken into pieces. The malloc() function requires only a single value: the number of bytes you
want allocated. Therefore, if you wanted 10 bytes, you could do this:*/

    malloc(10);

    /*The problem is that the previous description required not 10 bytes, but 10 integers. How many bytes
of memory do 10 integers require? 10? 20? The answer, of course, is that it depends. Only
sizeof() knows for sure.
Therefore, if you want 10 integers allocated, you must tell malloc() that you want 10 sets of bytes
allocated, with each set of bytes being enough for an integer. Therefore, the previous line included the
following malloc() function call:*/

    malloc(10 * sizeof(int));

    /*This part of the statement told malloc() to allocate, or set aside, 10 contiguous integer locations on
the heap. In a way, the computer puts a fence around those 10 integer locations so that subsequent
malloc() calls do not intrude on this allocated memory. Now that you’ve mastered that last half of
the malloc() statement, there’s not much left to understand. The first part of malloc() is fairly
easy.
malloc() always performs the following two steps (assuming that enough heap memory exists to
satisfy your allocation request):
1. Allocates the number of bytes you request and makes sure no other program can overwrite that
memory until your program frees it
2. Assigns your pointer to the first allocated value*


the heap of memory (shown here as just that, a heap) now contains a fenced-off area
of 10 integers, and the integer pointer variable named temps points to the first integer. Subsequent
malloc() function calls will go to other parts of the heap and will not tread on the allocated 10
integers.

What do you do with the 10 integers you just allocated? Treat them like an array! You can store data
by referring to temps[0], temps[1], and so on. You know from the last chapter that you access
contiguous memory using array notation, even if that memory begins with a pointer. Also remember
that each set of allocated memory will be contiguous, so the 10 integers will follow each other just as
if you allocated temps as a 10-integer array.
*/

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*The (int *) is a typecast. You’ve seen other kinds of typecasts in this book. To convert a float
    value to an int, you place (int) before the floating-point value, like this:*/
    float salary;
    int aVal = (int)salary;

    /*The * inside a typecast means that the typecast is a pointer typecast. malloc() always returns a
character pointer. If you want to use malloc() to allocate integers, floating points, or any kind of
data other than char, you have to typecast the malloc() so that the pointer variable that receives
the allocation (such as temps) receives the correct pointer data type. temps is an integer pointer;
you should not assign temps to malloc()’s allocated memory unless you typecast malloc()
into an integer pointer. Therefore, the left side of the previous malloc() simply tells malloc()
that an integer pointer, not the default character pointer, will point to the first of the allocated values.*/

    /*Besides defining an array at the top of main(), what have you gained by using
    malloc()? For one thing, you can use the malloc() function anywhere in your
    program, not just where you define variables and arrays. Therefore, when your
    program is ready for 100 double values, you can allocate those 100 double values.
    If you used a regular array, you would need a statement like this toward the top of
    main():*/

    double doublemyVals[100]; /* A regular array of 100 doubles */

    /*Those 100 double values would sit around for the life of the program, taking up
memory resources from the rest of the system, even if the program only needed the 100
double values for only a short time. With malloc(), you need to define only the
pointer that points to the top of the allocated memory for the program’s life, not the
entire array.*/
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // If There’s Not Enough Heap Memory

    /*In extreme cases, not enough heap memory might exist to satisfy malloc()’s request. The user’s
computer might not have a lot of memory, another task might be using a lot of memory, or your
program might have previously allocated everything already. If malloc() fails, its pointer variable
points to a null value, 0. Therefore, many programmers follow a malloc() with an if, like this:
*/

    temps = (int *)malloc(10 * sizeof(int));
    if (temps == 0)
    {
        printf("Oops! Not Enough Memory!\n");
        exit(1); // Terminate the program early
    }
    // Rest of program would follow...

    /*If malloc() works, temps contains a valid address that points to the start of the allocated heap. If
malloc() fails, the invalid address of 0 is pointed to (heap memory never begins at address zero)
and the error prints onscreen.*/

    // Programmers often use the not operator, !,
    if (!temps)
        ; /* Means, if not true */

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Freeing Heap Memory

    /*When you’re done with the heap memory, give it back to the system. Use free() to do that.
    free() is a lot easier than malloc(). To free the 10 integers allocated with the previous
    malloc(), use free() in the following manner:
    */

    int *temps;
    free(temps); /* Gives the memory back to the heap */

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*Multiple Allocations*/

    /*An array of pointers often helps you allocate many different sets of heap memory. Going back to the
weather forecaster’s problem, suppose the forecaster wanted to enter historical temperature readings
for several different cities. But the forecaster has a different number of readings for each different
city.
An array of pointers is useful for such a problem. Here is how you could allocate an array of 50
pointers:*/

    int *temps[50]; /* 50 integer pointers */

    /*The array will not hold 50 integers (because of the dereferencing operator in the definition); instead,
the array holds 50 pointers. The first pointer is called temps[0], the second pointer is temps[1],
and so on. Each of the array elements (each pointer) can point to a different set of allocated heap
memory. Therefore, even though the 50 pointer array elements must be defined for all of main(),
you can allocate and free the data pointed to as you need extra memory.
*/

    /*Of course, such code requires massive data entry. The values would most likely come from a saved
    file instead of from the user. Nevertheless, the code gives you insight into the advanced data
    structures available by using the heap. Also, real-world programs aren’t usually of the 20-line variety
    you often see in this book. Real-world programs, although not necessarily harder than those here, are
    usually many pages long. Throughout the program, some sections might need extra memory, whereas
    other sections do not. The heap lets you use memory efficiently*/

    /*As you can see, temps belongs to the
    program’s data area, but the memory each temps element points to belongs to the heap. You can free
    up the data temps points to when you no longer need the extra workspace.*/

    // Each temps element points to a dif erent part of the heap.
}