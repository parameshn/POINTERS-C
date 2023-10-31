/// Pointers to a constant
// A pointer can be defined to point to a constant. This means the pointer cannot be used
// to modify the value it is referencing. In the following example, an integer and an integer
// constant are declared. Next, a pointer to an integer and a pointer to an integer constant
// are declared and then initialized to the respective integers:

#include <stdio.h>
main()
{
    int num = 5;
    const int limit = 500;
    int *pi;        // Pointer to an integer
    const int *pci; // Pointer to a constant integer
    pi = &num;
    pci = &limit;

    // The following sequence will display the address and value of these variables:

    printf(" num - Address: %p value: %d\n", &num, num);
    printf("limit - Address: %p value: %d\n", &limit, limit);
    printf(" pi - Address: %p value: %p\n", &pi, pi);
    printf(" pci - Address: %p value: %p\n", &pci, pci);

    /*When executed, this sequence will produce values similar to the following:
 num - Address: 100 value: 5
limit - Address: 104 value: 500
 pi - Address: 108 value: 100
 pci - Address: 112 value: 104
Dereferencing a constant pointer is fine if we are simply reading the integer’s value.
Reading is a perfectly legitimate and necessary capability, as shown below*/

    printf("%d\n", *pci);

    /*We cannot dereference a constant pointer to change what the pointer references, but
   we can change the pointer. The pointer value is not constant. The pointer can be changed
   to reference another constant integer or a simple integer. Doing so will not be a problem.
   The declaration simply limits our ability to modify the referenced variable through the
   pointer.
   This means the following assignment is legal:*/
    pci = &num;

    /*We can dereference pci to read it; however, we cannot dereference it to modify it.
Consider the following assignment:
*/
    // *pci = 200;
    // This will result in the following syntax error:
    //'pci' : you cannot assign to a variable that is const

    /*The pointer thinks it is pointing to a constant integer; therefore, it does allow the mod‐
ification of the integer using the pointer. We can still modify num using its name. We
just can’t use pci to modify it.



The declaration of pci as a pointer to a constant integer means:
• pci can be assigned to point to different constant integers
• pci can be assigned to point to different nonconstant integers
• pci can be dereferenced for reading purposes
• pci cannot be dereferenced to change what it points to*/

    // The order of the type and the const keyword is not important. The following are equivalent:
    const int *pci;
    int const *pci;
}