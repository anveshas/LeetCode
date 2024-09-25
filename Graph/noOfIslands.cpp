class Solution {
public:
    bool isValid(int row, int col, int n, int m){
        return row >= 0 && row < n && col >= 0 && col < m;
    }
    void dfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int n, int m, int r, int c){
        vis[r][c] = 1;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        for(int i = 0; i < 4; i++){
            int row = r + drow[i];
            int col = c + dcol[i];

            if(isValid(row, col, n, m) && vis[row][col] == -1 && grid[row][col] == '1'){
                dfs(grid, vis, n, m, row, col);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, -1));
        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && vis[i][j] == -1){
                    dfs(grid, vis, n, m, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};