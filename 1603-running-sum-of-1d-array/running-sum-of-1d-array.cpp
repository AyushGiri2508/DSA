class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        int val=nums[0];
        ans.push_back(val);
        for(int i=1;i<n;i++){
            int curr=nums[i]+ans[i-1];
            ans.push_back(curr);
        }
        return ans;
        
    }
};