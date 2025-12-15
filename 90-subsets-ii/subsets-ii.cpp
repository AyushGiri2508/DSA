class Solution {
public:
void solve (vector<int>& nums,vector<int>&ans,int i,set<vector<int>>&st){
    if(i>=nums.size()){
       st.insert(ans);
        return;
    }
     solve(nums,ans,i+1,st);
     ans.push_back(nums[i]);
  
      solve(nums,ans,i+1,st);
      ans.pop_back();
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>ans;
        int n= nums.size();
        set<vector<int>>st;
        int i=0;
        solve(nums,ans,i,st);
                 vector<vector<int>>res(st.begin(),st.end());
        return res;
    }
};