/*Function Pointers


A function pointer is a pointer that holds the address of a function. The ability of pointers
to point to functions turns out to be an important and useful feature of C. This provides
us with another way of executing functions in an order that may not be known at compile
time and without using conditional statements.
One concern regarding the use of function pointers is a potentially slower running
program. The processor may not be able to use branch prediction in conjunction with
pipelining. Branch prediction is a technique whereby the processor will guess which
multiple execution sequences will be executed. Pipelining is a hardware technology
commonly used to improve processor performance and is achieved by overlapping
instruction execution. In this scheme, the processor will start processing the branch it
believes will be executed. If the processor successfully predicts the correct branch, then
the instructions currently in the pipeline will not have to be discarded.
This slowdown may or may not be realized. The use of function pointers in situations
such as table lookups can mitigate performance issues. In this section, we will learn how
to declare function pointers, see how they can be used to support alternate execution
paths, and explore techniques that exploit their potential.*/