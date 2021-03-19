#pragma once

template<typename T>
class BST
{
public:
	template<typename T>
	class Node
	{
	public:
		Node(const T& _data = T(), Node<T>* l = nullptr, Node<T>* r = nullptr, Node<T>* p = nullptr)
			: data(_data), left(l), right(r), parent(p)
		{}

		T data;
		Node<T>* parent;
		Node<T>* left;
		Node<T>* right;
	};
private:
	Node<T>* root;

	// Recursive function to find Node with data = data
	Node<T>* findNode(Node<T>* itsRoot, const T& data)
	{
		
		/* Function to be implemented 
		* Tjek itsRoot.data er = data , hvis true return Node<T>* itsRoot
		* Er data <= itsRoot.data eller > itsRoot.data
		* Eksistere left og right child?
		* kald rekursivt med left eller right child node og data.
		*/
		//Er root det data vi leder efter?
		if (itsRoot->data == data)
		{
			return itsRoot;
		}
		
		//Tjek om data er mindre eller = med det data vi søger efter
		if (data <= itsRoot->data)
		{
			//hvis ja, tjek om left child eksistere
			if (itsRoot->left != nullptr)
			{
				//Gør den det, kald rekursivt med denne pointer.
				return findNode(itsRoot->left,data);
			}
		}
		else //Data vi søger er større end data der peges på af itsroot
		{
			//Findes right child?
			if (itsRoot->right != nullptr)
			{
				//Hvis ja, kald rekursivt med right child pointer
				return findNode(itsRoot->right,data);
			}
		}

		//Hvis data på den node vi kigger på ikke er det vi søger, og der ingen children er til den pågældende node
		//så ved vi, at det Data vi søger ikke findes i træet.

		return nullptr;
	}

	// Recursive function to insert node with data
	Node<T>* insertNode(Node<T>* itsRoot, const T& data)
	{
		/* Function to be implemented 
		* BaseCase - no left or right child
		*/ 
		if(data <= itsRoot->data)
		{
			if (itsRoot->left == nullptr)
			{
				BST<T>::Node<T>* leftNode = new BST<T>::Node<T>(data,nullptr,nullptr,itsRoot);
				itsRoot->left = leftNode;
				return leftNode;
			}
			insertNode(itsRoot->left, data);
		}
		else
		{
			if (itsRoot->right == nullptr)
			{
				BST<T>::Node<T>* rightNode = new BST<T>::Node<T>(data, nullptr, nullptr, itsRoot);
				itsRoot->right = rightNode;
				return rightNode;
			}
			insertNode(itsRoot->right, data);
		}

		/* Rekursive kald
		* Find hvilket child der skal kigges på og kald igen
		*/

	}

