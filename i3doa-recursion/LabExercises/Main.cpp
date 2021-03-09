#include<iostream>
#include "LabExercises.h"
using namespace std;
#include<fstream>
#include<vector> // Vektor
#include<algorithm> //Giver mig sort funktionen
#include <chrono> //StopWatch
using namespace std;

int main()
{
	/*const unsigned int n = 5;
	int Ar[n] = { 1,2,3,4,5};
	int* p = Ar;
	bool res = SearchAnArray(p,3,3);

	printf("%d", res);*/


	int NUmberOfElements = 2000000;
	int numberToBeFound = NUmberOfElements;

	//Setup Vector
	vector<int> vec;

	//Sorted list of elements
	for (int i = 0; i < NUmberOfElements;i++)
	{
		vec.push_back(i);
	}

	0;

	// Start measuring time
	auto begin = std::chrono::high_resolution_clock::now();

	BinarySearchFunc(vec, numberToBeFound);

	// Stop measuring time and calculate the elapsed time
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	printf("Binary searchtime measured: %.10f seconds.\n", elapsed.count() * 1e-9);

	// Start measuring time
	auto begin2 = std::chrono::high_resolution_clock::now();
	for (int x : vec)
	{
		if (x == numberToBeFound)
		{
			break;
		}
	}

	// Stop measuring time and calculate the elapsed time
	auto end2 = std::chrono::high_resolution_clock::now();
	auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);

	printf("Iterative searchtime measured: %.10f seconds.\n", elapsed2.count() * 1e-9);


	//Lige meget hvad synes jeg den binære søgefunktion er den langsomste.
	//Søger kompleksiteten er log(n).
}