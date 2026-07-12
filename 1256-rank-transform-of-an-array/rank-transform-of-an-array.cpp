class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mpp;

        // Store unique elements
        for (int x : arr) {
            mpp[x];
        }

        // Assign ranks
        int rank = 1;
        for (auto &it : mpp) {
            it.second = rank++;
        }

        // Replace elements with their ranks
        vector<int> ans;
        for (int x : arr) {
            ans.push_back(mpp[x]);
        }

        return ans;
    }
};