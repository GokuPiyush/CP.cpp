/*
Given a singly linked list of size N. The task is to swap elements in the linked list pairwise.
For example, if the input list is 1 2 3 4, the resulting list after swaps will be 2 1 4 3.
Note: You need to swap the nodes, not only the data. If only data is swapped then driver will print -1.
*/


#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* pairWiseSwap(Node* head);

void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i<n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		head = pairWiseSwap(head);
		printList(head);
	}
	return 0; 
}
// } Driver Code Ends


/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/

Node* pairWiseSwap(struct Node* head) {
    // The task is to complete this method
    Node *prv=NULL, *first=head, *second=first->next, *nxt, *tmp = first;
    if(second != NULL){
        nxt=second->next;
    }else{
        return tmp;
    }
    tmp = second;
    while(true){
        if(prv != NULL){
            prv->next = second;
        }
        second->next = first;
        first->next = nxt;
        // cout<< first->data<< ' '<< second->data<< endl;
        if(nxt != NULL){
            prv = first, first = nxt;
            second = nxt->next;
            nxt = nxt->next;
            if(nxt != NULL){
                nxt = nxt->next;
            }else{
                break;
            }
        }else{
            break;
        }
    }
    return tmp;
}