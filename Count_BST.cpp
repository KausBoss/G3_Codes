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
		left=right=NULL;
	}
	Node(int data, Node* left, Node* right){
		this->data=data;
		this->left=left;
		this->right=right;
	}
};

Node* BST(int a[], int s, int e){
	//base case
	if(s==e){
		Node* n=new Node(a[s]);
		return n;
	}
	if(s>e){
		return NULL;
	}
	//recursive case
	int mid=(s+e)/2;
	Node* n= new Node(a[mid], BST(a,s,mid-1), BST(a,mid+1,e));
	return n;
}
int high, low, ans=0;

bool range(Node* root){
	//base case
	if(root==NULL){
		return true;
	}
	//recursive case
	bool left=range(root->left);
	bool right=range(root->right);

	if(left && right && root->data>=low && root->data<=high){
		ans++;
		return true;
	}
	return false;
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
	cin>>low>>high;
	Node* Tree=BST(a, 0, n-1);
	range(Tree);
	cout<<ans;
}