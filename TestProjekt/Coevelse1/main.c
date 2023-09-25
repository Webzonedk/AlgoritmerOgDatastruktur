#include <stdio.h>
#include <stdlib.h>

int main()
{
    Exercise1();
    Exercise2();
    Exercise2();
    Exercise4();
    Exercise5();
    Exercise6();
    Exercise7();
    Exercise8();
    Exercise9();

    return 0;
}

// 1. Basic Pointers. Declare a variable and a pointer, set the pointer to the address of the variable and print the value of the variable,
// then change the value of the variable through the pointer and print the value of the variable again.
void Exercise1()
{
    printf("\n1_basic Pointers:\n");
    int variable = 10;
    int *pointer = &variable;
    printf("first: %d\n", variable);
    *pointer = 20;
    printf("second: %d\n", variable);
    *pointer = 30;
    printf("last: %d\n", variable);
    return 0;
}

// 2. Pointer to Pointer. Declare a variable and a pointer, set the pointer to the address of the variable and print the value of the variable,
void Exercise2()
{
    printf("\n2_Pointer To Pointer\n");
    int variable = 10;
    printf("variable: %d\n", variable);
    int *pointer1 = &variable;
    printf("pointer1: %d\n", *pointer1);
    int **pointer2 = &pointer1;
    printf("pointer2: %d\n", **pointer2);
    int variable2 = **pointer2 * 3;
    printf("variable2: %d\n", variable2);
    return 0;
}

// 3. Swap. Declare two variables and two pointers, set the pointers to the addresses of the variables and swap the values of the variables through the pointers.
void Exercise3()
{
    printf("\n3_Swap\n");
    int a = 10, b = 20;
    printf("before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("after swap: a = %d, b = %d\n", a, b);
    return 0;
}

// Method to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 4. Pointer Arithmetic. Declare an array of 5 integers, declare a pointer and set it to the address of the array,
void Exercise4()
{
    printf("\n4_Pointer Aritmetik\n");
    int array[5] = {1, 2, 3, 4, 5};
    int *pointer = array;
    printf("array: %d\n", *pointer);
    printf("array: %d\n", *(pointer + 1));
    printf("array: %d\n", *(pointer + 2));
    printf("array: %d\n", *(pointer + 3));
    printf("array: %d\n", *(pointer + 4));
    printf("array: %d\n", *(pointer + 5)); // overflow
    printf("array: %d\n", *(pointer + 6)); // overflow
    printf("array: %d\n", *(pointer + 7)); // overflow
    return 0;
}

// 5. Dynamic Memory Allocation. Declare a pointer and allocate memory for 5 integers, set the values of the integers through the pointer,
void Exercise5()
{
    printf("\n5_Dynamic Memmory Allocation\n");

    int count = 5;
    int *array = (int *)malloc(count * sizeof(int));
    if (array == NULL)
    {
        printf("Error: memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < count; i++)
    {
        array[i] = i * i;
    }
    for (int i = 0; i < count; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }
    printf("\n");
    free(array);
    return 0;
}

// 6. Pointers and Functions. Declare an array of 5 integers, declare a pointer and set it to the address of the array,
void Exercise6()
{
    printf("\n6_Pointers And Functions\n");
    int array[5] = {1, 2, 3, 4, 5};
    int(*pointer)[5] = array;
    int n = sizeof(array) / sizeof(array[0]);
    printf("sum = %d\n", Summerize(array, n));
}

// Method to sum up the array
int Summerize(int *array, int n)
{
    int sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum += array[i];
    }
    return sum;
}

// 7. Copy String. Declare a string, declare a pointer and allocate memory for the string, copy the string to the allocated memory,
void Exercise7()
{
    printf("\n7_Copy String\n");
    char *string = "Hello World!";
    char *copy = (char *)malloc(strlen(string) + 1);
    if (copy == NULL)
    {
        printf("Error: memory allocation failed!\n");
        return 1;
    }
    strcpy(copy, string);
    printf("copy = %s\n", copy);
    free(copy);
    return 0;
}

// 8. Length of String. Declare a string, declare a pointer and set it to the address of the string, calculate the length of the string through the pointer.
void Exercise8()
{
    printf("\n8_lengt Of String\n");
    char *string = "Hello World!";
    printf("length with strlen: = %d\n", strlen(string));
    char *pointer = string;
    int length = 0;
    while (*pointer != '\0')
    {
        length++;
        pointer++;
    }
    printf("length calculated with pointer = %d\n", length);
    return 0;
}

// 9. Reverse Array. Declare an array of 5 integers, declare a pointer and set it to the address of the array,
void Exercise9()
{
    printf("\n9_Reverse Array\n");
    int array[5] = {1, 2, 3, 4, 5};
    int length = sizeof(array) / sizeof(array[0]);
    ReverseArray(array, length);

    for (int i = 0; i < length; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}

// Method to reverse the array
void ReverseArray(int *array, int length)
{
    int *startPointer = array;
    int *endPointer = array + length - 1;
    while (startPointer < endPointer)
    {
        int temp = *startPointer;
        *startPointer = *endPointer;
        *endPointer = temp;
        startPointer++;
        endPointer--;
    }
}