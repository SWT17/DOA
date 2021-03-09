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


double power(double x, double exp)
{
	/*The problem complexity is "exp" since this is the number of times we will need to do muliplication*/
	//Base case must be exp = 0 which returns 1;

	/*For positive intergers*/
	if (exp >= 0)
	{
		if (exp == 0)
		{
			return 1;
		}

		/*The recursive solution is seeing that the rest is just x * x^(exp-1)
		This also ensures that for positive integers we will reach the base case*/

		return x * power(x, exp - 1);
	}
	
	/*For negative integers*/
	if (exp == 0)
	{
		return 1;
	}
	return(1 / x) * power(x,exp + 1);

	

	
}


unsigned int fib(unsigned int n)
{
	if (n < 2)
	{
		return n;
	}
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
	
}

void hanoi(int nDisks, int from, int to, int via)
{
	
}
