class Solution {
public:
    int reverseDegree(string s) {
            int hash[256]={0};          
        for(char ch = 'a'; ch <= 'z'; ch++) {
            hash[ch] = 26 - (ch - 'a');
        }
            int sum=0;
            for(int i=0;i<s.length();i++){
                sum+= hash[s[i]]*(i+1);
            }
        return sum;
    }
};