class Solution {
    public:
        int minimumArea(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            int top = 0, bottom = n - 1, left = 0, right = m - 1;
            while (top < n && all_of(grid[top].begin(), grid[top].end(), [](int x){ return x == 0; }))
                top++;
            while (bottom >= 0 && all_of(grid[bottom].begin(), grid[bottom].end(), [](int x){ return x == 0; }))
                bottom--;
            while (left < m) {
                bool has1 = false;
                for (int i = 0; i < n; i++) if (grid[i][left] == 1) { has1 = true; break; }
                if (has1) break;
                left++;
            }
            while (right >= 0) {
                bool has1 = false;
                for (int i = 0; i < n; i++) if (grid[i][right] == 1) { has1 = true; break; }
                if (has1) break;
                right--;
            }
            if (top > bottom || left > right) return 0;
            return (bottom - top + 1) * (right - left + 1);
        }
    };