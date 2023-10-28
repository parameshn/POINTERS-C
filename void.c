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
}
