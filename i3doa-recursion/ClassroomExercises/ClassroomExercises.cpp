#include "ClassroomExercises.h"
#include <iostream>


unsigned int factorial(unsigned int n)
{
	return 1;
}



void printDownTo1(unsigned int n)
{
	/*
	* a)
	* Ja det inkludere jo, at man skal kunne printe et enkelt tal af gangen, og kan man gøre det for alle tallene jamen så kan man løse opgaven
	* 
	* Base case er n=1 , hvor der kun er 0 at printe.
	* Sørg også for, at den printe n og ned til 1.
	*/
	if (n == 1)
	{
		printf("1\n");
	}
	else
	{
		printf("%u\n", n);
		printDownTo1(n - 1);
		
	}
	
	

}


double power(int x, int exp)
{
	return 1;
}


unsigned int fib(unsigned int n)
{
	return 1;
}

void hanoi(int nDisks, int from, int to, int via)
{
	
}
