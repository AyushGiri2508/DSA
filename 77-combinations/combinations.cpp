class Solution {
public:
void solve (int start,int n, int k,vector<vector<int>>&res,vector<int>&ans){
    if(ans.size()==k){
        res.push_back(ans);
        return;
    }
    for(int i=start;i<=n;i++){
        ans.push_back(i);
        solve(i+1,n,k,res,ans);
        ans.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>ans; 
        solve(1,n,k,res,ans);
    return res;
    }
};