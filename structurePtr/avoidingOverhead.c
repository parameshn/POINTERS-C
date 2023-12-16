// Avoiding malloc/free Overhead

/*When structures are allocated and then deallocated repeatedly, some overhead will be
incurred, resulting in a potentially significant performance penalty. One approach to
deal with this problem is to maintain your own list of allocated structures. When a user
no longer needs an instance of a structure, it is returned to the pool. When an instance
is needed, it obtains the object from the pool. If there are no elements available in the
pool, a new instance is dynamically allocated. This approach effectively maintains a pool
of structures that can be used and reused as needed.
*/
/*To demonstrate this approach we will use the Person structure previously defined. A
pool of persons is maintained in an array. A more complex list, such as a linked list, can
also be used, as illustrated in the section “Single-Linked List” on page 142. To keep this
example simple, an array of pointers is used, as declared below:*/
#include <stdlib.h>
#define LIST_SIZE 10

typedef struct person
{
    int a;
    char b;
} Person;
Person *list[LIST_SIZE];

/*Before the list can be used, it needs to be initialized. The following function assigns NULL
to each element of the array:
*/
void initializeList()
{
    for (int i = 0; i < LIST_SIZE; i++)
    {
        list[i] = NULL;
    }
}

/*Two functions are used to add and retrieve persons. The first is the getPerson function,
as shown below. This function retrieves a person from the list if possible. The array’s
elements are compared to NULL. The first non-null element is returned, and its position
in list is then assigned a value of NULL. If there is no person available, then a new
instance of a Person is created and returned. This avoids the overhead of dynamically
allocating memory for a person every time a new one is needed. We only allocate mem‐
ory if there is none in the pool. The initialization of the instance returned can be done
either before it is returned or by the caller, depending on the needs of the application:
*/

Person *getPerson()
{
    for (int i = 0; i < LIST_SIZE; i++)
    {
        if (list[i] != NULL)
        {
            Person *ptr = list[i];
            list[i] = NULL;
        }
    }
    Person *person = (Person *)malloc(sizeof(Person));
    return person;
}
/*The second function is the returnPerson, which either adds the person to the list or
frees it up. The array’s elements are checked to see whether there are any NULL values.
If it does, then person is added to that position and the pointer is returned. If the list is
full, then the pointers within person are freed using the deallocatePerson function,
person is freed, and then NULL is returned:*/

Person *returnPerson(Person *person)
{
    for (int i = 0; i < LIST_SIZE; i++)
    {
        if (list[i] = NULL)
        {
            list[i] = person;
            return person;
        }
    }
    deallocatePerson(person);
    free(person);
    return NULL;
}
// The following illustrates the initialization of the list and adding a person to the list:

main()
{
    initializeList();
    Person *ptrPerson;

    ptrPerson = getPerson();
    initializePerosn(ptrPerson, "ralph", "fitsgersad", "Mr.", 35);
    displayPerson(*ptrPerson);
    returnPerson(ptrPerson);
}

/*One problem associated with this approach deals with the list size. If the list is too small,
then more dynamic allocation and deallocation of memory will be necessary. If the list
is large and the structures are not being used, a potentially large amount of memory
may be tied up and unavailable for other uses. A more sophisticated list management
scheme can be used to manage the list’s size*/