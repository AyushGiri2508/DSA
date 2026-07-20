class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        while(k--){
            vector<vector<int>>temp=grid;
            temp[0][0]=grid[n-1][m-1];
            for(int i=1;i<n;i++){
                temp[i][0] = grid[i - 1][m - 1];
                }
            
             for (int i = 0; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    temp[i][j] = grid[i][j - 1];
                }
            }
            grid=temp;
        }
        return grid;
    }
};