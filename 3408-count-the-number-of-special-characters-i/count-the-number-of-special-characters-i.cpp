class Solution {
public:
    int numberOfSpecialChars(string word) {
       vector<bool> hasLower(26, false);
        vector<bool> hasUpper(26, false);       
        for (char c : word) {
            if (c >= 'a' && c <= 'z') {
                hasLower[c - 'a'] = true;
            } else if (c >= 'A' && c <= 'Z') {
                hasUpper[c - 'A'] = true;
            }
        }      
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (hasLower[i] && hasUpper[i]) {
                count++;
            }
        }   
        return count;
    }
};