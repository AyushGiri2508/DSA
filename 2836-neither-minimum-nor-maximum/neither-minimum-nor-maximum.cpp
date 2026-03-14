class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<3){
            return -1;
        }
        for(int i=0;i<nums.size();i++){
            return nums[1];
        }
        return -1;
    }
};