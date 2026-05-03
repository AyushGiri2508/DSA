class Solution {
public:
bool ispossible(vector<int>& arr, int days,int target){
    int currsum=0;
       int n=arr.size();
    int cnt=1;
    for(int i=0;i<n;i++){
        if(arr[i]>target){
            return false;
        }
        if(arr[i]+currsum>target){
            cnt++;
            currsum=arr[i];
            if(cnt>days){
                return false;
            }
        }
        else{
        currsum+=arr[i];
        }
    }
    return true;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
      
        int start=*max_element(weights.begin(), weights.end());
        int end=0;
        for(int i=0;i<n;i++){
            end+=weights[i];
        }
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(ispossible(weights,days,mid)){
                    ans=mid;
                    end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};