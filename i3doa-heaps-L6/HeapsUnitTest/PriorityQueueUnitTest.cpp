#include "pch.h"

#include <gtest/gtest.h>
#include "../PriorityQueue/MinHeapPriorityQueue.h"


class PriorityQueueUnitTest : public ::testing::Test
{
protected:

	void SetUp()
	{
		uut = new MinHeapPriorityQueue<int>();
	}

	void TearDown()
	{
		delete uut;
	}

	PriorityQueue<int>* uut;
};


TEST_F(PriorityQueueUnitTest, Ctor_VanillaPQ_PQIsEmpty)
{
	ASSERT_TRUE(uut->isEmpty());
}


TEST_F(PriorityQueueUnitTest, Ctor_OneElementpushed_PQIsNotEmpty)
{
	uut->push(2);
	ASSERT_FALSE(uut->isEmpty());
}


TEST_F(PriorityQueueUnitTest, front_OneElementpushed_CorrectElementInfront)
{
	uut->push(2);
	ASSERT_EQ(2, uut->front());
}

TEST_F(PriorityQueueUnitTest, front_OneElementpushedTwofronts_CorrectElementInfront)
{
	uut->push(2);
	uut->front();
	ASSERT_EQ(2, uut->front());
}


TEST_F(PriorityQueueUnitTest, push_TwoElementpushed_CorrectElementInfront)
{
	uut->push(2);
	uut->push(3);
	ASSERT_EQ(2, uut->front());
}


TEST_F(PriorityQueueUnitTest, pop_OneElementpushed_PQIsEmpty)
{
	uut->push(2);
	uut->pop();
	ASSERT_TRUE(uut->isEmpty());
}


TEST_F(PriorityQueueUnitTest, pop_TwoElementspushedOnepopd_PQIsNotEmpty)
{
	uut->push(2);
	uut->push(3);
	uut->pop();
	ASSERT_FALSE(uut->isEmpty());
}

TEST_F(PriorityQueueUnitTest, pop_TwoElementspushedTwopopd_PQIsEmpty)
{
	uut->push(2);
	uut->push(3);
	uut->pop();
	uut->pop();
	ASSERT_TRUE(uut->isEmpty());
}
TEST_F(PriorityQueueUnitTest, pop_TwoElementspushedOnepopd_CorrectElementInfront)
{
	uut->push(2);
	uut->push(3);
	uut->pop();
	ASSERT_EQ(3, uut->front());
}

TEST_F(PriorityQueueUnitTest, push_FourElementspushedUnOrdered_CorrectElementInfront)
{
	uut->push(5);
	uut->push(15);
	uut->push(3);
	uut->push(5);
	ASSERT_EQ(3, uut->front());
}

TEST_F(PriorityQueueUnitTest, push_FourElementspushedOnepopd_CorrectElementInfront)
{
	uut->push(5);
	uut->push(15);
	uut->push(4);
	uut->push(10);
	uut->pop();
	ASSERT_EQ(5, uut->front());
}
