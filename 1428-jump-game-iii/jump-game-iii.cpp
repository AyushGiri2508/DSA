class Solution {
public:
    bool solve(vector<int>& arr, int start, vector<bool>& vis) {
        int n = arr.size();

        // Out of bounds
        if(start < 0 || start >= n)
            return false;

        // Already visited
        if(vis[start])
            return false;

        // Reached 0
        if(arr[start] == 0)
            return true;

        vis[start] = true;

        // Forward or backward jump
        return solve(arr, start + arr[start], vis) ||
               solve(arr, start - arr[start], vis);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(), false);
        return solve(arr, start, vis);
    }
};