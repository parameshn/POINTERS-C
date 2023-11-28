#include <stdio.h>
main()
{
    /*Multiple Levels of Indirection
Pointers can use different levels of indirection. It is not uncommon to see a variable
declared as a pointer to a pointer, sometimes called a double pointer. A good example
of this is when program arguments are passed to the main function using the tradition‐
ally named argc and argv parameters. This is discussed in more detail in Chapter 5.
The example below uses three arrays. The first array is an array of strings used to hold
a list of book titles:*/

    char *titles[] = {"A Tale of Two Cities",
                      "Wuthering Heights", "Don Quixote",
                      "Odyssey", "Moby-Dick", "Hamlet",
                      "Gulliver's Travels"};
    /*char *titles[] declares an array of character pointers, where each element is a pointer to a character array, typically used to represent strings. Each element points to the first character of a string (not just a single character).
     */

    /*Two additional arrays are provided whose purpose is to maintain a list of the “best
 and English books. Instead of holding copies of the titles, they will hold theaddress of a title in the titles array. Both arrays will need to be declared as a pointerto a pointer to a char. The array’s elements will hold the addresses of the titles array’selements. This will avoid having to duplicate memory for each title and results in a singlelocation for titles. If a title needs to be changed, then the change will only have to beperformed in one location.The two arrays are declared below. Each array element contains a pointer that points toa second pointer to char:*/

    char **bestBooks[3];
    char **englishBooks[4]; // the ** indicates that you are working with pointers that point to other pointers (strings).

    /*The two arrays are initialized and one of their elements is displayed, as shown below.In the assignment statements, the value of the righthand side is calculated by applyingthe subscripts first, followed by the address-of operator. For example, the second state‐ment assigns the address of the fourth element of titles to the second element of:*/

    bestBooks[0] = &titles[0];
    bestBooks[1] = &titles[3];
    bestBooks[2] = &titles[5];

    englishBooks[0] = &titles[0];
    englishBooks[1] = &titles[1];
    englishBooks[2] = &titles[5];
    englishBooks[3] = &titles[6];

    printf("%s\n", *englishBooks[1]); // Wuthering Heights
}
/*To clarify the difference between an array of character pointers and an array of characters:

1. **Array of Character Pointers (Strings)**:

   - An array of character pointers is commonly used to store strings in C.
   - Each element of the array is a pointer to a character (char pointer).
   - Strings are typically represented as arrays of characters (char arrays) that are null-terminated, and each element of the array points to the first character of a string.
   - You can easily work with and manipulate strings using standard string manipulation functions, like `strcpy`, `strlen`, `strcmp`, etc.

   Example:
   ```c
   char *titles[] = {
       "A Tale of Two Cities",
       "Wuthering Heights",
       "Don Quixote"
   };
   ```

2. **Array of Characters (Char Arrays)**:

   - An array of characters (char arrays) is a sequence of characters stored in consecutive memory locations.
   - It's not necessarily used to store strings in the same way as character pointers; it's more like a buffer for raw characters.
   - You need to manually manage the null-termination and other aspects of string handling.
   - Typically, you declare a fixed-size array of characters when you know the maximum length of the content.

   Example:
   ```c
   char title1[50] = "A Tale of Two Cities";
   char title2[50] = "Wuthering Heights";
   char title3[50] = "Don Quixote";
   ```

In summary, an array of character pointers (strings) is more commonly used for representing and working with strings because it provides a convenient way to manage and manipulate text data. On the other hand, an array of characters (char arrays) is used for raw character storage and isn't inherently suited for string manipulation. The choice between them depends on your specific needs and how you intend to work with the data.*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*I apologize for any confusion. In C, when we say that each element of an array of character pointers points to the first character of a string, it means that each element of the array holds the memory address of the first character of a string. Here's an example with clarifications:

```c
char *titles[] = {
    "A Tale of Two Cities",    // Element 0
    "Wuthering Heights",       // Element 1
    "Don Quixote"             // Element 2
};
```

In this example:

- `titles` is an array of character pointers.
- Each element of `titles` is a pointer to the first character of a string.

So, in the case of "A Tale of Two Cities," `titles[0]` points to the memory address where the 'A' character is stored. Similarly, `titles[1]` points to the memory address where the 'W' character is stored, and `titles[2]` points to the memory address where the 'D' character is stored.

This is how each element of the array points to the first character of a string. It allows you to work with and manipulate the entire string through the pointer to the first character.*/

/*Character pointers (char pointers) are fundamental in C and are commonly used to work with strings and character data. A character pointer is a data type that stores the memory address of a character (char) or a sequence of characters (a string). Here are the key points about character pointers:

1. **Declaration**: You declare a character pointer using the `char *` syntax. For example:

    ```c
    char *str;
    ```

2. **Initialization**: You can initialize a character pointer to point to a character or a string:

    ```c
    char *ch = "A";        // Points to a single character
    char *str = "Hello";   // Points to a string
    ```

3. **Accessing Characters**: You can access individual characters in a string using pointer arithmetic:

    ```c
    char *str = "Hello";
    char first_char = *str;  // 'H'
    char second_char = *(str + 1);  // 'e'
    ```

4. **String Manipulation**: Character pointers are often used to manipulate strings, and C provides a set of string manipulation functions, such as `strcpy`, `strlen`, `strcat`, etc., to work with character pointers and strings.

5. **Null-Terminated Strings**: In C, strings are typically represented as arrays of characters with a null terminator (`'\0'`) at the end. Character pointers are used to point to the first character of such null-terminated strings.

6. **Dynamic Memory Allocation**: Character pointers are used when dynamically allocating memory for strings using functions like `malloc` and `strdup`.

7. **Arrays of Character Pointers**: You can create arrays of character pointers to manage multiple strings or an array of strings.

Character pointers are fundamental for working with text data in C, and understanding how to use them is essential for many programming tasks in C.*/
