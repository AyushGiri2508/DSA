// class Solution {
// public:
//     vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
//         int product=1;
//         int n=grid.size();
//         int m=grid[0].size();
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 product*=grid[i][j];
//             }
//         }
//         vector<vector<int>>res;
       
//         for(int i=0;i<n;i++){
//              vector<int>ans;
//             for(int j=0;j<m;j++){
//                 int val=product/grid[i][j];
//                 int t=val%12345;
//                 ans.push_back(t);
                
//             }
//             res.push_back(ans);
//         }
//        return res; 
//     }
// };
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int mod = 12345;
        int n = grid.size(), m = grid[0].size();
        
        int total = n * m;
        vector<int> prefix(total, 1), suffix(total, 1);
        
        // Prefix
        for(int i = 1; i < total; i++){
            int r = (i - 1) / m;
            int c = (i - 1) % m;
            prefix[i] = (1LL * prefix[i - 1] * grid[r][c]) % mod;
        }
        
        // Suffix
        for(int i = total - 2; i >= 0; i--){
            int r = (i + 1) / m;
            int c = (i + 1) % m;
            suffix[i] = (1LL * suffix[i + 1] * grid[r][c]) % mod;
        }
        
        vector<vector<int>> res(n, vector<int>(m));
        
        for(int i = 0; i < total; i++){
            int r = i / m;
            int c = i % m;
            res[r][c] = (1LL * prefix[i] * suffix[i]) % mod;
        }
        
        return res;
    }
};