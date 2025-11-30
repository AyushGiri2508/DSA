class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
     int n = nums.size();
    long long total = 0;
    for (int x : nums) total += x;
    int r = total % p;
    if (r == 0) return 0;

    unordered_map<int,int> last; // prefix_mod -> latest index
    last.reserve(n*2);
    last[0] = 0;
    int ans = n + 1;
    long long running = 0;
    for (int j = 1; j <= n; ++j) {
        running += nums[j-1];
        int curr = (int)(running % p);
        int need = curr - r;
        need %= p;
        if (need < 0) need += p;
        auto it = last.find(need);
        if (it != last.end()) {
            int i = it->second;
            if (!(i == 0 && j == n)) // don't remove whole array
                ans = min(ans, j - i);
        }
        // store/update latest index for this prefix mod
        last[curr] = j;
    }
    return (ans <= n-1) ? ans : -1;
    }
};