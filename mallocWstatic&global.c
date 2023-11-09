/*Using malloc with static and global pointers
You cannot use a function call when initializing a static or global variable. In the fol‐
lowing code sequence, we declare a static variable and then attempt to initialize it using
malloc:*/

#include <stdio.h>
#include <stdlib.h>
main()
{
    // static int *pi = malloc(sizeof(int)); //function call is not allowed in a constant expression

    /**This will generate a compile-time error message. The same thing happens with global
variables but can be avoided for static variables by using a separate statement to allocate
memory to the variable as follows. We cannot use a separate assignment statement with
global variables because global variables are declared outside of a function and exe‐
cutable code, such as the assignment statement, must be inside of a function:*/

    static int *pi;
    pi = malloc(sizeof(int));

    /*From the compiler standpoint, there is a difference between using the
initialization operator, =, and using the assignment operator, =.*/
}