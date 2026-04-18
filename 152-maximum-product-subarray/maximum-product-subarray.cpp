class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod=nums[0];
        int maxi=nums[0];
        int mini=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            
           if(nums[i]<0){
            swap(maxi,mini);
           }
            maxi = max(nums[i], maxi * nums[i]);
            mini = min(nums[i], mini * nums[i]);
            
            prod = max(prod, maxi);

        }
      return prod;  
    }
};