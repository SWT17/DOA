#include"pch.h"
#include "../BST/BST.h"

class BSTToolkitUnitTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
	}

	void TearDown() override
	{
	}

	BST<int> uut;
	BST<int>::Node<int>* testRoot = nullptr;

	/* Configure a BST based on Nodes manually */
	/* To be used for initial tests */
	void setupRawTree() {
		//      2
		//   1     5
		//        3	
		BST<int>::Node<int>* testNodes[4];
		for (int i = 0; i < 4; i++)
			testNodes[i] = new BST<int>::Node<int>;
		testNodes[0]->data   = 2;
		testNodes[0]->left   = testNodes[1];
		testNodes[0]->right  = testNodes[2];
		testNodes[1]->data   = 1;
		testNodes[1]->parent = testNodes[0];
		testNodes[2]->data   = 5;
		testNodes[2]->left   = testNodes[3];
		testNodes[2]->parent = testNodes[0];
		testNodes[3]->data   = 3;
		testNodes[3]->parent = testNodes[2];
		testRoot = testNodes[0];
	}

	void setUpTree()
	{
		uut.insert(2);		// ROOT
		uut.insert(1);		// ROOT->L
		uut.insert(5);		// ROOT->R
		uut.insert(3);		// ROOT->R->L
		uut.insert(4);		// ROOT->R->L->R
		uut.insert(6);		// ROOT->R->R
	}
};

TEST_F(BSTToolkitUnitTest, Search_EmptyTree_ElementNotFound)
{
	ASSERT_FALSE(uut.search(5));
}

TEST_F(BSTToolkitUnitTest, Insert_EmptyTree_ElementFound)
{
	uut.insert(5);
	ASSERT_TRUE(uut.search(5));
}

TEST_F(BSTToolkitUnitTest, Insert_ThreeInsertsAscendingOrder_AllElementsFound)
{
	uut.insert(1);
	uut.insert(2);
	uut.insert(3);
	ASSERT_TRUE(uut.search(1));
	ASSERT_TRUE(uut.search(2));
	ASSERT_TRUE(uut.search(3));
}


TEST_F(BSTToolkitUnitTest, Insert_ThreeInsertsDescendingOrder_AllElementsFound)
{
	uut.insert(3);
	uut.insert(2);
	uut.insert(1);
	ASSERT_TRUE(uut.search(3));	
	ASSERT_TRUE(uut.search(2));
	ASSERT_TRUE(uut.search(1));
}


TEST_F(BSTToolkitUnitTest, Insert_ThreeInsertsRandomOrder_AllElementsFound)
{
	uut.insert(5);
	uut.insert(3);
	uut.insert(7);
	ASSERT_TRUE(uut.search(5));
	ASSERT_TRUE(uut.search(3));
	ASSERT_TRUE(uut.search(7));
}

TEST_F(BSTToolkitUnitTest, Insert_ThreeInsertsRandomOrderMiddleRemoved_AllElementsFound)
{
	uut.insert(5);
	uut.insert(3);
	uut.insert(7);
	uut.remove(5);

	ASSERT_TRUE(uut.search(3));
	ASSERT_TRUE(uut.search(7));

	ASSERT_FALSE(uut.search(5));
}

TEST_F(BSTToolkitUnitTest, Insert_InsertRemove_ElementNotFound)
{
	uut.insert(1);
	uut.remove(1);

	ASSERT_FALSE(uut.search(1));
}

TEST_F(BSTToolkitUnitTest, Insert_InsertRemoveInsert_ElementFound)
{
	uut.insert(1);
	uut.remove(1);
	uut.insert(2);
	ASSERT_TRUE(uut.search(2));
	ASSERT_FALSE(uut.search(1));
}


TEST_F(BSTToolkitUnitTest, Insert_TwoDuplicates_ElementFound)
{
	uut.insert(5);
	uut.insert(5);

	ASSERT_TRUE(uut.search(5));
}


TEST_F(BSTToolkitUnitTest, Remove_TwoDuplicatesOneRemoved_ElementFound)
{
	uut.insert(3);
	uut.insert(1);
	uut.insert(5);
	uut.insert(5);
	uut.remove(5);

	ASSERT_TRUE(uut.search(5));
}


