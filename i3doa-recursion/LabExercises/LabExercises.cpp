#include "framework.h"
#include "LabExercises.h"


/*
* Search an array through the first n elements for an integer of value x. If it is found, return true. Otherwise return false.
* Pre condition - Array is of size greater than 0, x is same type as Array and n<=arraysize
* post condition - return true if x is present in the n'th first elements of the array - false if not.
*/

/*
* Find the recursive problem:
* 
* 1. Size and complexity is n - since we have n elements to traverse through.
* 2. BaseCase must be n=0, since going thorugh the whole n elements didnt find the x value. Return must be false
*/
bool SearchAnArray(int* ar, unsigned int x,unsigned int n)
{
	if (n == 0)
	{
		return false;
	}
	else
	{
		if (ar[n] == x)
		{
			return true;
		}
		else
		{
			SearchAnArray(ar, x, n - 1);
		}
	}
}
