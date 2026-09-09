class Solution {
public:
    long long countCommas(long long n) {
        if (n <= 999) {
            return 0;
        }
        long long ans = 0;
        long long start = 1000;
        long long commas = 1;
        while (start <= n) {
            long long end = min(n, start * 1000 - 1);
            long long count = end - start + 1;
            ans += count * commas;
            start *= 1000;
            commas++;
        }
        return ans;
    }
};