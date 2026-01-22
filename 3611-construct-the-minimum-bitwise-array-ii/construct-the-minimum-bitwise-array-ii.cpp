class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
      int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int val = nums[i];

            // Edge Case: 2 is the only even prime.
            // In binary, 2 is '10'. It has no trailing ones to support the logic.
            // No integer x exists such that x | (x+1) == 2.
            if (val == 2) {
                ans[i] = -1;
                continue;
            }

            // ==Step 1: Count trailing ones==
            // We can iterate bits starting from 0 until we find a 0.
            int trailingOnes = 0;
            while ((val >> trailingOnes) & 1) {
                trailingOnes++;
            }

            // ==Step 2: Flip the highest bit of the trailing sequence==
            // The bits are at indices 0, 1, ..., trailingOnes-1.
            // To minimize 'ans', we remove the largest power of 2 possible,
            // which corresponds to the bit at index (trailingOnes - 1).
            
            // ^^Example^^: val = 7 (111), trailingOnes = 3. 
            // We flip bit at index 2 (val 4). ans = 7 ^ 4 = 3.
            // Check: 3 | 4 = 7. Correct.
            
            ans[i] = val ^ (1 << (trailingOnes - 1));
        }

        return ans;
    }
};
