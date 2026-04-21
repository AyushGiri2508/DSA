class Solution {
public:
bool ispossible(vector<int>& arr, int h,int mid){
      long long val=0;
      for(int i=0;i<arr.size();i++){
            val+=(arr[i]+(long long)mid-1)/mid;
      } 
      return val<=h; 
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int end=piles[0];
        for(int i=0;i<piles.size();i++){
            if(piles[i]>end){
                end=piles[i];
            }
        }
        int ans=end;
        while(s<=end){
            int mid=s+(end-s)/2;
            if(ispossible(piles,h,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};