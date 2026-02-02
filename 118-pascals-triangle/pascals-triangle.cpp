class Solution {
public:
    vector<vector<int>> generate(int numRows) {
            vector<vector<int>> ans;

    for(int i = 0; i < numRows; i++) {
        vector<int> row;
        long long val = 1;
        row.push_back(val);

        for(int j = 1; j <= i; j++) {
            val = val * (i - j + 1) / j;
            row.push_back(val);
        }
        ans.push_back(row);
    }
    return ans;

    }
};