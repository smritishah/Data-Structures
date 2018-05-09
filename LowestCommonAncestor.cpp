#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

int lca(Node* root, int a,int b){
	if (root==NULL) return -1;
	if (root->data == a || root->data == b) return root->data;
	
	int left = lca(root->left,a,b);
	int right = lca(root->right,a,b);
	
	if(left == -1 && right == -1) return -1;
	if (left != -1 && right != -1) return root->data;
	
	return left!=-1?left:right;
}

Node* newNode(int val){
	Node* temp = new Node();
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int main() {
	//	  		  3
	//	 		 / \
	//		    /   \
	//         6     8
	//         /\     \
	//        2	 11    13
	//	         /\   /
	//	        9  5 7
	Node* root = newNode(3);
	root->left = newNode(6);
	root->right = newNode(8);
	root->left->left = newNode(2);
	root->left->right = newNode(11);
	root->left->right->left = newNode(9);
	root->left->right->right = newNode(5);
	root->right->right = newNode(13);
	root->right->right->left = newNode(7);
	
	cout << lca(root,9,5) << endl;
	return 0;
}