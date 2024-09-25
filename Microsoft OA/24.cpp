#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Function to check if a valid path exists with the given maxValue
bool canTraverse(const vector<int>& A, const vector<int>& B, int maxValue) {
    int n = A.size();
    // Create a visited matrix to keep track of visited cells in A and B
    vector<vector<bool>> visited(2, vector<bool>(n, false));
    queue<pair<int, int>> q; // Queue for BFS

    // Start BFS from A[0] if its value is within the allowed maxValue
    if (A[0] <= maxValue) {
        q.push({0, 0}); // Start from the top-left corner A[0]
        visited[0][0] = true; // Mark as visited
    }

    // Perform BFS to explore paths
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // If we reach the bottom-right cell B[n-1], a valid path is found
        if (row == 1 && col == n - 1) return true;

        // Check to move right in the same row
        if (col + 1 < n) {
            // Move right in row A
            if (row == 0 && A[col + 1] <= maxValue && !visited[0][col + 1]) {
                visited[0][col + 1] = true; // Mark new position as visited
                q.push({0, col + 1}); // Enqueue the new position
            }
            // Move right in row B
            if (row == 1 && B[col + 1] <= maxValue && !visited[1][col + 1]) {
                visited[1][col + 1] = true; // Mark new position as visited
                q.push({1, col + 1}); // Enqueue the new position
            }
        }

        // Check to move down from A to B
        if (row == 0 && B[col] <= maxValue && !visited[1][col]) {
            visited[1][col] = true; // Mark the position in B as visited
            q.push({1, col}); // Enqueue the new position in B
        }

        // Check to move up from B to A
        if (row == 1 && A[col] <= maxValue && !visited[0][col]) {
            visited[0][col] = true; // Mark the position in A as visited
            q.push({0, col}); // Enqueue the new position in A
        }
    }

    // Return false if no valid path is found
    return false;
}

// Function to find the minimum possible maximum value on the path from A[0] to B[n-1]
int solution(vector<int>& A, vector<int>& B) {
    int n = A.size();
    // Set initial binary search bounds
    int left = min(A[0], B[n - 1]); // Minimum possible max value
    int right = max(*max_element(A.begin(), A.end()), *max_element(B.begin(), B.end())); // Maximum possible max value

    int result = right; // Initialize result with the maximum possible value

    // Binary search for the minimum possible maximum value
    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate mid value

        // Check if a valid path exists with the current maximum value 'mid'
        if (canTraverse(A, B, mid)) {
            result = mid;       // Update result as a potential minimum
            right = mid - 1;    // Try to find a smaller maximum value
        } else {
            left = mid + 1;     // Increase the allowed maximum value
        }
    }

    return result; // Return the minimum possible maximum value on the path
}