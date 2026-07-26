class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        long long op1 = 1LL * nums[n - 1] * nums[n - 2] * nums[n - 3];
        long long op2 = 1LL * nums[0] * nums[1] * nums[n - 1];
        return max(op1, op2);
    }
};