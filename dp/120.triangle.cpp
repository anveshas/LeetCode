// recurrence
class Solution {
public:
    int solve(vector<vector<int>>& triangle, int row, int col) {
        int n = triangle.size();
        if (row == n - 1) return triangle[row][col];

        int down = solve(triangle, row + 1, col);
        int downRight = solve(triangle, row + 1, col + 1);

        return triangle[row][col] + min(down, downRight);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(triangle, 0, 0);
    }
};

// memoization
class Solution {
public:
    int solve(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp) {
        int n = triangle.size();
        if (row == n - 1) return triangle[row][col];

        if(dp[row][col] != INT_MAX){
            return dp[row][col];
        }

        int down = solve(triangle, row + 1, col, dp);
        int downRight = solve(triangle, row + 1, col + 1, dp);

        return dp[row][col] = triangle[row][col] + min(down, downRight);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return solve(triangle, 0, 0, dp);
    }
};

// tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp = triangle;
        dp[0][0] = triangle[0][0];
        for(int row = n - 2; row >= 0; row--){
            for(int col = 0; col <= row; col++){
                dp[row][col] += min(dp[row + 1][col], dp[row + 1][col + 1]);
            }
        }
        return dp[0][0];
    }
};