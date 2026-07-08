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
    int postIndex;
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    int inStart, int inEnd) {
        if (inStart > inEnd)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[postIndex--]);
        int idx = mp[root->val];
        root->right = solve(inorder, postorder, idx + 1, inEnd);
        root->left = solve(inorder, postorder, inStart, idx - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = inorder.size();

        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        postIndex = n - 1;

        return solve(inorder, postorder, 0, n - 1);
    }
};