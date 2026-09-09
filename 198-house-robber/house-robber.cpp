class Solution {
public:
int solve(vector<int>& nums,int i,vector<int>&dp){
    if(i>=nums.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
   int ans1=nums[i]+solve(nums,i+2,dp);
   int  ans2=solve(nums,i+1,dp);
    dp[i]= max(ans1,ans2);
    return dp[i];
}
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
         return solve(nums,0,dp);
    }
};