class Solution {
public:
    vector<vector<int>> res;

    void solve(int idx, vector<int>& candidates, int target, vector<int>& curr) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            // No need to proceed further
            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            // Move to next index since each element can be used only once
            solve(i + 1, candidates, target - candidates[i], curr);

            curr.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> curr;
        solve(0, candidates, target, curr);

        return res;
    }
};