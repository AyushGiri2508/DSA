class Solution {
public:
bool ispossible(string &s,int i,int j){
    if(i>=j){
        return true;
    }
    if(s[i]==s[j]){
        return ispossible(s,i+1,j-1);
    }

    return false;
}
    string longestPalindrome(string s) {
            int n=s.size();
            int currindex=0;
            int maxlen=INT_MIN;
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    if(ispossible(s,i,j)==true){
                        if(maxlen<j-i+1){
                            maxlen=j-i+1;
                            currindex=i;
                        }
                    }
                }
            }
            return s.substr(currindex,maxlen);
    }
};