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

Node* Build(int a[], int s, int e){
	//base case
	if(s==e){
		Node* n= new Node(a[s]);
		return n;
	}
	if(s>e){return NULL;}

	//recursive case
	int mid=(s+e)/2;
	Node *n= new Node(a[mid], Build(a,s,mid-1), Build(a,mid+1, e));
	return n;
}
int sum=0;
void modify(Node* &root){
	//base case
	if(root==NULL){
		return;
	}
	//recursive case
	modify(root->right);
	root->data += sum;
	sum = root->data;
	modify(root->left);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n, a[1000];
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	Node *Tree=Build(a, 0, n-1);
	modify(Tree);
	PrePrint(Tree);
}