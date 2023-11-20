/*Function Pointers


A function pointer is a pointer that holds the address of a function. The ability of pointers
to point to functions turns out to be an important and useful feature of C. This provides
us with another way of executing functions in an order that may not be known at compile
time and without using conditional statements.
One concern regarding the use of function pointers is a potentially slower running
program. The processor may not be able to use branch prediction in conjunction with
pipelining. Branch prediction is a technique whereby the processor will guess which
multiple execution sequences will be executed. Pipelining is a hardware technology
commonly used to improve processor performance and is achieved by overlapping
instruction execution. In this scheme, the processor will start processing the branch it
believes will be executed. If the processor successfully predicts the correct branch, then
the instructions currently in the pipeline will not have to be discarded.
This slowdown may or may not be realized. The use of function pointers in situations
such as table lookups can mitigate performance issues. In this section, we will learn how
to declare function pointers, see how they can be used to support alternate execution
paths, and explore techniques that exploit their potential.*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Declaring Function Pointers

/*
The syntax for declaring a pointer to a function can be confusing when you first see it.
As with many aspects of C, once you get used to the notation, things start falling into
place. Let’s start with a simple declaration. Below, we declare a pointer to a function that
is passed void and returns void:*/

void (*foo)();

/*This declaration looks a lot like a function prototype. If we removed the first set of
parentheses, it would appear to be a function prototype for the function foo, which is
passed void and returns a pointer to void. However, the parentheses make it a function
pointer with a name of foo. The asterisk indicates that it is a pointer. Figure 3-9highlights
the parts of a function pointer declaration*/

// Other examples of function pointer declarations are illustrated below
int (*f4)(double); // Passed a double and
                   // returns an int

void (*f2)(char *); // Passed a pointer to char and
                    // returns void

double *(*f6)(int, int); // Passed two integers and
                         // returns a pointer to a double

/*One suggested naming convention for function pointers is to always
begin their name with the prefix: fptr.
*/

/*Do not confuse functions that return a pointer with function pointers. The following
declares f4 as a function that returns a pointer to an integer, while f5 is a function
pointer that returns an integer. The variable f6 is a function pointer that returns a pointer
to an integer:*/

int *f4();
int (*f5)();
int *(*f6)();

// The whitespace within these expressions can be rearranged so that it reads as follows:
int *f4();
int (*f5)();

/*It is clear that f4 is a function that returns a pointer to an integer. However, using
parentheses with f5 clearly bind the “pointer” asterisk to the function name, making it
a function pointer.*/