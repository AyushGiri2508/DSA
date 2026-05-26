class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lower, upper;

        for(char ch : word) {
            if(islower(ch)) {
                lower.insert(ch);
            }
            else {
                upper.insert(tolower(ch));
            }
        }

        int cnt = 0;

        for(char ch : lower) {
            if(upper.count(ch)) {
                cnt++;
            }
        }

        return cnt;
    }
};