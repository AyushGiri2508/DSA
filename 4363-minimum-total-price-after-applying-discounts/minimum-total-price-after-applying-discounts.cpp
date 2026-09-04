class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
    int n=discounts.size();
    int m=prices.size();
     double sum=0;
             int cnt = min(n, m);
             for(int i=0;i<prices.size();i++){
            sum+=prices[i];
        }
        for (int i = 0; i < cnt; i++) {
            sum -= prices[m - 1 - i] * ( discounts[n - 1 - i]) / 100.0;
            // sum += val;
        }

        return sum;
    }
};