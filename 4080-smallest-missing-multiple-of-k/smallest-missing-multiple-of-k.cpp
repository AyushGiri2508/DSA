class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%k==0){
                mpp[nums[i]]++;
            }
        }
        int i=1;
        while(true){
           if( mpp.find(k*i)==mpp.end()){
           return k*i;
        }
        i++;
        }
        return -1;
    }
};