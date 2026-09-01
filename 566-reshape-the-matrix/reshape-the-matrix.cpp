class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<int>val;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                val.push_back(mat[i][j]);

            }
        }
        if(m * n != r * c){
    return mat;
}
    vector<vector<int>> ans(r, vector<int>(c));
    int b=0;
     for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans[i][j]=val[b];
            b++;
            }
        }
        return ans;
    }
};