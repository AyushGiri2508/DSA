class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string second= strs[strs.size()-1];
        string common="";

        int minlen= min(first.length(),second.length());
        for(int i=0;i<minlen;i++) {
            if (first[i] == second[i]) {
            common += first[i];
        } else {
            break; 
        }
    }
    return common;
        
       
    }
};