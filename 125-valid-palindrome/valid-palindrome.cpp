class Solution {
public:
    bool isPalindrome(string s) {
        if(s==" "){
            return true;
        }
        string b="";
        for(int i=0;i<s.size();i++){
            if (isalnum(s[i])) {
                b += tolower(s[i]);
            }
        }
        int i=0;
        int j=b.length()-1;
        while(i<j){
            if(b[i]!=b[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};