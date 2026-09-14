class Solution {
public:
int solve(vector<int>&nums,int i,int end,vector<int>&dp){
    if(i>end){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int include=nums[i]+solve(nums,i+2,end,dp);
    int exclude=solve(nums,i+1,end,dp);
    dp[i]= max(include,exclude);
    return dp[i];
}
    int rob(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        if(n==1) return nums[0];
           vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int case1 = solve(nums, 0, n - 2,dp1); // Exclude last
        int case2 = solve(nums, 1, n - 1,dp2); // Exclude first

        return max(case1, case2);
    }
};