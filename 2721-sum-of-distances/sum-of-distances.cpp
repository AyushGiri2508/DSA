class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        // vector<long long>ans;
        // int j=0;
        // while(j<nums.size()){
        //     long long res=0;
        //     int val=nums[j];  
        // for(int i=0;i<nums.size();i++){
        //     if(val==nums[i]){
        //         long long cal=abs(j-i);
        //             res=res+cal;
        //     }
            
        // }
        // ans.push_back(res);
        // j++;
        // res=0;
        // } 
        // return ans;
        int n = nums.size();
        vector<long long> ans(n);

        unordered_map<int, long long> count, sum;

        for(int i = 0; i < n; i++){
            int val = nums[i];
            ans[i] += count[val] * i - sum[val];

            count[val]++;
            sum[val] += i;
        }

        count.clear();
        sum.clear();

        for(int i = n-1; i >= 0; i--){
            int val = nums[i];
            ans[i] += sum[val] - count[val] * i;

            count[val]++;
            sum[val] += i;
        }

        return ans;
    }
};