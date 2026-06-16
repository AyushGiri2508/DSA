class Solution {
public:
    string processStr(string s) {
        string res;

        for(char c : s) {
            if(c == '*') {
                if(!res.empty())
                    res.pop_back();
            }
            else if(c == '#') {
                res += res;      // duplicate whole string
            }
            else if(c == '%') {
                reverse(res.begin(), res.end());
            }
            else {
                res.push_back(c);
            }
        }

        return res;
    }
};