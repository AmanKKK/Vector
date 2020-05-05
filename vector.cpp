#include <iostream>
#include "MyVector.h"

using namespace std;

int main()
{
	MyVector test1(3, ResizeStrategy::MULTIPLICATIVE);
	cout << test1.capacity() << '\n';
	cout << test1.size() << '\n';
	test1.pushBack(4);
	cout << "--------------" << "\n";
	cout << test1.capacity() << " " << test1.size() << "\n";
	test1.PrintData();
	test1.insert(2,14);
	cout << "\n";
	test1.PrintData();
	cout << '\n';
	test1.insert(1, 32);
	test1.popBack();
	test1.PrintData();

	
	
	
	

	return 0;
}