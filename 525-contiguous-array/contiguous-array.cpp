class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mpp;
        mpp[0]=-1;

        int prefix=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                prefix+=-1;
            }
            else{
                prefix+=1;
            }
            if(mpp.find(prefix)!=mpp.end()){
                ans=max(ans,i-mpp[prefix]);
            }
            else{
                mpp[prefix]=i;
            }
        }
     
      return ans;  
    }
};