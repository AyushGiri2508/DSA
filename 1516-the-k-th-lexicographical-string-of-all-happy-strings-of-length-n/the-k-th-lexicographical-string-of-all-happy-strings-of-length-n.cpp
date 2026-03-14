class Solution {
public:
string ans="";
    int cnt=0;

    void solve(string &curr,int n,int k){
        if(curr.size()==n){
            cnt++;
            if(cnt==k){
                ans=curr;
            }
            return;
        }

        for(char ch : {'a','b','c'}){
            if(curr.empty() || curr.back()!=ch){
                curr.push_back(ch);
                solve(curr,n,k);
                curr.pop_back();
            }

            if(ans!="") return; 
        }
    }
    string getHappyString(int n, int k) {
        string curr="";
        solve(curr,n,k);
        return ans;

        
    }
};