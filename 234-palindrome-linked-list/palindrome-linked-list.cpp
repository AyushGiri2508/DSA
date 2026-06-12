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
ListNode* reverse(ListNode* head){
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return true;
        }
        if(head->next==NULL){
            return true;
        }
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast&&fast->next){     
            fast=fast->next->next;
            slow=slow->next;
    }
    ListNode* reversekahead=reverse(slow->next);
    // slow->next=reversekahead;
    ListNode* temp1=head;
    ListNode* temp2=reversekahead;
    while(temp2){
        if(temp1->val!=temp2->val){
            return false;
        }
        else{
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
return true;
    }
};