class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n=nums.size();
        int ans1=0;
        int ans2=0;
        for(int i=0;i<n;i++){
            if(nums[i]>9){
                ans2+=nums[i];
            }
            else{
                ans1+=nums[i];
            }
        }
        if((ans1>ans2)||(ans1<ans2)){
            return true;
        }
        return false;
    }
};