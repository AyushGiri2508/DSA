class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr,brr;
        arr.push_back(nums[0]);
           brr.push_back(nums[1]);
        int i=0;
        int j=0;
        for(int i=2;i<nums.size();i++){
            if(arr.back()>brr.back()){
                arr.push_back(nums[i]);
            }
            else{
                brr.push_back(nums[i]);
            }
        }
        for(int i=0;i<brr.size();i++){
            arr.push_back(brr[i]);
        }
        return arr;
    }
};