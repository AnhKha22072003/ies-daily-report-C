C Memory Address
-When a variable is created in C, its value is stored somewhere in the computer's memory.
-A variable that stores a memory address is called a pointer.
-To get the address of a variable, we use the & operator.
exm: pointer=&var;
C Pointer
-Memory allocation cannot be performed without using pointers.
-A pointer is a variable whose value is the address of another variable.
-A null pointer has a value of 0 in some libraries.
exm
int myAge = 43;     // Variable declaration
int* ptr = &myAge;  // Pointer declaration

// Reference: Output the memory address of myAge with the pointer (0x7ffe5367e044)
printf("%p\n", ptr);

// Dereference: Output the value of myAge with the pointer (43)
printf("%d\n", *ptr);
int myAge = 43;
int* ptr = &myAge;
printf("%d\n", *ptr);

-myAge=43
-&myAge=0x7ffe5367e044
-*ptr=0x7ffe5367e044 -> 43
-ptr=0x7ffe5367e044

-int* a, b; creates a pointer named a, and a normal int named b. To create two pointers, write int *a, *b;

Pointers and Arrays
-the name of an array works as a pointer to the first element of the array.

int myNumbers[4] = {25, 50, 75, 100};
// Get the memory address of the myNumbers array
printf("%p\n", myNumbers);

// Get the memory address of the first array element
printf("%p\n", &myNumbers[0]);

0x7ffe70f9d8f0
0x7ffe70f9d8f0

printf("%d", *myNumbers);
25
printf("%d\n", *(myNumbers + 1));
50


-strings are actually arrays, you can also use pointers to access strings.

Pointer Arithmetic
-Pointer arithmetic means changing the value of a pointer to make it point to a different element in memory.
int myNumbers[4] = {25, 50, 75, 100};
int *p = myNumbers;  // points to myNumbers[0]

printf("%d\n", *p);       // 25
printf("%d\n", *(p + 1)); // 50
printf("%d\n", *(p + 2)); // 75
printf("%d\n", *(p + 3)); // 100

