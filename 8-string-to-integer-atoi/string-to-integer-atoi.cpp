class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        // 1. skip spaces
        while (i < n && s[i] == ' ') i++;

        // 2. sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        int val = 0;

        // 3. build number with overflow check
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // 🔥 overflow check BEFORE update
            if (val > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            val = val * 10 + digit;
            i++;
        }

        return val * sign;
    }
};