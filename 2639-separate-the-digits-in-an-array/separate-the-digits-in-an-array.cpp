class Solution {
public:
void solve(int n,vector<int>& arr){
         vector<int> temp;

        while (n > 0) {
            temp.push_back(n % 10);
            n /= 10;
        }

        reverse(temp.begin(), temp.end());

        for (int x : temp) {
            arr.push_back(x);
        }

}
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
          solve(nums[i],ans);
        }
        return ans;
    }
};