class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // cnt[g] = number of pairs whose gcd is exactly g
        vector<long long> cnt(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            long long total = 0;

            for (int multiple = g; multiple <= mx; multiple += g)
                total += freq[multiple];

            cnt[g] = total * (total - 1) / 2;

            for (int multiple = 2 * g; multiple <= mx; multiple += g)
                cnt[g] -= cnt[multiple];
        }

        // prefix[i] = number of pairs with gcd <= i
        vector<long long> prefix(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            prefix[i] = prefix[i - 1] + cnt[i];

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};