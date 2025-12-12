class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        map<int,int>mpp;
        int n=nums.size();
        int min= n/3+1;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]==min){
                ans.push_back(nums[i]);
            }
            if(ans.size()==2)break;

        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};