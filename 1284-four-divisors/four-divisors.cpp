class Solution {
public:
    int solve(int n){
         int cnt = 0, sum = 0;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                cnt++;
                sum += i;
                if(i != n / i){
                    cnt++;
                    sum += n / i;
                }
            }
        }
         if(cnt == 4) return sum;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+= solve(nums[i]);
        }
        return ans; 
    }
};