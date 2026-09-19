/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    let low=0;
    let high=nums.length-1;
    let mid= Math.floor(low+(high-low)/2);
    while(low<=high){
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            high=mid-1;
        }
        else{
        low=mid+1;
        }
         mid=Math.floor(low+(high-low)/2);
    }
    return -1;
};