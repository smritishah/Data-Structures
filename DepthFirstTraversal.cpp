#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};
void Preorder(Node* root){
	if (root==NULL) return;
	cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}
void Postorder(Node* root){
	if(root==NULL) return;
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data << " ";
}
void Inorder(Node* root){
	if(root==NULL) return;
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}
int main() {
			
	Node* root = new Node();
	root->data = 1;
	root->left = new Node();
	root->right = new Node();
	root->left->data = 2;
	root->right->data = 3;
	root->left->left = new Node();
	root->left->right = new Node();
	root->left->left->data = 4;
	root->left->right->data = 5;
	cout << "Preorder traversal" << endl;
	Preorder(root);
	cout << endl << "Inorder traversal" << endl;
	Inorder(root);
	cout << endl << "Postorder traversal" << endl;
	Postorder(root);
	return 0;
}