class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.begin(),cost.end(),greater<int>());
        // if(n<=2){
        //     int ans=cost[0]+cost[1];
        //     return ans;
        // }
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==0){
              ans=ans+cost[i]; 
            }
           else if((i+1)%3==0){
                continue;
            }
            else{
                 ans=ans+cost[i];
            }
        }
        return ans;
    }
};