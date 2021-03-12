#include "pch.h"
#include<random>
#include"..\i3doa-sorting\Quicksort.h"


class QuicksortUnitTest : public ::testing::Test
{
protected:
	const int SIZE;
	int* testar;

	QuicksortUnitTest() : SIZE(100000) {}

	void SetUp()
	{
		testar = new int[SIZE];

		// Ensure array is unsorted
		if (SIZE > 1)
		{
			while (isSorted(testar, SIZE))
			{
				for (int i = 0; i < SIZE; i++)
					testar[i] = rand() % SIZE;
			}
		}
	}

	void TearDown()
	{
		delete[] testar;
	}

	template <typename T>
	bool isSorted(T data[], int n)
	{
		for (int i = 0; i < n - 1; i++)
			if (data[i] > data[i + 1]) return false;
		return true;
	}

};

TEST_F(QuicksortUnitTest, QuickSort_EmptyArray_NoError)
{
	quicksort(testar, 0);
}

TEST_F(QuicksortUnitTest, QuickSort_SingleElementArray_NoError)
{
	quicksort(testar, 1);
}

TEST_F(QuicksortUnitTest, QuickSort_CompleteArray_IsSorted)
{
	quicksort(testar, SIZE);
	EXPECT_TRUE(isSorted(testar, SIZE));
}

