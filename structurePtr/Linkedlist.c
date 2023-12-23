// Linked list

/*We will illustrate each of these data structures using an employee structure. For example,
a linked list consists of nodes connected to one another. Each node will hold user supplied data. The simple employee structure is listed below. The unsigned char data
type is used for age, as this will be large enough to hold people’s ages:*/

typedef struct _employee
{
    char name[32];
    unsigned char age;
} Employee;

/*A simple array is used for a single name. While a pointer to char may prove to be a more
flexible data type for this field, we have elected to use an array of char to simplify the
examples.*/

/*Two comparison functions will be developed. The first one compares two employees
and returns an integer. This function is modeled after the strcmp function. A return
value of 0 means the two employee structures are considered to be equal to each other.
A return value of –1 means the first employee precedes the second employee alphabet‐
ically. A return value of 1 means the first employee follows the second employee. The
second function displays a single employee:*/

int compareEmployee(Employee *e1, Employee *e2)
{
    return strcmp(e1->name, e2->name);
}
void displayEmployee(Employee *employee)
{
    printf("%s\t%d\n", employee->name, employee->age);
}
/*In addition, two function pointers will be used as defined below. The DISPLAY function
pointer designates a function that is passed void and returns void. Its intent is to display
data. The second pointer, COMPARE, represents a function used to compare data refer‐
enced by two pointers. The function should compare the data and return either a 0,
–1, or 1, as explained with the compareEmployee function:*/

typedef void (*DISPLAY)(void *);
typedef int (*COMPARE)(void *, void *);

/*Single-Linked List
A linked list is a data structure that consists of a series of nodes interconnected with
links. Typically, one node is called the head node and subsequent nodes follow the head,
one after another. The last node is called the tail. The links connecting the nodes are
easily implemented using a pointer. Each node can be dynamically allocated as needed.

This approach is preferable to an array of nodes. Using an array results in the creation
of a fixed number of nodes regardless of how many nodes may be needed. Links are
implemented using the index of the array’s elements. Using an array is not as flexible as
using dynamic memory allocation and pointers.

For example, if we wanted to change the order of elements of the array, it would be
necessary to copy both elements, and that can be large for a structure. In addition, adding
or removing an element may require moving large portions of the array to make room
for the new element or to remove an existing element.

There are several types of linked lists. The simplest is a single-linked list where there is
a single link from one node to the next. The links start at the head and eventually leads
to the tail. A circular-linked list has no tail. The linked list’s last node points back to the
head. A doubly linked list uses two links, one pointing forward and one pointing back‐
ward so that you can navigate through the list in both directions. This type of linked list
is more flexible but is more difficult to implement

In this section, we will illustrate the construction and use of a single-linked list. The
following shows the structure used to support the linked list. A Node structure is defined
to represent a node. It consists of two pointers. The first one, a pointer to void, holds
an arbitrary data type. The second is a pointer to the next node. The LinkedList struc‐
ture represents the linked list and holds a pointer to the head and the tail. The current
pointer will help traverse the linked list:*/
typedef struct _node
{
    void *data;
    struct _node *next;
} Node;
typedef struct _linkedList
{
    Node *head;
    Node *tail;
    Node *current;
} LinkedList;
