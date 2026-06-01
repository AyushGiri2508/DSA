class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), bptIdx = -1;
        for(int i = n - 1; i >= 1; i--) {
            if(nums[i - 1] < nums[i]) {
                bptIdx = i - 1;
                break;
            }
        }
        if(bptIdx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = n - 1; i > bptIdx; i--) {
            if(nums[i] > nums[bptIdx]) {
                swap(nums[i], nums[bptIdx]);
                break;
            }
        }
        reverse(nums.begin() + bptIdx + 1, nums.end());
    }
};