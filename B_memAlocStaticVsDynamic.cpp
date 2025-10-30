// https://www.geeksforgeeks.org/difference-between-static-and-dynamic-memory-allocation-in-c/
// https://www.geeksforgeeks.org/what-is-dynamic-memory-allocation/

// Memory Allocation: process by which computer programs and services are assigned with physical or virtual memory space. 
// It is done either before or at the time of program execution. There are two types of memory allocations: 

// Compile-time or Static Memory Allocation: allocated for declared variables by the compiler during compile time.
// The address can be found using the address of operator and can be assigned to a pointer. 
// Uses the stack memory and is less efficient but executes faster.

// Run-time or Dynamic Memory Allocation: allocated during execution (run) time and assigned to pointer variables.
// Functions calloc() and malloc() support allocating dynamic memory which is controlled by the programmer.
// Uses the heap memory and is more efficient (allows memmory reusability) but executes slower.

#include <iostream>



int main() 
{ 
    int *ptr1 = new int(42); 
    int *ptr2 = new int[10]; // can't initialize dynamic array with values
    int *ptr3 = ptr2; 

    std::cout<<*ptr1<<std::endl; // prints: 42
    std::cout<<*ptr2<<std::endl; // prints: 0
    std::cout<<*ptr2<<" "<<*(ptr2+1)<<std::endl; // prints: 0 0

    ptr2[0] = 7;
    ptr2[1] = 8;

    std::cout<<*ptr2<<std::endl; // prints: 7
    std::cout<<*ptr2<<" "<<*(ptr2+1)<<std::endl; // prints: 7 8

    ptr3++;

    std::cout<<*ptr3<<std::endl; // prints: 8

    delete ptr1; 
    delete [] ptr2; 
} 