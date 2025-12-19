class Solution {
public:
void solve (int start,vector<int>& candidates,int n,int target,vector<vector<int>>&res,vector<int>&ans){
    if(target==0){
     res.push_back(ans);
        return;
    }
    for(int i=start;i<n;i++){
        if(i > start && candidates[i] == candidates[i-1]) continue;
        if(candidates[i]>target) break;
       
            ans.push_back(candidates[i]);
        solve(i+1,candidates,n,target-candidates[i],res,ans);
        ans.pop_back();      
    }

}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        sort(candidates.begin(), candidates.end());
        vector<int>ans;
        int n= candidates.size();
        int start=0;
         solve( start,candidates,n,target,res,ans);
      return res;
    }
};