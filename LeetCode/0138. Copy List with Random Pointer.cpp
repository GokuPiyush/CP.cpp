/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* tmp=head, *prv, *ans; int count=0;
        while(tmp !=NULL){
            Node* n = new Node(tmp->val);
            if(count++ == 0) ans = n;
            else prv->next = n;
            n->next = NULL;
            prv = n;
            tmp = tmp->next;
        }
        Node* tmp1=head, *tmp2=ans;
        while(tmp1){
            Node* tmp11=head, *tmp22=ans;
            if(tmp1->random){
                while(tmp11 != tmp1->random){
                    tmp11 = tmp11->next;
                    tmp22 = tmp22->next;
                }
                tmp2->random = tmp22;
            }
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        return ans;
    }
};