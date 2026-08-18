class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        int n = nums.size();

        // Generate every subarray/window of size k
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> st;

            // Elements in current window
            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            // Count this number for this window only once
            for (int x : st) {
                freq[x]++;
            }
        }

        int ans = -1;

        // Find largest number appearing in exactly one window
        for (auto it : freq) {
            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};