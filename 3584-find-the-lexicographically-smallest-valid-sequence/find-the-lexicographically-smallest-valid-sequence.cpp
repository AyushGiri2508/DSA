class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> pos(26);
        for (int i = 0; i < n; i++) {
            pos[word1[i] - 'a'].push_back(i);
        }
        // nextDiff[i] = first index > i
        // whose character differs from word1[i]
        vector<int> nextDiff(n, -1);

        int last1 = -1, last2 = -1;
        char last1Char = '#';

        for (int i = n - 1; i >= 0; i--) {
            if (last1 != -1 && word1[last1] != word1[i]) {
                nextDiff[i] = last1;
            } else {
                nextDiff[i] = last2;
            }

            if (last1 == -1 || word1[i] != last1Char) {
                last2 = last1;
                last1 = i;
                last1Char = word1[i];
            } else {
                last2 = i;
            }
        }

        // prevDiff[i] = last index < i
        // whose character differs from word1[i]
        vector<int> prevDiff(n, -1);

        last1 = -1;
        last2 = -1;
        last1Char = '#';

        for (int i = 0; i < n; i++) {
            if (last1 != -1 && word1[last1] != word1[i]) {
                prevDiff[i] = last1;
            } else {
                prevDiff[i] = last2;
            }

            if (last1 == -1 || word1[i] != last1Char) {
                last2 = last1;
                last1 = i;
                last1Char = word1[i];
            } else {
                last2 = i;
            }
        }

        /*
            exact[j] = largest possible first index
                       for exact matching of word2[j...].

            one[j] = largest possible first index
                     for matching word2[j...] with <= 1 mismatch.
        */
        vector<int> exact(m + 1, -1);
        vector<int> one(m + 1, -1);

        // Empty suffix
        exact[m] = n;
        one[m] = n;

        for (int j = m - 1; j >= 0; j--) {
            int c = word2[j] - 'a';

            // -------------------------------
            // exact[j]
            // -------------------------------
            auto it = lower_bound(
                pos[c].begin(),
                pos[c].end(),
                exact[j + 1]
            );

            if (it != pos[c].begin()) {
                --it;
                exact[j] = *it;
            }

            // -------------------------------
            // one[j]
            // -------------------------------

            // Match current character exactly.
            int match = -1;

            it = lower_bound(
                pos[c].begin(),
                pos[c].end(),
                one[j + 1]
            );

            if (it != pos[c].begin()) {
                --it;
                match = *it;
            }

            // Change current character.
            int mismatch = -1;

            int p = exact[j + 1] - 1;

            if (p >= 0) {
                if (word1[p] != word2[j]) {
                    mismatch = p;
                } else {
                    mismatch = prevDiff[p];
                }
            }

            one[j] = max(match, mismatch);
        }

        if (one[0] == -1) {
            return {};
        }

        vector<int> ans;

        int prev = -1;
        bool mismatchUsed = false;

        for (int j = 0; j < m; j++) {
            int c = word2[j] - 'a';

            // --------------------------------
            // Candidate 1: exact character
            // --------------------------------
            int candidateMatch = -1;

            auto it = upper_bound(
                pos[c].begin(),
                pos[c].end(),
                prev
            );

            if (it != pos[c].end()) {
                candidateMatch = *it;
            }

            int limit = mismatchUsed
                        ? exact[j + 1]
                        : one[j + 1];

            if (candidateMatch == -1 ||
                candidateMatch >= limit) {
                candidateMatch = -1;
            }

            // --------------------------------
            // Candidate 2: use our one mismatch
            // --------------------------------
            int candidateMismatch = -1;

            if (!mismatchUsed) {
                int p = prev + 1;

                if (p < n) {
                    if (word1[p] != word2[j]) {
                        candidateMismatch = p;
                    } else {
                        candidateMismatch = nextDiff[p];
                    }
                }

                if (candidateMismatch == -1 ||
                    candidateMismatch >= exact[j + 1]) {
                    candidateMismatch = -1;
                }
            }

            // --------------------------------
            // Lexicographically smallest index
            // --------------------------------
            int chosen = -1;

            if (candidateMatch != -1) {
                chosen = candidateMatch;
            }

            if (candidateMismatch != -1 &&
                (chosen == -1 || candidateMismatch < chosen)) {
                chosen = candidateMismatch;
            }

            if (chosen == -1) {
                return {};
            }

            ans.push_back(chosen);

            if (word1[chosen] != word2[j]) {
                mismatchUsed = true;
            }

            prev = chosen;
        }

        return ans;
    }
};