class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> store(n, vector<int> (m, 0));
        store[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (obstacleGrid[i][j] == 1) {
                    store[i][j] = 0;
                    continue;
                }

                if (i == 0 && j == 0) continue;
                int up = (i > 0) ? store[i-1][j] : 0;
                int left = (j > 0) ? store[i][j-1] : 0;

                store[i][j] = up + left;
            }
        }
        return store[n - 1][m - 1];
    }
};