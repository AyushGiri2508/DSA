class Solution {
public:
    vector<int> spf;

    void sieve(int MAXV) {
        spf.resize(MAXV + 1);

        for (int i = 0; i <= MAXV; i++) {
            spf[i] = i;
        }

        for (int i = 2; i * i <= MAXV; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= MAXV; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    bool isPrime(int x) {
        return x >= 2 && spf[x] == x;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;

        int MAXV = *max_element(nums.begin(), nums.end());

        sieve(MAXV);

        // prime factor -> indices divisible by it
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            unordered_set<int> factors;

            while (x > 1) {
                int p = spf[x];
                factors.insert(p);

                while (x % p == 0) {
                    x /= p;
                }
            }

            for (int p : factors) {
                mp[p].push_back(i);
            }
        }

        queue<int> q;
        vector<int> dist(n, -1);

        q.push(0);
        dist[0] = 0;

        // avoid processing same prime teleport multiple times
        unordered_set<int> usedPrime;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int d = dist[i];

            if (i == n - 1) return d;

            // adjacent left
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = d + 1;
                q.push(i - 1);
            }

            // adjacent right
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = d + 1;
                q.push(i + 1);
            }

            // teleportation
            int val = nums[i];

            if (isPrime(val) && !usedPrime.count(val)) {

                for (int nxt : mp[val]) {
                    if (dist[nxt] == -1) {
                        dist[nxt] = d + 1;
                        q.push(nxt);
                    }
                }

                usedPrime.insert(val);
            }
        }

        return -1;
    }
};