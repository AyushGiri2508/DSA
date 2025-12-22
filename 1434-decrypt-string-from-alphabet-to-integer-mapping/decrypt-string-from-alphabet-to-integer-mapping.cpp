class Solution {
public:
    string freqAlphabets(string s) {
        string res = "";
        int i = s.length() - 1;
        while (i >= 0) {
            if (s[i] == '#') {
                int val = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                res += (char)('a' + val - 1);
                i -= 3;
            } else {
                int val = s[i] - '0';
                res += (char)('a' + val - 1);
                i -= 1;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};