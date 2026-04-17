// class Solution {
// public:
// int reverse(int n){
//     int num=0;
//     while(n>0){
//         int digit=n%10;{
//             if(digit==0){
//                 return -1;
//             }
//         }
//         num=10*num+digit;
//         n/=10;

//     }
//     return num;
// }
//     int minMirrorPairDistance(vector<int>& nums) {
//         int n=nums.size();
//         int mini=INT_MAX;
//         unordered_map<int, vector<int>> mpp;
//         for(int i=0;i<n;i++){
//            int val=reverse(nums[i]);
//            mpp[val].push_back(i);
//         }
//         for(int i=0;i<n;i++){
//             int val = nums[i];
//             if(mpp.find(val) != mpp.end()){
//                 for(auto it : mpp[val]){
//                     if(it!= i){
//                         mini = min(mini, abs(i - it));
//                     }
//                 }
//             }
//         } 
//         return (mini == INT_MAX) ? -1 : mini;
//     }
// };
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& a) {
        unordered_map<int, int> mpp;
        int n = a.size(), ans = 1e6;

        for (int i = 0; i < n; i++) {
            if (mpp.count(a[i])) {
                ans = min(ans, i - mpp[a[i]]);
            }
            mpp[reverse(a[i])] = i;
        }
        return ans == 1e6 ? -1 : ans;
    }
};