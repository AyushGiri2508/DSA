class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum=0;
        sort(happiness.begin(),happiness.end(),greater<int>());      
            for(int i=0;i<k;i++){
               int ans= happiness[i]-i;
               if(ans<0)break;
               sum+=ans;    
            }   
        return sum;
    }
};