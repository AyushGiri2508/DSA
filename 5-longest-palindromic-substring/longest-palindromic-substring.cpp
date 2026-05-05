class Solution {
public:
    bool ispossible(string &s, int i, int j, vector<vector<int>> &dp) {
        if (i >= j) return true;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) {
            return dp[i][j] = ispossible(s, i + 1, j - 1, dp);
        }

        return dp[i][j] = false;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int start = 0;
        int maxlen = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (ispossible(s, i, j, dp)) {
                    int len = j - i + 1;
                    if (len > maxlen) {
                        maxlen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxlen);
    }
};