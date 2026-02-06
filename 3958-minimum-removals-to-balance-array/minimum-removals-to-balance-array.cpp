// class Solution {
// public:
//     int minRemoval(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         int cnt=0;
//         int left=0;
//         int right=nums.size()-1;
//         while(left<=right){
//             if(nums[right]<=k*nums[left]){
//                 break;
//             }
//             else{
//                 right--;
//                 cnt++;
//             }
//         }
//        return cnt; 
//     }
// };

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int maxLen = 1;
        int i = 0;
        
        for (int j = 0; j < n; j++) {
            while ((long long)nums[j] > (long long)k * nums[i]) {
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        
        return n - maxLen;
    }
};