TEST_F(BSTToolkitUnitTest, Remove_TwoNodesOneRemoved_ElementFound)
{
	uut.insert(5);
	uut.insert(6);
	uut.remove(5);

	ASSERT_TRUE(uut.search(6));
}

TEST_F(BSTToolkitUnitTest, Remove_ThreeInsertsAscendingOrderMiddleRemoved_AllElementsFound)
{
	uut.insert(1);
	uut.insert(2);
	uut.insert(3);
	uut.remove(2);
	ASSERT_TRUE(uut.search(1));
	ASSERT_TRUE(uut.search(3));

	ASSERT_FALSE(uut.search(2));
}


TEST_F(BSTToolkitUnitTest, Remove_ThreeInsertsDescendingOrderMiddleRemoved_AllElementsFound)
{
	uut.insert(3);
	uut.insert(2);
	uut.insert(1);
	uut.remove(2);
	ASSERT_TRUE(uut.search(3));
	ASSERT_TRUE(uut.search(1));

	ASSERT_FALSE(uut.search(2));
}

TEST_F(BSTToolkitUnitTest, Remove_RemoveLeaf_OtherElementsFound)
{
	setUpTree();

	uut.remove(4);		

	ASSERT_TRUE(uut.search(1));	
	ASSERT_TRUE(uut.search(2));	
	ASSERT_TRUE(uut.search(3));
	ASSERT_TRUE(uut.search(5));
	ASSERT_TRUE(uut.search(6));

	ASSERT_FALSE(uut.search(4));
}


TEST_F(BSTToolkitUnitTest, Remove_RemoveNodeWithOneChild_OtherElementsFound)
{
	setUpTree();

	uut.remove(3);

	ASSERT_TRUE(uut.search(1));
	ASSERT_TRUE(uut.search(2));
	ASSERT_TRUE(uut.search(4));
	ASSERT_TRUE(uut.search(5));
	ASSERT_TRUE(uut.search(6));

	ASSERT_FALSE(uut.search(3));
}

TEST_F(BSTToolkitUnitTest, Remove_RemoveNodeWithTwoChildren_OtherElementsFound)
{
	setUpTree();

	uut.remove(5);

	ASSERT_TRUE(uut.search(1));		// ROOT->L
	ASSERT_TRUE(uut.search(2));		// ROOT
	ASSERT_TRUE(uut.search(3));		// ROOT->R->L
	ASSERT_TRUE(uut.search(4));		// ROOT->R (substitutes [5])
	ASSERT_TRUE(uut.search(6));		// ROOT->R->R

	ASSERT_FALSE(uut.search(5));
}

/* The Following three tests verifies search, insert & remove independently */

TEST_F(BSTToolkitUnitTest, Remove_RawTreeRemove5_ElementsNotFound)
{
	setupRawTree();

	BST<int> myuut(testRoot);
	myuut.remove(5);

	ASSERT_TRUE(myuut.search(1));		// ROOT->L
	ASSERT_TRUE(myuut.search(2));		// ROOT
	ASSERT_TRUE(myuut.search(3));		// ROOT->R->L
	ASSERT_FALSE(myuut.search(5));
}

TEST_F(BSTToolkitUnitTest, Insert_RawTreeInsert10_ElementFound)
{
	testRoot = new BST<int>::Node<int>(20);
	BST<int> myuut(testRoot);

	myuut.insert(10);
	ASSERT_EQ(testRoot->data, 20);
	ASSERT_TRUE(testRoot->left->data == 10);
}

TEST_F(BSTToolkitUnitTest, Search_RawTreeSearchElements_ElementsFound)
{
	setupRawTree();
	BST<int> myuut(testRoot);

	ASSERT_TRUE(myuut.search(1));		// ROOT->L
	ASSERT_TRUE(myuut.search(2));		// ROOT
	ASSERT_TRUE(myuut.search(3));		// ROOT->R->L
	ASSERT_TRUE(myuut.search(5));
}

TEST_F(BSTToolkitUnitTest, Search_RawTreeSearchNonElement_ElementNotFound)
{
	setupRawTree();
	BST<int> myuut(testRoot);

	ASSERT_FALSE(myuut.search(8));
}