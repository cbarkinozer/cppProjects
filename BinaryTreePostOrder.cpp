#include<iostream>
using namespace std;



struct bintree_node { //node of the binary tree
	int data;
	bintree_node* left;
	bintree_node* right;
};

class bst {
	bintree_node* root;
public:
	bst() {   //constructor
		root = NULL;
	}
	int isempty() {
		return(root == NULL);
	}
	void insert(int item);
	void displayBinTree();
	void printBinTree(bintree_node*);

};
void bst::insert(int item) {
	bintree_node* p = new bintree_node; //p is the new node
	bintree_node* parent;

	p->data = item;
	p->left = NULL;
	p->right = NULL;

	parent = NULL;

	if (isempty()) //if there is no node,root is p
		root = p;

	else { // there is a node or nodes
		bintree_node* ptr;
		ptr = root; 

		while (ptr != NULL) {  //while root is not empty
			parent = ptr; // root is parent

			if (item > ptr->data) //if new nodes data is greater than roots data
				ptr = ptr->right; 

			else
				ptr = ptr->left; // new input is not greater than roots data ptr points the element at the left of the ptr
		}

		if (item < parent->data) // if new nodes data is smaller than  parents data
			parent->left = p; 
		else
			parent->right = p; 
	}
}

void bst::displayBinTree() {
	printBinTree(root);
}

void bst::printBinTree(bintree_node* ptr) {
	if (ptr != NULL) { // if there is a node or nodes
		printBinTree(ptr->left); //recurse left
		printBinTree(ptr->right); //recurse right
		cout << "  " << ptr->data << " ";
	}
}

int main() {
	int input;
	bst b;

	do
	{
		cout << "Please enter the data:(EXIT:0)" << endl;
		cin >> input;

		if (input != 0) // for the purpose of not reading 0
		{
			b.insert(input);
		}

	} while (input);
	cout << "Binary tree created: " << endl;
	b.displayBinTree();
	return 0;
}
