#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};
void LevelOrder(Node *root){
	if(root==NULL)
		return;
	queue<Node*> Q;
	Q.push(root);
	while(!Q.empty()){
		Node* current = Q.front();
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
		cout << current->data << " ";
		Q.pop();
	}
}
int main() {
	// your code goes here
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
	LevelOrder(root);
	
	return 0;
}