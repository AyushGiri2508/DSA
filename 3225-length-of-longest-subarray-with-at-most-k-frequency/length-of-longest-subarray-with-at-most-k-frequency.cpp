class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int i = 0;
        int maxlen = 0;
        for (int j = 0; j < n; j++) {
            mpp[nums[j]]++;
            while (mpp[nums[j]] > k) {
                mpp[nums[i]]--;
                i++;
            }
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};