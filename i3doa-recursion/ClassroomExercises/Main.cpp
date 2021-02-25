#include<iostream>
#include "ClassroomExercises.h"
using namespace std;
#include<fstream>
using namespace std;

int main()
{
	//==================================
	// Test num
	//int n = 0;
	//cout << "num() test" << endl; 
	//cout << "num(7) is: " << endl;
	//num(7);
	//cout << endl;
	//==================================

	////==================================
	//// Test hanoi()
	//int nDisks = 0;
	//do
	//{
	//	cout << "HANOI'S TOWERS: Enter number of disks to move: ";
	//	cin >> nDisks;
	//	hanoi(nDisks, 1, 3, 2);
	//} while (nDisks > 0);

	//==================================
	printf("printDownTo1: \n");
	printDownTo1(6);
	printf("fib:\n");
	printf("%u",fib(0));

	
	// Test Fibomacci()
	/*int n = 0;
	do
	{
		cout << "FINBOACCI: Enter number: ";
		cin >> n;
		cout << "fib(n) = " << fib(n) << endl;
	} while (n >= 0);

	return 0;*/

}