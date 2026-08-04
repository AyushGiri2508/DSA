class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            for (int j = nums[i - 1] + 1; j < nums[i]; j++) {
                ans.push_back(j);
            }
        }
        return ans;
    }
};