class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b) {
        return (a[1] - a[0]) > (b[1] - b[0]);
    }

    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(), cmp);

        int ans = 0;
        int cur = 0;

        for(auto &t : tasks) {

            int actual = t[0];
            int minimum = t[1];

            if(cur < minimum) {
                ans += (minimum - cur);
                cur = minimum;
            }

            cur -= actual;
        }

        return ans;
    }
};