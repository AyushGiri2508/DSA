class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // int curr=0;
        // int maxi=0;
        // for(int i=0;i<nums1.size();i++){
        //     for(int j=0;j<nums2.size();j++){
        //         if(i<=j&&nums1[i]<=nums2[j]){
        //             curr=j-i;
        //             maxi=max(maxi,curr);
        //         }
        //     }
        // }
        // return maxi;
          int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        int maxi = 0;

        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                maxi = max(maxi, j - i);
                j++; 
            } else {
                i++; 
            }
        }
        return maxi;
    }
};