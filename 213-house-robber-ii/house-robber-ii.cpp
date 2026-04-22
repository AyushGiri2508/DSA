class Solution {
public:
int solve(vector<int>&arr,int i,int n,vector<int>&dp){
   
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int include=arr[i]+solve(arr,i+2,n,dp);
    int exclude=0+solve(arr,i+1,n,dp);
    dp[i]= max(include,exclude);
    return dp[i];
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>dp1(n+1,-1);
         vector<int>dp2(n+1,-1);
        int ans1=solve(nums,0,n-1,dp1);
         int ans2 = solve(nums, 1, n,dp2);
        return max(ans1,ans2);
    }
};