#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int>& A, vector<int>& B) {
    int N = A.size();
    vector<vector<int>> dp(2, vector<int>(N, 0));
    
    // Initialize the starting point
    dp[0][0] = A[0];
    dp[1][0] = B[0];
    
    // Fill the DP table
    for (int i = 1; i < N; ++i) {
        dp[0][i] = max(dp[0][i-1], A[i]); // Moving right in the top row
        dp[1][i] = max(dp[1][i-1], B[i]); // Moving right in the bottom row
        dp[1][i] = min(dp[1][i], max(dp[0][i], B[i])); // Moving down from top row to bottom row
    }
    
    return dp[1][N-1]; // Minimum of the maximum values in the optimal path
}