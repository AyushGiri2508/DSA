class Solution {
public:
int solveusingtab(int n){
    vector<int>dp(n+1,-1);
    dp[0]=0;
    if (n==0) return dp[0];
    dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
    int fib(int n) {
       vector<int>dp(n+1,-1);
    //    return solve(n,dp);
     int ans= solveusingtab(n);
     return ans;
    }
};