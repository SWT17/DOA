#include<iostream>
#include "LabExercises.h"
using namespace std;
#include<fstream>
using namespace std;

int main()
{
	const unsigned int n = 6;
	int Ar[n] = { 1,2,3,4,5,6 };
	int* p = Ar;

	SearchAnArray(p, 3, n);

}