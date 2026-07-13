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
    struct NodeInfo {
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };
    int ans = 0;
    NodeInfo solve(TreeNode* root) {
        if (!root)
            return {true, INT_MAX, INT_MIN, 0};
        NodeInfo left = solve(root->left);
        NodeInfo right = solve(root->right);
        if (left.isBST && right.isBST &&
            root->val > left.maxVal &&
            root->val < right.minVal) {
            int currSum = left.sum + right.sum + root->val;
            ans = max(ans, currSum);
            return {
                true,
                min(root->val, left.minVal),
                max(root->val, right.maxVal),
                currSum
            };
        }

        return {false, INT_MIN, INT_MAX, 0};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};