class Solution {
public:
    int findMin(vector<int>& nums) {
       int mini=INT_MAX;
       int ans=nums[0];
       for(int i=0;i<nums.size();i++){
        if(nums[i]<ans){
            ans=nums[i];
        }
        mini=min(ans,mini);
       } 
       return mini;
    }
};