class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') i++;
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        int val = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            if (val > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            val = val * 10 + digit;
            i++;
        }
        return val * sign;
    }
};