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
    int ans = INT_MIN;
    int solve(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int leftGain = max(0, solve(root->left));
        int rightGain = max(0, solve(root->right));
        // Maximum path passing through current node
        ans = max(ans, leftGain + rightGain + root->val);

        // Return one path to parent
        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};