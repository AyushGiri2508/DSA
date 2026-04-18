class Solution {
public:
    string removeStars(string s) {
        string str="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
            str.pop_back();
            }
            else{
                str+=s[i];
            }
        }
        return str;
    }
};