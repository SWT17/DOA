#include "pch.h"
#include"../ClassroomExercises/ClassroomExercises.cpp"

TEST(Factorial, FactorialIsCorrect) 
{
	ASSERT_EQ(factorial(0), 1);
	ASSERT_EQ(factorial(1), 1);
	ASSERT_EQ(factorial(10), 3628800);
}

TEST(Power, PowerIsCorrect)
{
	ASSERT_EQ(power(0, 0), 1);
	ASSERT_EQ(power(0, 2), 0);

	ASSERT_EQ(power(1, 0), 1);
	ASSERT_EQ(power(1, 1), 1);
	ASSERT_EQ(power(1, 3), 1);
	
	
	ASSERT_EQ(power(-1, 0), 1);
	ASSERT_EQ(power(-1, 1), -1);
	ASSERT_EQ(power(-1, 3), -1);

	ASSERT_EQ(power(3, 0), 1);
	ASSERT_EQ(power(3, 1), 3);
	ASSERT_EQ(power(3, 4), 81);

	ASSERT_EQ(power(-3, 0), 1);
	ASSERT_EQ(power(-3, 1), -3);
	ASSERT_EQ(power(-3, 4), 81);

	ASSERT_EQ(power(0, -1), INFINITY);
	ASSERT_EQ(power(1, -1), 1);
	ASSERT_EQ(power(2, -3), 0.125);
	ASSERT_EQ(power(-2, -3), -0.125);
}


TEST(Fibonacci, FibIsCorrect)
{
	ASSERT_EQ(fib(0), 0);
	ASSERT_EQ(fib(1), 1);
	ASSERT_EQ(fib(2), 1);
	ASSERT_EQ(fib(5), 5);
	ASSERT_EQ(fib(8), 21);
}
