#include "pch.h"
#include"../LabExercises/LabExercises.cpp"


TEST(SearchAnArray, SearchAnArray_numberIsPresent_true)
{
	const unsigned int n = 5;
	int arr[5] = { 1,2,3,4,5};
	int* p = arr;
	bool res = SearchAnArray(p,3,3);

	ASSERT_EQ(true, res);

}

TEST(SearchAnArray, SearchAnArray_numberIsNotPresent_false)
{
	//n is number of entries in the array to search, starting from index = 0 going to n-1.
	const unsigned int n = 5;
	int arr[5] = { 1,2,3,4,5 };
	int* p = arr;

	int NumberToBeFound = 8;
	bool res = SearchAnArray(p, NumberToBeFound, n);

	ASSERT_EQ(false, res);
}

TEST(SearchAnArray, SearchAnArray_NumberPresentSearchLengthTooShort_false)
{
	//n is number of entries in the array to search, starting from index = 0 going to n-1.
	const unsigned int n = 3;
	int arr[5] = { 1,2,3,4,5 };
	int* p = arr;

	int NumberToBeFound = 4;
	bool res = SearchAnArray(p, NumberToBeFound, n);

	ASSERT_EQ(false, res);
}

TEST(BinarySearch, SearchForElement_ElementIsInVector_true)
{
	vector<int> vec;

	//Sorted list of elements
	for (int i = 0; i < 2000;i++)
	{
		vec.push_back(i);
	}

	int numberToBeFound = 500;

	bool res = BinarySearchFunc(vec, 500);

	ASSERT_EQ(true, res);
}
