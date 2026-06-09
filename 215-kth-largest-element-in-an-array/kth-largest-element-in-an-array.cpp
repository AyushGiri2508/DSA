// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int,vector<int>,greater<int>>pq;
//         int n=nums.size();
//         for(int i=0;i<k;i++){
//             pq.push(nums[i]);
//         }
//         for(int i=k;i<n;i++){
//             if(nums[i]>pq.top()){
//                 pq.pop();
//                 pq.push(nums[i]);
//             }
//         }
//     return pq.top();
//     }
// };
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            pq.push(num);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};