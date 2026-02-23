class Solution {
public:
    bool hasAllCodes(string s, int k) {

        int n=s.size();

        int met=pow(2,k);

        set<string>st;

        for(int i=0;i<n-k+1;i++){
            string ch=s.substr(i,k);

            st.insert(ch);
        }

        if(st.size()==met)return true;
        else return false;
        
    }
};