class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       int n = nums.size();     
     unordered_map<int,int> lastIdx;
        for (int i = 0; i < (int)nums.size(); ++i) {
            auto it = lastIdx.find(nums[i]);
            if (it != lastIdx.end() && i - it->second <= k) return true;
            lastIdx[nums[i]] = i; 
        }
        return false;
    }
};