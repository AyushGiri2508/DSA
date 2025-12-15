class Solution {
public:
void solve (vector<int>& nums,vector<vector<int>>&res,vector<int>&ans, int n,int i){
    if(i>=n){
        res.push_back(ans);
        return;
    }
     solve(nums,res,ans,n,i+1);
     ans.push_back(nums[i]);
      solve(nums,res,ans,n,i+1);
      ans.pop_back();
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ans;
        int n= nums.size();
        int i=0;
        solve(nums,res,ans,n,i);
        return res;
    }
};