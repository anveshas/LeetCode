class Solution {
    public:
        int countSquares(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
            vector<vector<int>> grid = matrix;
            for(int i = 1; i < n; i++){
                for(int j = 1; j < m; j++){
                    if(matrix[i][j] == 1){
                        // if(matrix[i][j-1] == 1 && matrix[i-1][j] == 1 && matrix[i-1][j-1] == 1){
                        //     grid[i][j] += 1;
                        // }
                        grid[i][j] = 1 + min({grid[i-1][j], grid[i][j-1], grid[i-1][j-1]});
                    }
                }
            }
            int sum = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    sum += grid[i][j];
                }
            }
            return sum;
        }
    };