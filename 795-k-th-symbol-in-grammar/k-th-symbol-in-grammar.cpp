// class Solution {
// public:
//     int kthGrammar(int n, int k) {
//         if (n == 1)
//             return 0;
//         int parent = kthGrammar(n - 1, (k + 1) / 2);
//         if (k % 2 == 1)
//             return parent;
//         else
//             return 1 - parent;
//     }
// };

class Solution {
public:
    int kthGrammar(int n, int k) {
        return __builtin_popcount(k - 1) % 2;
    }
};