/**
 * @file array_decay.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-05-19
 * 
 * @copyright Copyright (c) 2025
 * 
 * 
 * What is Array Decay? 
	The loss of type and dimensions of an array is known as decay of an array. This generally occurs when we pass the array into function by value or pointer. What it does is, it sends first address to the array which is a pointer, hence the size of array is not the original one, but the one occupied by the pointer in the memory.

How to prevent Array Decay? 
	- A typical solution to handle decay is to pass size of array also as a parameter and not use sizeof on array parameters (See this for details)
	- Another way to prevent array decay is to send the array into functions by reference. This prevents conversion of array into a pointer, hence prevents the decay. 
	- We can also preserve the size of the array by passing it as a pointer to the array which have one more dimension as compared to our array

In summary, the best approaches to prevent array decay, especially in C++, are:
	• Passing by reference using template parameters. This is type-safe and preserves the exact array size.
	• Using std::array. This provides a safer and more convenient way to work with fixed-size arrays without decay

 * 
 */

#include <iostream>
#include <array>

using namespace std;

// array by value 
void arrayByValueDecay(int *pointer){
	// Print size
	cout << "size of array using array by value: ";
	cout << sizeof(pointer) << endl;
}

// array by pointer 
void arrayByPointerDecay(int (*pointer)[10]){
	// Print size 
	cout << "size of array using array by pointer: ";
	cout << sizeof(pointer) << endl;
}

// TODO: Solution
// * Prevent array decay

// TODO: METHOD 1: prevent array decay is to send the array into functions by reference (only fixed size arrays)
// * This is done by using a reference to an array of a fixed size
void by_reference(int (&p)[10]){
	 // Printing size of array
    cout << "Modified size of array by passing by reference: ";
    cout << sizeof(p) << endl;
}

// * by using a template function
template <size_t N>
void by_reference_template(int (&p)[N]){
	// Printing size of array
	cout << "Modified size of array by passing by reference: ";
	cout << sizeof(p) << endl;
}

// * by using a template function
template <typename T, size_t N>	
void by_reference_template2(T (&p)[N]){
	// Printing size of array
	cout << "Modified size of array by passing by reference: ";
	cout << sizeof(p) << endl;
}

// TODO: METHOD 2: prevent array decay is to send the array into functions by pinter
// * This is done by using a pointer to an array of a fixed size
void by_pointer(int (*p)[10]){
	// Printing size of array
	cout << "Modified size of array by passing by pointer: ";
	cout << sizeof(p) << endl;
}

// * by using a template function
template <size_t N>
void by_pointer_template(int (*p)[N]){
	// Printing size of array
	cout << "Modified size of array by passing by pointer: ";
	cout << sizeof(p) << endl;
}

// * by using a template function
template <typename T, size_t N>
void by_pointer_template2(T (*p)[N]){
	// Printing size of array
	cout << "Modified size of array by passing by pointer: ";
	cout << sizeof(p) << endl;
}

// * by using std::array
template <typename T, size_t N>
void by_reference_with_array(std::array<T, N> &p){
	// Printing size of array
	cout << "Modified size of array by passing by reference with std::array: ";
	cout << sizeof(p) << endl;
}

int main(){
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	char array2[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

	std::array<int,10> array3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for(const auto &i : array){
		cout << i << " ";
	}

	cout << "\nSize of array (sizeof(int)*10): ";
	cout << sizeof(array) << endl;

	// Passing array by value 
	arrayByValueDecay(array);

	// passing array by pointer 
	arrayByPointerDecay(&array);

	// Modified size of array by passing by reference
	by_reference(array);

	by_reference_template(array);

	by_reference_template2(array);

	by_reference_with_array(array3);

	// Modified size of array by passing by pointer
	by_pointer(&array); //! error
	
	by_pointer_template(&array); //! error
	
	
	{std::cout << "\n\n\n";

	for(const auto &i : array2){
		cout << i << " ";
	}

	cout << "\nSize of array2 (sizeof(char)*8): ";
	cout << sizeof(array2) << endl;

	by_reference_template2(array2);

	by_pointer_template2(&array2);}

	return 0;
}
