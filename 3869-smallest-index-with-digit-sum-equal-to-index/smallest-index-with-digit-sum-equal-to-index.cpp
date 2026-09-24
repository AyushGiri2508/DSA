class Solution {
public:
int solve(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
        if(nums[i]<10&&nums[i]==i){
            return i;
        }
        else{
            int val=solve(nums[i]);
            if(i==val){
                return i;
            }
            else{
                continue;
            }
        }
        }
        return -1;    
    }
};