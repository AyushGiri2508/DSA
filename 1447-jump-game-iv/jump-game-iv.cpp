class Solution {
public:

    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if (n == 1) {
            return 0;
        }

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                int idx = q.front();
                q.pop();

                if (idx == n - 1) {
                    return steps;
                }

                // i - 1
                if (idx - 1 >= 0 && !vis[idx - 1]) {
                    vis[idx - 1] = 1;
                    q.push(idx - 1);
                }

                // i + 1
                if (idx + 1 < n && !vis[idx + 1]) {
                    vis[idx + 1] = 1;
                    q.push(idx + 1);
                }

                // same value jumps
                for (auto next : mp[arr[idx]]) {

                    if (!vis[next]) {
                        vis[next] = 1;
                        q.push(next);
                    }
                }

                // important optimization
                mp[arr[idx]].clear();
            }

            steps++;
        }

        return -1;
    }
};