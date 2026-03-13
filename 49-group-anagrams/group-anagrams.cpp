class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        map<string,vector<string>>mpp;
       for(int i=0;i<strs.size();i++){
        string str=strs[i];
        sort(str.begin(),str.end());
        mpp[str].push_back(strs[i]);
       }
       for(auto it : mpp) {
            res.push_back(it.second);
        }
         return res;
    
    }
};