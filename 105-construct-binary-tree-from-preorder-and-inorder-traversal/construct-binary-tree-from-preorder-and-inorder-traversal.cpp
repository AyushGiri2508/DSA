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
    unordered_map<int, int> mp;
    int preIndex;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int inStart, int inEnd) {
        if (inStart > inEnd)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        int idx = mp[root->val];
        root->left = solve(preorder, inorder, inStart, idx - 1);
        root->right = solve(preorder, inorder, idx + 1, inEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = inorder.size();

        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        preIndex = 0;

        return solve(preorder, inorder, 0, n - 1);
    }
};