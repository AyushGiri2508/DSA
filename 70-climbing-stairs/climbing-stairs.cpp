class Solution {
public:
int solve(int n, vector<int>&dp){
    if(n==0||n==1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=0;
    ans+=solve(n-1,dp)+solve(n-2,dp);
    dp[n]= ans;
    return dp[n];
}
int solveusingmem(int n){
    vector<int>dp(n+1,-1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int solveusingspace(int n){
    if(n==1||n==0){
        return 1;
    }
    int prev=1;

    int curr=1;
    int ans=0;
    for(int i=2;i<=n;i++){
        ans=prev+curr;
        prev=curr;
        curr=ans;
    }
    return ans;
}
    int climbStairs(int n) {
        // vector<int>dp(n+1,-1);
    //     return solve(n,dp);
//    return solveusingmem(n);
return solveusingspace(n);
    }
};