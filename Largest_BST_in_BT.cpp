#include <bits/stdc++.h>

using namespace std;
#define ll long long

class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(int data){
		this->data=data;
		left = right = NULL;
	}
	Node(int data, Node* left, Node* right){
		this->data=data;
		this->left=left;
		this->right=right;
	}
};

void PrePrint(Node* root){
	//base case
	if(root==NULL){
		return;
	}
	//recursive case
	cout<<root->data<<" ";
	PrePrint(root->left);
	PrePrint(root->right);
}

