class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
         int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(vis[i][j]) continue;
                
                queue<pair<int,int>> q;
                q.push({i, j});
                vis[i][j] = 1;
                
                map<pair<int,int>, pair<int,int>> parent;
                parent[{i,j}] = {-1,-1};
                
                while(!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();
                    
                    for(auto &d : dirs) {
                        int nr = r + d[0];
                        int nc = c + d[1];
                        
                        if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==grid[r][c]) {
                            
                            if(parent[{r,c}] == make_pair(nr,nc)) continue;
                            
                            if(vis[nr][nc]) return true;
                            
                            vis[nr][nc] = 1;
                            q.push({nr,nc});
                            parent[{nr,nc}] = {r,c};
                        }
                    }
                }
            }
        }
        return false;
    }
};