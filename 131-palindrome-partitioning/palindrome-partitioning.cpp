class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string &s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    void solve(int index, string &s, vector<string> &path) {
        if(index == s.size()) {
            ans.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); i++) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                solve(i + 1, s, path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        solve(0, s, path);
        return ans;
    }
};