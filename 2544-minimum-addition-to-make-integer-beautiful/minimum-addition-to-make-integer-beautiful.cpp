class Solution {
public:
    long long digitSum(long long n) {
        long long sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    long long makeIntegerBeautiful(long long n, int target) {
        long long add = 0;
        long long base = 1;

        while (digitSum(n) > target) {
            long long digit = (n / base) % 10;
            long long inc = (10 - digit) % 10;
            add += inc * base;
            n += inc * base;
            base *= 10;
        }
        return add;
    }
};