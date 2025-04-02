#include <iostream>
#include <iomanip>

void exp1(){
	int a=7, b=1, c=10, d;
	d =(a++ && b++) || --c;
	std::cout << "\nExperiment 1: "<< a << b << c << d << "\n";
}

void exp2(){
	int i = 0, j =1, m;
	m = i++ || j++;
	std::cout << "\nExperiment 2: " << m << i << j << "\n";
}

void exp3(){
	int i = 7, m, n;
	m = i++;
	n = ++i;
	std::cout << "\nExperiment 3: " << m << n << i << "\n";
}

void exp4(){
	int x = 10, y = 20, z = 4;
	z = x > y ? x : y;
	std::cout << "\nExperiment 4: " << z << "\n";
}

void exp5(){
	int i = 0;
	std::cout << "\nExperiment 5: ";
	while(i < 5)
	{
		std::cout << i ;
		i++;
	}
	std::cout << "\n";
}

void exp6(){
	int a = 3, b = 4;
	std::cout << "\nExperiment 6:" << a << &b << "\n";
}

int main(){
	exp1();
	exp2();
	exp3();
	exp4();
	exp5();
	exp6();
	return 0;
}
