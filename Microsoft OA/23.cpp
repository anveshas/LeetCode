#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool canTraverse(const vector<int>& A, const vector<int>& B, int maxValue) {
    int n = A.size();
    vector<vector<bool>> visited(2, vector<bool>(n, false));
    queue<pair<int, int>> q;

    if (A[0] <= maxValue) {
        q.push({0, 0});
        visited[0][0] = true;
    }

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if (row == 1 && col == n - 1) return true;

        if (col + 1 < n) {
            if (row == 0 && A[col + 1] <= maxValue && !visited[0][col + 1]) {
                visited[0][col + 1] = true;
                q.push({0, col + 1});
            }
            if (row == 1 && B[col + 1] <= maxValue && !visited[1][col + 1]) {
                visited[1][col + 1] = true;
                q.push({1, col + 1});
            }
        }

        // Check to move down from A to B
        if (row == 0 && B[col] <= maxValue && !visited[1][col]) {
            visited[1][col] = true;
            q.push({1, col});
        }

        // Check to move up from B to A
        if (row == 1 && A[col] <= maxValue && !visited[0][col]) {
            visited[0][col] = true;
            q.push({0, col});
        }
    }

    return false;
}

int solution(vector<int>& A, vector<int>& B) {
    int n = A.size();
    int left = min(A[0], B[n - 1]);
    int right = *max_element(A.begin(), A.end());
    right = max(right, *max_element(B.begin(), B.end()));

    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canTraverse(A, B, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}
