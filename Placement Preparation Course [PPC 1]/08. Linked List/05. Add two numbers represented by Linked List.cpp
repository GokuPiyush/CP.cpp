/*
Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list is a linked list representation of the addition of two input numbers.
*/


// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* addTwoLists(struct Node* first, struct Node* second);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // code here
    
    Node *head1, *head2, *tmp, *prv;
    tmp = first, prv = NULL;
    while(tmp != NULL){
        Node* nxt = tmp->next;
        tmp->next = prv;
        prv = tmp;
        tmp = nxt;
    }
    head1 = prv;
    
    tmp = second, prv = NULL;
    while(tmp != NULL){
        Node* nxt = tmp->next;
        tmp->next = prv;
        prv = tmp;
        tmp = nxt;
    }
    head2 = prv;
    
    int carry = 0;
    prv = NULL;
    for(auto it1=head1, it2=head2; it1!=NULL || it2 !=NULL; it1=it1!=NULL? it1->next:NULL, it2=it2!=NULL? it2->next:NULL){
        Node *tmp = new Node(0);
        int num = ((it1!=NULL?it1->data:0) + (it2!=NULL?it2->data:0) + carry);
        tmp->data = num % 10;
        carry = num / 10;
        //cout<< tmp->data<< ' ';
        tmp->next = prv;
        prv = tmp;
    }
    if(carry != 0){
        Node* tmp = new Node(carry);
        tmp->next = prv;
        prv = tmp;
    }
    return prv;
}
