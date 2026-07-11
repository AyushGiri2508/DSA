/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>& preorder, int& idx, int bound) {
        if (idx == preorder.size() || preorder[idx] > bound)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = build(preorder, idx, root->val);
        root->right = build(preorder, idx, bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return build(preorder, idx, INT_MAX);
    }
};