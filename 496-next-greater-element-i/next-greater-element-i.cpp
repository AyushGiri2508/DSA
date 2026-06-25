class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {           unordered_map<int, int> ng;
        stack<int> st;
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                ng[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        vector<int> res;
        for (int num : nums1) {
            res.push_back(ng.count(num) ? ng[num] : -1);
        }
        return res;   
    }
};