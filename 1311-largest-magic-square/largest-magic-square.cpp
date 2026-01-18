class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
       int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> row(m, vector<long long>(n+1,0));
        vector<vector<long long>> col(m+1, vector<long long>(n,0));

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++) {
                row[i][j+1] = row[i][j] + grid[i][j];
                col[i+1][j] = col[i][j] + grid[i][j];
            }

        for(int k=min(m,n); k>=2; k--) {
            for(int i=0;i+k<=m;i++) {
                for(int j=0;j+k<=n;j++) {
                    long long target = row[i][j+k] - row[i][j];
                    bool ok = true;

                    for(int x=0;x<k && ok;x++) {
                        if(row[i+x][j+k] - row[i+x][j] != target) ok = false;
                        if(col[i+k][j+x] - col[i][j+x] != target) ok = false;
                    }

                    long long d1=0,d2=0;
                    for(int x=0;x<k;x++) {
                        d1 += grid[i+x][j+x];
                        d2 += grid[i+x][j+k-x-1];
                    }

                    if(ok && d1==target && d2==target)
                        return k;
                }
            }
        }
        return 1; 
    }
};