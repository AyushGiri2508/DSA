// class Solution {
// public:
// int solve(string s){
//     int cnt=1;
//     int ans=1;
//       int n=s.length();
//    for(int i=1;i<n;i++){
//     if(s[i]==s[i-1]){
//         cnt++;
//     }
//     else{
//         cnt=1;
//     }
//     ans=max(ans,cnt);
//    }
    
//     return ans;
// }
//     vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
//         int n=s.length();
//         vector<int>ans;
//         int m=queryCharacters.size();
//        for(int i=0;i<m;i++){
//         s[queryIndices[i]]=queryCharacters[i];
//         int val=solve(s);
//         ans.push_back(val);
//        }
//        return ans;
//     }
// };
// class Solution {
// public:

//     vector<int> longestRepeating(string s,
//                                  string queryCharacters,
//                                  vector<int>& queryIndices) {

//         int n = s.size();

//         // Store the length of every consecutive run.
//         // multiset keeps them sorted automatically.
//         multiset<int> lengths;

//         // start -> end of each run
//         map<int, int> runs;

//         // Build initial runs
//         int start = 0;

//         for (int i = 1; i <= n; i++) {

//             if (i == n || s[i] != s[i - 1]) {
//                 runs[start] = i - 1;
//                 lengths.insert(i - start);
//                 start = i;
//             }
//         }

//         vector<int> ans;

//         for (int q = 0; q < queryCharacters.size(); q++) {

//             int pos = queryIndices[q];
//             char newChar = queryCharacters[q];

//             if (s[pos] == newChar) {
//                 ans.push_back(*lengths.rbegin());
//                 continue;
//             }

//             // Find the run containing pos
//             auto it = runs.upper_bound(pos);
//             --it;

//             int L = it->first;
//             int R = it->second;

//             // Remove old run length
//             auto old = lengths.find(R - L + 1);
//             lengths.erase(old);

//             // Remove old run
//             runs.erase(it);

//             // Left part: [L, pos-1]
//             if (L <= pos - 1) {
//                 runs[L] = pos - 1;
//                 lengths.insert(pos - L);
//             }

//             // Right part: [pos+1, R]
//             if (pos + 1 <= R) {
//                 runs[pos + 1] = R;
//                 lengths.insert(R - pos);
//             }

//             s[pos] = newChar;

//             // Add the new character as a separate run
//             runs[pos] = pos;
//             lengths.insert(1);

//             // Merge with left run if same character
//             auto cur = runs.find(pos);

//             if (cur != runs.begin()) {

//                 auto left = prev(cur);

//                 if (s[left->second] == s[pos]) {

//                     int leftL = left->first;
//                     int leftR = left->second;

//                     // Remove lengths
//                     lengths.erase(lengths.find(leftR - leftL + 1));
//                     lengths.erase(lengths.find(1));

//                     // Remove current and left runs
//                     runs.erase(left);
//                     runs.erase(pos);

//                     // Create merged run
//                     runs[leftL] = pos;

//                     lengths.insert(pos - leftL + 1);
//                 }
//             }

//             // Find current run again
//             auto current = runs.upper_bound(pos);
//             --current;

//             // Merge with right run if same character
//             auto right = next(current);

//             if (right != runs.end()) {

//                 if (s[right->second] == s[pos]) {

//                     int curL = current->first;
//                     int curR = current->second;

//                     int rightL = right->first;
//                     int rightR = right->second;

//                     // Remove lengths
//                     lengths.erase(lengths.find(curR - curL + 1));
//                     lengths.erase(lengths.find(rightR - rightL + 1));

//                     // Remove runs
//                     runs.erase(current);
//                     runs.erase(right);

//                     // Merge
//                     runs[curL] = rightR;

//                     lengths.insert(rightR - curL + 1);
//                 }
//             }

//             // Largest run
//             ans.push_back(*lengths.rbegin());
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> longestRepeating(string s, string chars, vector<int>& indices) {
        int n = s.size();

        set<int> boundaries;
        set<int> lengths;
        vector<int> count(n+1);

        auto addlen = [&](int len) {
            if (++count[len] == 1)
                lengths.insert(len);
        };

        auto removelen = [&](int len) {
            if (--count[len] == 0)
                lengths.erase(len);
        };

        boundaries.insert(0);
        boundaries.insert(n);
        int prev = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i - 1] != s[i]) {
                boundaries.insert(i);
                addlen(i - prev);
                prev = i;
            }
        }
        addlen(n - prev);

        auto update = [&](int i, bool set) {
            if (set) {
                auto it = boundaries.lower_bound(i);
                int next = *it;
                int prev = *std::prev(it);

                removelen(next - prev);
                addlen(i - prev);
                addlen(next - i);

                boundaries.insert(i);
            } else {
                auto it = boundaries.find(i);
                int prev = *std::prev(it);
                int next = *std::next(it);

                removelen(i - prev);
                removelen(next - i);
                addlen(next - prev);

                boundaries.erase(it);
            }
        };

        vector<int> result(indices.size());

        for (int i = 0; i < indices.size(); ++i) {
            int idx = indices[i];
            char c = chars[i];

            if (idx > 0) {
                bool old = s[idx - 1] != s[idx];
                bool now = s[idx - 1] != c;
                if (old != now)
                    update(idx, now);
            }
            if (idx + 1 < n) {
                bool old = s[idx] != s[idx + 1];
                bool now = c != s[idx + 1];
                if (old != now)
                    update(idx + 1, now);
            }

            s[idx] = c;
            result[i] = *lengths.rbegin();
        }

        return result;
    }
};