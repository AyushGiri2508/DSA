class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int sum=0;
        for(auto val:mpp){
            if(val.second==1){
                sum+=val.first;
            }
        }
        return sum;
    }
};