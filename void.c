#include <stdlib.h>
#include <stdio.h>
main()
{
    // int num;
    // int *pi = &num;
    // printf("Value of pi: %p\n", pi);
    // void *pv = pi;
    // pi = (int *)pv;
    // printf("Value of pi: %p\n", pi);

    size_t sizet = -5;
    printf("%d\n", sizet);
    printf("%zu\n", sizet);

    sizet = 5;
    printf("%d\n", sizet);
    printf("%zu\n", sizet);
    printf("the size of *char =%d\n", sizeof(char *));

    int num;
    // intptr_t *pi = &num;
    // uintptr_t *pu = &num;

    intptr_t *pi = &num;
    uintptr_t *pu = (uintptr_t *)&num;

    int vector[] = {12, 21, 33};
    int *pa = &vector;

    printf("%d\n", *pa);

    pa += 1;
    printf("%d\n", *pa);
    pa += 1;
    printf("%d\n", *pa);

    pi = vector + 2;
    printf("%d\n", *pa);

    pi = vector;
    pi += 3;
    printf("%d\n", *pa);

    short s;
    short *ps = &s;

    char c;
    char *pc = &c;

    printf("content of the ps before : %d\n", ps);
    ps = ps + 1;
    printf("content of the ps after: %d\n", ps);

    printf("Content of pc before: %d\n", pc);
    pc = pc + 1;
    printf("Content of pc after: %d\n", pc);
}
