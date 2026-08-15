class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
       int ans=0;
       int n=nums.size();
       bool haszero=false;
       for(int i=0;i<n;i++){
        ans=ans^nums[i];
            if(nums[i]!=0) haszero=true;
       }
       if(ans!=0){
        return n;
       }
       if(haszero) return n-1;
        
        return 0;
    }
};