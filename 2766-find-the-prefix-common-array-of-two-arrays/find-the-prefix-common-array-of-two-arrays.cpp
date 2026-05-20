class Solution {
public:
void solve(vector<int>& A, vector<int>& B,int i,int j,vector<int>&ans){
    int cnt=0;
    if(j>=A.size()){
        return;
    }
    map<int,int>mpp;
    for(int k=i;k<=j;k++){
        mpp[A[k]]++;
        mpp[B[k]]++;
    }
    for(auto val:mpp){
        if(val.second==2){
            cnt++;
        }
    }
    ans.push_back(cnt);
     solve(A,B,0,j+1,ans);

}
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans;
         int j=0;
         solve(A,B,0,j,ans);
         return ans;
    }
};