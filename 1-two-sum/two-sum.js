/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let n=nums.length;
    for(let i=0;i<n;i++){
        let val1=nums[i];
        for(let j=i+1;j<n;j++){
            if(val1+nums[j]==target){
                return [i,j];
            }
        }
    }
    return [];
};