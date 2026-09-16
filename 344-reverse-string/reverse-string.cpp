class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
        }
        vector<char> temp;
        while(!st.empty()){
            char ch=st.top();
            temp.push_back(ch);
            st.pop();
        }
        s=temp;
    }
};