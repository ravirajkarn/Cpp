// C++ Code to swap two numbers using bitwise XOR

#include <iostream>

using namespace std;

int main() 
{
	int a = 2, b = 3;
	cout << "a = " << a << " b = " << b << endl;   

	// Bitwise XOR mathord: 	
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	// end

	cout << "a = " << a << " b = " << b << endl;
                                 
	return 0;                              
}
                                  
