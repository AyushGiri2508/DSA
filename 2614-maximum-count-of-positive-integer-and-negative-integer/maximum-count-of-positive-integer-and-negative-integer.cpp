class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int poscnt=0;
        int negcnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                poscnt++;
            }
            else if(nums[i]<0){
                negcnt++;
            }
        }
        return max(poscnt,negcnt);
    }
};