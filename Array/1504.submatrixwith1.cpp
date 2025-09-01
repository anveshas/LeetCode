class Solution {
    public:
        int numSubmat(vector<vector<int>>& mat) {
            int n = mat.size();
            int m = mat[0].size();
            vector<vector<int>> height(n, vector<int>(m, 0));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (mat[i][j] == 0) height[i][j] = 0;
                    else height[i][j] = (i == 0 ? 1 : height[i-1][j] + 1);
                }
            }
            int total = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (height[i][j] > 0) {
                        int minH = height[i][j];
    
                        for (int k = j; k >= 0 && height[i][k] > 0; k--) {
                            minH = min(minH, height[i][k]);
                            total += minH;
                        }
                    }
                }
            }
            return total;
        }
    };