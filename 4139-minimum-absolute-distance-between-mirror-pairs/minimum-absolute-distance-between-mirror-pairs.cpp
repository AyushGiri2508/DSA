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
    int minMirrorPairDistance(vector<int>& nums) {
        int res = 100000, i = 0;
        unordered_map<int, int> seen;

        for (int& n : nums) {
            int r;
            if (seen.count(n))
                res = min(res, i - seen[n]);

            for (r = 0; n; n /= 10)
                r = r * 10 + (n % 10);

            seen[r] = i++;
        }

        return -(res == 100000) | res;
    }
};