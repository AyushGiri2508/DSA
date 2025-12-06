class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto val:mpp){
            if(val.second >1){
                return val.first;
            }
        }
        return 0;
    }
};