	void removeNode(Node<T>* itsRoot)
	{
		/*Pointen er, at fjerne den Node der sendes ind i funktionen removeNode*/
		/*Først vil jeg finde rightmost eller leftmost child
		alt efter om itsRoot.data er større eller mindre end root.data*/

		/*Special case - itsRoots parent er root-pointeren
		Der skal også håndteres den special case hvor den node der skal fjernes er root*/

		if (itsRoot->parent == nullptr)
		{
			if(itsRoot->left != nullptr)
			{
				Node<T>* RightMostChild = findRightmostChild(itsRoot->left);
								
				//Den tager ventre child's højre child, og finder den største til højre.
				//Effektiv set betyder det, at den finder den største værdi, som er mindre end data end root Noden.

				//Swap Noden der skal slettes's data ud med RightMostChild data
				itsRoot->data = RightMostChild->data;
				//Sørg for, at RightMostChilds parent right child pointer peger mod en null pointer.

				//Dernæst tjekkes for, om Rightmostchild har et left child.
				if (RightMostChild->left != nullptr)
				{
					//Nederste element til højre, hvis det har en left child, så skal det left child 
					//Kobles til det nederste elements til højres parent, og omvendt.
					RightMostChild->parent->right = RightMostChild->left;
					RightMostChild->left->parent = RightMostChild->parent;

					delete RightMostChild;
					return;
				}
				//Hvis right most child er et leaf - sæt parents rightptr til nullptr.
				RightMostChild->parent->left = nullptr;
				
				//Slet objektet.
				delete RightMostChild;
				return;
			
			}
			if(itsRoot->right != nullptr)
			{
				itsRoot->data = itsRoot->right->data;

				itsRoot->right = nullptr;
				delete itsRoot->right;
				return;
			}
			else
			{
				root = nullptr;
				delete itsRoot;
				return;
			}
			
			
		}
	
		/*Noden er ikke root, den har en parent*/
		if (itsRoot->data <= itsRoot->parent->data)
		{			
			//Find den mostRight node, return den.
			if (itsRoot->right != nullptr)
			{
				Node<T>* LefMostChild = findLeftmostChild(itsRoot->right);
				//Swap Noden der skal slettes's data ud med RightMostChild data
				itsRoot->data = LefMostChild->data;

				//Dernæst tjekkes for, om leftmostchild har et left child.
				if (LefMostChild->right != nullptr)
				{
					//Right most childs parent, dens nye left child, bliver rightmostchilds left child.
					LefMostChild->parent->left = LefMostChild->right;
					LefMostChild->right->parent = LefMostChild->parent;

					delete LefMostChild;
					return;
				}

				LefMostChild->parent->right	= nullptr;
				//Slet objektet.
				delete LefMostChild;
				return;
			}else
			{				
				//Noden har intet right child, tjek for left child
				if (itsRoot->left != nullptr)
				{
					//Right most childs parent, dens nye left child, bliver rightmostchilds left child.
					itsRoot->parent->left = itsRoot->left;
					itsRoot->left->parent = itsRoot->parent;
					delete itsRoot;
					return;

				}

			}
			itsRoot->parent->left = nullptr;
			delete itsRoot;
			return;
			
		}else
		{
			if (itsRoot->left != nullptr)
			{
				//Find den mostRight node, return den.
				Node<T>* RightMostChild = findRightmostChild(itsRoot->left);
				//Special case - itsRoots parent er root-pointeren

				//Check om rightmostchild har et left child
				if (RightMostChild->left != nullptr)
				{
					//Right most childs parent, dens nye left child, bliver rightmostchilds left child.
					RightMostChild->parent->left = RightMostChild->left;
					RightMostChild->left->parent = RightMostChild->parent;
					delete RightMostChild;
					return;

				}
				//Swap Noden der skal slettes's data ud med RightMostChild data
				itsRoot->data = RightMostChild->data;
				//Sørg for, at RightMostChilds parent peger mod en null.
				RightMostChild->parent->right = nullptr;
				//Slet objektet.
				delete RightMostChild;
				return;
			}
			else
			{
				//Noden har intet right child, tjek for left child
				if (itsRoot->right != nullptr)
				{
					//Right most childs parent, dens nye left child, bliver rightmostchilds left child.
					itsRoot->parent->right = itsRoot->right;
					itsRoot->right->parent = itsRoot->parent;
					delete itsRoot;
					return;

				}
				else
				{
					itsRoot->parent->right = nullptr;
					delete itsRoot;
				}
				//Slet objektet.
				
				return;

			}
			
		}
	

	}

	 //Recursive function to find right-most node
	Node<T>* findRightmostChild(Node<T>* itsRoot) 
	{
		/*Denne funktioner bevæger sig fra itsroots leftchild, og ned
		til højre indtil den rammer et leaf*/
		if (itsRoot->right != nullptr)
		{
			return findRightmostChild(itsRoot->right);
		}
		return itsRoot;
	}

	// Recursive function to find left-most node
	Node<T>* findLeftmostChild(Node<T>* itsRoot) {
		/* Helper function can be implemented */ 
		if (itsRoot->left != nullptr)
		{
			return findRightmostChild(itsRoot->left);
		}
		return itsRoot;
	}


public:

	BST(Node<T>* root = nullptr) : root(root)
	{
	}

	bool search(const T& data)
	{
		// Recursive function called with root as seed
		if (root == nullptr)
		{
			return false;
		}

		return findNode(root, data) != nullptr;
	}

	void insert(const T& data)
	{
		// Recursive function called with root as seed
		if(root == nullptr)
		{
			BST<T>::Node<T>* rootNode = new BST<T>::Node<T>(data);
			root = rootNode;
		}
		else
		{
			insertNode(root, data);
		}
	}

	void remove(const T& data)
	{
		/* Function to be implemented */
		if (root == nullptr)
		{

		}
		else
		{
			Node<T>* NodeToBeRemoved = findNode(root, data);

			if (NodeToBeRemoved != nullptr)
			{
				removeNode(NodeToBeRemoved);
			}
			
		}
	}

};