class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 1;
        }
        int mini = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            mini = min(nums[i], mini);
        }
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(nums[i], maxi);
        }
        int minindex = 0, maxindex = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == mini) {
                minindex = i;
            }
            if (nums[i] == maxi) {
                maxindex = i;
            }
        }
        int left = min(minindex, maxindex);
        int right = max(minindex, maxindex);
        int val1 = right + 1;
        int val2 = n - left;
        int val3 = (left + 1) + (n - right);
        return min({val1, val2, val3});
    }
};