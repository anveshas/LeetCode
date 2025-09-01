class Solution {
    public:
        vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
            int n = mat.size(), m = mat[0].size();
            for (int col = 0; col < m; ++col) {
                sortDiagonal(mat, 0, col, n, m);
            }
            for (int row = 1; row < n; ++row) {
                sortDiagonal(mat, row, 0, n, m);
            }
            return mat;
        }
    
    private:
        void sortDiagonal(vector<vector<int>>& mat, int row, int col, int n, int m) {
            vector<int> diag;
            int r = row, c = col;
            while (r < n && c < m) {
                diag.push_back(mat[r][c]);
                ++r; ++c;
            }
            sort(diag.begin(), diag.end());
            r = row; c = col;
            int idx = 0;
            while (r < n && c < m) {
                mat[r][c] = diag[idx++];
                ++r; ++c;
            }
        }
    };