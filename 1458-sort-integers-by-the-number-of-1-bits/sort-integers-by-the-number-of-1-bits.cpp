class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
         vector<pair<int,int>> temp;
        
        for(int x : arr) {
            temp.push_back({__builtin_popcount(x), x});
        }
        
        sort(temp.begin(), temp.end());
        
        for(int i = 0; i < arr.size(); i++) {
            arr[i] = temp[i].second;
        }
        
        return arr;
        
    }
};