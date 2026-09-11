class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int ans=0;
        for(auto val:mpp){
            if(val.second==1){
                return -1;
            }
            ans+=val.second/3;
            if(val.second%3==1){
               ans--;
               ans+=2;
            }
            else if(val.second%3==2){
               ans++;
            }
            
        }
return ans;
    }
};