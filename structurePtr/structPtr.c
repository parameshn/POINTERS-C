// Introduction
main()
{
    /*A structure in C can be declared in a number of ways. In this section we will only examine
    two approaches, as our focus is on their use with pointers. In the first approach, we
    declare a structure using the struct keyword. In the second approach, we use a type
    definition. In the following declaration, the structure’s name is prefixed with an under‐
    score. This is not necessary but is often used as a naming convention. The _person
    structure includes fields for name, title, and age:*/
    struct _person
    {
        char *firstName;
        char *lastName;
        char *title;
        unsigned int age;
    };
    /*A structure’s declaration frequently uses the typedef keyword to simplify its use later
    in a program. The following illustrates its use with the _person structure:*/
    typedef struct _person
    {
        char *firstName;
        char *lastName;
        char *title;
        unsigned int age;
    } Person;
    // An instance of a person is declared as follows:
    Person person;
    // Alternately, we can declare a pointer to a Person and allocate memory for it, as shown below:
    Person *ptrPerson;
    ptrPerson = (Person *)malloc(sizeof(Person));

    /*If we use a simple declaration of a structure as we did with person, we use the dot
    notation to access its fields. In the following example, we assign values to the first
    Name and age fields:
    */
    Person person;
    person.firstName = (char *)malloc(strlen("Emily") + 1);
    strcpy(person.firstName, "Emily");
    person.age = 23;

    /*However, if we are using a pointer to a structure, we need to use the points-to operator,
as follows. This operator consists of a dash followed by the greater than symbol:
*/
    Person *ptrPerson;
    ptrPerson = (Person *)malloc(sizeof(Person));
    ptrPerson->firstName = (char *)malloc(strlen("Emily") + 1);
    strcpy(ptrPerson->firstName, "Emily");
    ptrPerson->age = 23;
    /*We do not have to use the points-to operator. Instead, we can dereference the pointer
first and then apply the dot operator. This is illustrated below, where we duplicate the
previous assignments:*/
    Person *ptrPerson;
    ptrPerson = (Person *)malloc(sizeof(Person));
    (*ptrPerson).firstName = (char *)malloc(strlen("Emily") + 1);
    strcpy((*ptrPerson).firstName, "Emily");
    (*ptrPerson).age = 23;

    // This approach is more awkward but you may see it used at times.
}