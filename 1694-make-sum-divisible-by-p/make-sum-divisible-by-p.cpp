class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
      int n = nums.size();
    long long total = 0;
    for (int x : nums) total += x;
    int r = total % p;
    if (r == 0) return 0;

    vector<int> pref(n+1, 0);
    long long running = 0;
    for (int i = 0; i < n; ++i) {
        running += nums[i];
        pref[i+1] = (int)(running % p);
    }

    unordered_map<int, vector<int>> pos;
    pos.reserve(n*2);
    for (int i = 0; i <= n; ++i) {
        pos[pref[i]].push_back(i);
    }

    int ans = n + 1;
    for (int j = 1; j <= n; ++j) {
        int need = (pref[j] - r) % p;
        if (need < 0) need += p;
        auto it = pos.find(need);
        if (it == pos.end()) continue;
        // find largest index i < j
        auto &vec = it->second; // already in increasing order
        auto ub = upper_bound(vec.begin(), vec.end(), j-1);
        if (ub != vec.begin()) {
            --ub;
            int i = *ub;
            if (!(i == 0 && j == n)) { // don't remove whole array
                ans = min(ans, j - i);
            }
        }
    }
    return (ans <= n-1) ? ans : -1;
    }
};