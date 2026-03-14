class Solution {
public:
    int thirdMax(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int count=0;
        for(auto i=mpp.rbegin();i!=mpp.rend();i++){
            count++;
            if(count==3){
                return i->first;
            }
        }

        return mpp.rbegin()->first;
    }
};