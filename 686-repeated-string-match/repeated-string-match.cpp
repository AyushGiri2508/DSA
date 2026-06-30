class Solution {
public:
    const long long BASE = 31;
    const long long MOD = 1000000007;
    bool rabinKarp(string &text, string &pattern) {
        int n = text.size(), m = pattern.size();
        if (m > n) return false;
        long long patternHash = 0, textHash = 0;
        long long power = 1;
        for (int i = 0; i < m - 1; i++)
            power = (power * BASE) % MOD;
        for (int i = 0; i < m; i++) {
            patternHash = (patternHash * BASE + (pattern[i] - 'a' + 1)) % MOD;
            textHash = (textHash * BASE + (text[i] - 'a' + 1)) % MOD;
        }
        for (int i = 0; i <= n - m; i++) {
            if (patternHash == textHash) {
                if (text.substr(i, m) == pattern)
                    return true;
            }
            if (i < n - m) {
                textHash = (textHash - (text[i] - 'a' + 1) * power % MOD + MOD) % MOD;
                textHash = (textHash * BASE + (text[i + m] - 'a' + 1)) % MOD;
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int count = 1;

        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }

        if (rabinKarp(repeated, b))
            return count;

        repeated += a;

        if (rabinKarp(repeated, b))
            return count + 1;

        return -1;
    }
};