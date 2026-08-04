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
void inordertraversal(TreeNode* root, vector<int>&ans){
    if(root==NULL){
        return;
    }
    inordertraversal(root->left,ans);
    ans.push_back(root->val);
    inordertraversal(root->right,ans);
}
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>ans;
        inordertraversal(root,ans);
        int sum=0;
       for (int x : ans) {
        if (x >= low && x <= high) {
            sum += x;
        }
       }
        return sum;
    } 
};