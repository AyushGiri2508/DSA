class Solution {
public:
    string findValidPair(string s) {
        vector<int> freq(10, 0);
        for (char c : s) {
            freq[c - '0']++;
        }
        for (int i = 0; i < s.size() - 1; i++) {
            int a = s[i] - '0';
            int b = s[i + 1] - '0';
            if (a != b && freq[a] == a && freq[b] == b) {
                return s.substr(i, 2);
            }
        }
        return "";
    }
};