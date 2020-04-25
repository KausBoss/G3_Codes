/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *temp=head, *tail=head;
        while(tail->next){
        	tail=tail->next;
        } 

        while(temp){
        	if(temp->child){
        		tail->next=temp->child;
        		temp->child->prev=tail;
        		temp->child=NULL;
        		while(tail->next){
        			tail=tail->next;
        		}
        	}
        	temp=temp->next;
        }
        return head;
    }
};