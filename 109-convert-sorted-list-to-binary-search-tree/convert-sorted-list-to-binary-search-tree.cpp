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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* arraytoBST(vector<int>&ans,int s,int e){
        if(s>e )return NULL;
        int mid=s+(e-s)/2;
        TreeNode* temp=new TreeNode(ans[mid]);
        temp->left =arraytoBST(ans,s,mid-1);
        temp->right=arraytoBST(ans,mid+1,e);
        return temp;
    }
    void linkedlisttoarray(ListNode* head,vector<int>&ans){
        ListNode* temp=head;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        vector<int>ans;
        linkedlisttoarray(head,ans);
        int s=0;
        int e=ans.size()-1;

        return arraytoBST(ans,s,e);
        
    }
};