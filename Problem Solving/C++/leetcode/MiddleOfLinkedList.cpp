/**
 * Definition for singly-linked list.
 * 
 */
class Solution {
#include <bits/stdc++.h>
public:    
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
 };
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* mid=head;
        int i=0;
        //cout<<head->val;
        while(head->next!=NULL)
        {
            if(i%2==0)mid=mid->next;
            head=head->next;
            i++;
        }
        return mid;
    }
};