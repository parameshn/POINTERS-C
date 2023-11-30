// Passing a One-Dimensional Array

/*When a one-dimensional array is passed to a function, the array’s address is passed by
value. This makes the transfer of information more efficient since we are not passing
the entire array and having to allocate memory in the stack for it. Normally, this means
the array’s size must be passed. If we don’t, from the function’s perspective all we have
is the address of an array with no indication of its size.


Unless there is something integral to the array to tell us its bounds, we need to pass the
size information when we pass the array. In the case of a string stored in an array, we
can rely on the NUL termination character to tell us when we can stop processing the
array. We will examine this in Chapter 5. Generally, if we do not know the array’s size,
we are unable to process its elements and can wind up working with too few elements
or treating memory outside of the array as if it were part of the array. This will frequently
result in abnormal program termination.*/

// We can declare the array in the function declaration using one of two notations: array notation or pointer notation.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Using Array Notation

/*In the following example, an integer array is passed to a function along with its size. Its
contents are then displayed:*/

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    display(arr, 5);
}

/*The sequence’s output will be the numbers 1 through 5.We passed the number 5 to the
function that indicates its size. We could have passed any positive number and the
function would attempt to display the corresponding number of elements, regardless
of whether the size was correct. The program may terminate if we attempt to address
memory outside of the array’s bounds. The memory allocation for this example is shown*/

/*It is a common practice to pass a size smaller than the actual number of elements in an
array. This is done to process only part of an array. For example, assume we read in a
series of ages into an array but did not fill up the array. If we called a sort function to
sort it, we would only want to sort the valid ages, not every array element.
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Using Pointer Notation

/*We do not have to use the bracket notation when declaring an array parameter of a
function. Instead, we can use pointer notation as follows:
*/
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]); // arr[] = array notation
    }                           //*(arr+i)= pointer notation
}

// We continued to use array notation within the function. If desired, we could have used
// pointer notation in the function:

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", *(arr + i));
    }
}

/*If we had used array notation to declare the function, we could have still used pointer
notation in the function’s body*/

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", *(arr + i));
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// Using a One-Dimensional Array of Pointers

/*In this section, we will examine the key aspects of using an array of pointers by using
an array of pointers to integer. Examples of array of pointers can also be found in:


• “Using an Array of Function Pointers” on page 76, where we use an array of function
pointers;
• “How Memory Is Allocated for a Structure” on page 135, where an array of structures
is used; and
• “Passing Arguments to an Application” on page 125, where the argv array is handled.


The purpose of this section is to set the stage for later examples by illustrating the essence
of the approach. The following sequence declares an array of integer pointers, allocates
memory for each element, and initializes this memory to the array’s index:*/
void array()
{
    int *arr[5];
    for (int i = 0; i < 5; i++)
    {
        arr[i] = (int *)malloc(sizeof(int));
        *arr[i] = i;
    }
}

/*If this array was displayed, the numbers 0 through 4 would be printed. We used arr[i]
to reference the pointer and *arr[i] to assign a value to the location referenced by the
pointer. Do not let the use of array notation confuse you. Since arr was declared as an
array of pointers, arr[i] returns an address. When we dereference a pointer such as
*arr[i], we get the contents at that address.*/

// We could have used the following equivalent pointer notation for the loop’s body:

void array()
{
    int *arr[5];
    for (int i = 0; i < 5; i++)
    {
        *(arr + i) = (int *)malloc(sizeof(int));
        **(arr + i) = i;
    }
}

/*This notation is harder to follow, but understanding it will further your C expertise. We
are using two levels of indirection in the second statement. Mastery of this type of
notation will separate you from the less experienced C programmers.


The subexpression (arr+i) represents the address of the array’s ith element. We need to
modify the content of this address so we use the subexpression *(arr+i). The allocated
memory is assigned to this location in the first statement. Dereferencing this subex‐
pression a second time, as we do in the second statement, returns the allocated memory’s
location. We then assign the variable i to it. Figure 4-9 illustrates how memory is
allocated.
*/

/*For example, arr[1] is located at address 104. The expression (arr+1) will give us 104.
Using *(arr+1) gives us its content. In this example, it is the pointer 504. Dereferencing
this a second time using **(arr+1) gives us the contents of 504, which is a 1.*/

/*What we have is a five-element array of pointers to a series of one-element
arrays.
The expression arr[3][0] refers to the fourth element of arr and then the first element
of the array it points to. The expression arr[3][1] does not work because the array the
fourth element is pointing to does not have two elements.*/