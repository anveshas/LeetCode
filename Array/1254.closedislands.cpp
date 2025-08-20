class Solution {
    public:
        bool dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& is_visited) {
            int n = grid.size(), m = grid[0].size();
            
            if (i < 0 || j < 0 || i >= n || j >= m) return false;
            if (grid[i][j] == 1 || is_visited[i][j]) return true;
    
            is_visited[i][j] = 1;
            bool up    = dfs(grid, i - 1, j, is_visited);
            bool down  = dfs(grid, i + 1, j, is_visited);
            bool left  = dfs(grid, i, j - 1, is_visited);
            bool right = dfs(grid, i, j + 1, is_visited);
    
            return up && down && left && right;
        }
    
        int closedIsland(vector<vector<int>>& grid) {
            int n = grid.size(), m = grid[0].size();
            vector<vector<int>> is_visited(n, vector<int>(m, 0));
            int count = 0;
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 0 && !is_visited[i][j]) {
                        if (dfs(grid, i, j, is_visited)) {
                            count++;
                        }
                    }
                }
            }
            return count;
        }
    };