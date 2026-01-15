class Solution {
public:

     int longestConsecutive(vector<int>& bars) {
        sort(bars.begin(), bars.end());
        int maxLen = 1, curr = 1;

        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1) {
                curr++;
            } else {
                maxLen = max(maxLen, curr);
                curr = 1;
            }
        }
        maxLen = max(maxLen, curr);
        return maxLen + 1; 
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
       int hGap = longestConsecutive(hBars);
        int vGap = longestConsecutive(vBars);

        int side = min(hGap, vGap);
        return side * side;
    }
};