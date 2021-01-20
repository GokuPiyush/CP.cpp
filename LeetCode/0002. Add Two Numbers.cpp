/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sum=new ListNode(), *head=sum, *prv;
        int carry=0;
        while(l1 || l2){
            int num = carry + (l1?l1->val:0) + (l2?l2->val:0);
            carry = num / 10;
            sum->val = num % 10;
            ListNode *tmp = new ListNode();
            sum->next = tmp;
            prv = sum;
            sum = tmp;
            l1 = l1?l1->next:nullptr;
            l2 = l2?l2->next:nullptr;
        }
        if(carry) sum->val = carry;
        else prv->next = nullptr;
        return head;
    }
};