class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        unordered_set<int> st;
        
        for (int c = 1; c <= n; c++) {
            st.insert(c * c);
        }
        
        for (int a = 1; a <= n; a++) {
            int aa = a * a;
            for (int b = 1; b <= n; b++) {
                int bb = b * b;
                int sum = aa + bb;
                if (st.count(sum)) {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};
