class Solution {
public:
int solve(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int prev=0;
    int ans=0;
    int curr=1; 
    for(int i=2;i<=n;i++){
        ans=prev+curr;
        prev=curr;
    curr=ans;
    }
    return ans;
}
    int fib(int n) {
        return solve(n);
    }
};