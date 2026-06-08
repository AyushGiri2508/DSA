class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        vector<int> ans1;
        vector<int> ans2;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                ans1.push_back(nums[i]);
            }
            if (nums[i] >= pivot) {
                if (nums[i] == pivot) {
                    cnt++;
                } else {
                    ans2.push_back(nums[i]);
                }
            }
        }
            for (int i = 0; i < ans1.size(); i++) {
                ans.push_back(ans1[i]);
            }
            while (cnt--) {
                ans.push_back(pivot);
            }
            for (int i = 0; i < ans2.size(); i++) {
                ans.push_back(ans2[i]);
            }
            return ans;
        }
    };