class Solution {
public:
int firstoccurence(vector<int>& nums, int target){
    int ans=-1;
    int start=0;
    int end=nums.size()-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(nums[mid]==target){
            ans=mid;
            end=mid-1;
        }
        else if(nums[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
    
}
int lastoccurence(vector<int>& nums, int target){
    int ans=-1;
    int start=0;
    int end=nums.size()-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(nums[mid]==target){
            ans=mid;
            start=mid+1;
        }
        else if(nums[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
    
}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
       int first=firstoccurence(nums,target);
       int last=lastoccurence(nums,target);
       ans.push_back(first);
       ans.push_back(last);

        return ans;
    }
};