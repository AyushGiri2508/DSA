class Solution {
public:
 vector<vector<int>>val;
void solve(vector<int>& candidates,int n,int target,int start,vector<int>&ans){
   
    if(target==0){
        val.push_back(ans);
        return ;
 }
 if(target<0){
    return;
 }

 for(int i=start;i<n;i++){
     if (candidates[i] > target) continue;
    ans.push_back(candidates[i]);
    solve(candidates,n,target-candidates[i],i,ans);
    ans.pop_back();
 }

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
                val.clear();
       vector<int>ans;
        int n= candidates.size();
       
        solve(candidates,n,target,0 ,ans);
            
        
     return  val;
    }
};