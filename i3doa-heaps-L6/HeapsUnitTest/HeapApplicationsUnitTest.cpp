#include "pch.h"

#include <gtest/gtest.h>
#include "../Heaps/HeapApplications.h"

TEST(Select, Select_Kis1_SmallestElementReturned)
{
	vector<int> ar = { 5,4,3,7,6,5 };
	ASSERT_EQ(select(1, ar), 3);
}


TEST(Select, Select_Kis2_SecondSmallestElementReturned)
{
	vector<int> ar = { 5,4,3,7,6,5 };
	ASSERT_EQ(select(2, ar), 4);
}

TEST(Select, Select_Kis4_SecondSmallestElementReturned)
{
	vector<int> ar = { 5,4,3,7,6,5 };
	ASSERT_EQ(select(4, ar), 5);
}

TEST(Select, Select_KisArraySize_LargestElementReturned)
{
	vector<int> ar = { 5,4,3,7,6,5 };
	ASSERT_EQ(select(6, ar), 7);
}
TEST(Select, Select_Kis0_ExceptionThrown)
{
	vector<int> ar = { 5,4,3,7,6,5 };
	EXPECT_THROW({
		select(0, ar);
		}, std::invalid_argument);
}

TEST(Select, Select_KisLargerThanArray_ExceptionThrown)
{
	vector<int> ar = { 5,4,3,7,6,5 };
	EXPECT_THROW({
		select(7, ar);
		}, std::invalid_argument);
}

TEST(Select, Select_SourceRemainsUntouched)
{
	vector<int> ar = { 5,4,3,7,6,5 };
	vector<int> ar2(ar);
	select(6, ar);
	ASSERT_TRUE(ar == ar2);
}


TEST(Heapsort, Heapsort_ArrayIsSorted)
{
	vector<int> ar = { 5,4,3,7,6,5 };
	heapsort(ar);

	bool isSorted = true;
	for (int i=0; i < ar.size()-1; i++)
	{
		if (ar[i] > ar[i + 1]) isSorted = false;
	}
	ASSERT_TRUE(isSorted);
}