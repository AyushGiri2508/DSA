class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
         int m = grid.size(), n = grid[0].size();

        vector<vector<vector<int>>> dir = {
            {},
            {{0,-1},{0,1}},
            {{-1,0},{1,0}},
            {{0,-1},{1,0}},
            {{0,1},{1,0}},
            {{0,-1},{-1,0}},
            {{0,1},{-1,0}}
        };

        vector<vector<bool>> vis(m, vector<bool>(n,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = true;

        while(!q.empty()){
            auto [i,j] = q.front(); q.pop();

            if(i == m-1 && j == n-1) return true;

            for(auto &d : dir[grid[i][j]]){
                int ni = i + d[0];
                int nj = j + d[1];

                if(ni>=0 && nj>=0 && ni<m && nj<n && !vis[ni][nj]){
                    for(auto &back : dir[grid[ni][nj]]){
                        if(ni + back[0] == i && nj + back[1] == j){
                            vis[ni][nj] = true;
                            q.push({ni,nj});
                            break;
                        }
                    }
                }
            }
        }
        return false;

    }
};