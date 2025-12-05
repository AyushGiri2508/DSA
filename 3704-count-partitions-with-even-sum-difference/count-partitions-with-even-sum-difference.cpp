class Solution {
public:
    int countPartitions(vector<int>& nums) {
         int n = nums.size();
    int cnt = 0;
    int sum1 = 0;
    int total = 0;
    for(int i=0;i<n;i++){
        total+=nums[i];
    }
    for (int i = 0; i < n-1 ; i++) {
        sum1 += nums[i];
        int sum2 = total - sum1;

        if ((sum1 % 2) == (sum2 % 2)) {
            cnt++;
        }
    }
    return cnt;
    }
};