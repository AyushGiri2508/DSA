class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>prefix;
        int maxi=INT_MIN;
         for(int i=0;i<nums.size();i++){
             maxi=max(nums[i],maxi);
             int ans=gcd(nums[i],maxi);
             prefix.push_back(ans);
         }
        sort(prefix.begin(),prefix.end());
        int i=0;
        int j=prefix.size()-1;
        long long sum=0;
        while(i<j){
            sum+=gcd(prefix[i],prefix[j]);
            i++;
            j--;
        }
       return sum;
    }
};