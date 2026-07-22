class Solution {
public:
    int solve(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        int prev = 0;
        int curr = 1;

        for (int i = 2; i <= n; i++) {
            int ans = prev + curr;
            prev = curr;
            curr = ans;
        }

        return curr;
    }

    int fib(int n) {
        return solve(n);
    }
};