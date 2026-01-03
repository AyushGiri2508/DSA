class Solution {
public:
    int numOfWays(int n) {
             const int MOD = 1e9 + 7;

        long long diff = 6;
        long long same = 6; 

        for (int i = 2; i <= n; i++) {
            long long newDiff = (diff * 2 + same * 2) % MOD;
            long long newSame = (diff * 2 + same * 3) % MOD;

            diff = newDiff;
            same = newSame;
        }

        return (diff + same) % MOD;
    }
};