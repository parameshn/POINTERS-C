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