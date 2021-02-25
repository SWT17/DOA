#include<iostream>
#include "LabExercises.h"
using namespace std;
#include<fstream>
using namespace std;

int main()
{
	const unsigned int n = 5;
	int Ar[n] = { 1,2,3,4,5};
	int* p = Ar;
	bool res = SearchAnArray(p,3,3);

	printf("%d", res);

}