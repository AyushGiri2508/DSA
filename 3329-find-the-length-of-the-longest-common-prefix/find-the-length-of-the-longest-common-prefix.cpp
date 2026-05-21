class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_set<int> st;

        // Store all prefixes of arr1
        for(int num : arr1) {

            while(num > 0) {
                st.insert(num);
                num /= 10;
            }
        }

        int ans = 0;

        // Check prefixes of arr2
        for(int num : arr2) {

            int temp = num;

            while(temp > 0) {

                if(st.count(temp)) {
                    ans = max(ans, (int)to_string(temp).size());
                }

                temp /= 10;
            }
        }

        return ans;
    }
};