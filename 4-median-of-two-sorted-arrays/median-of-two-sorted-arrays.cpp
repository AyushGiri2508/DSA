class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            int element=nums1[i];
            ans.push_back(element);
        }
        for(int i=0;i<nums2.size();i++){
            int item=nums2[i];
            ans.push_back(item);
        }
        sort(ans.begin(),ans.end());
        int start=0;
        int end=ans.size()-1;
        int mid=(start+end)/2;
        if(ans.size()%2==1){
            float val=ans[mid];
            return val;
        }
        else{
            float value=(ans[mid]+ans[mid+1])/2.0;
            return value;
        }
        
    }
};