// class Solution {
// public:
//     vector<int> pivotArray(vector<int>& nums, int pivot) {
//         vector<int> ans;
//         vector<int> ans1;
//         vector<int> ans2;
//         int cnt = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] < pivot) {
//                 ans1.push_back(nums[i]);
//             }
//             if (nums[i] >= pivot) {
//                 if (nums[i] == pivot) {
//                     cnt++;
//                 } else {
//                     ans2.push_back(nums[i]);
//                 }
//             }
//         }
//             for (int i = 0; i < ans1.size(); i++) {
//                 ans.push_back(ans1[i]);
//             }
//             while (cnt--) {
//                 ans.push_back(pivot);
//             }
//             for (int i = 0; i < ans2.size(); i++) {
//                 ans.push_back(ans2[i]);
//             }
//             return ans;
//         }
//     };
// class Solution {
// public:
//     vector<int> pivotArray(vector<int>& nums, int pivot) {
//         vector<int> ans;
//         // ans.reserve(nums.size());

//         int cnt = 0;

//         for (int x : nums) {
//             if (x < pivot)
//                 ans.push_back(x);
//             else if (x == pivot)
//                 cnt++;
//         }

//         while (cnt--)
//             ans.push_back(pivot);

//         for (int x : nums) {
//             if (x > pivot)
//                 ans.push_back(x);
//         }

//         return ans;
//     }

// };


class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);

        int left = 0;
        int right = n - 1;

        // Fill smaller elements from left
        // Fill greater elements from right
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                ans[left++] = nums[i];
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > pivot) {
                ans[right--] = nums[i];
            }
        }

        while (left <= right) {
            ans[left++] = pivot;
        }

        return ans;
    }
};