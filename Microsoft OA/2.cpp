// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int solution(vector<int>& A, vector<int>& B, int N) {
//     int prev_upper = A[0];
//     int prev_lower = B[0];
//     int n = A.size();
    
//     for (int i = 1; i < n; ++i) {

//         int curr_upper = min(max(prev_upper, A[i]), max(prev_lower, A[i]));
//         int curr_lower = min(max(prev_upper, B[i]), max(prev_lower, B[i]));
        
//         prev_upper = curr_upper;
//         prev_lower = curr_lower;
//     }
    
//     return min(prev_upper, prev_lower);
// }

// int main() {
//     // Example 1
//     vector<int> A1 = {3, 4, 6};
//     vector<int> B1 = {6, 5, 4};
//     cout << solution(A1, B1, 3) << endl; // Output: 5

//     // Example 2
//     vector<int> A2 = {1, 2, 1, 1, 1, 4};
//     vector<int> B2 = {1, 1, 1, 3, 1, 1};
//     cout << solution(A2, B2, 6) << endl; // Output: 2

//     // Example 3
//     vector<int> A3 = {-5, -1, -3};
//     vector<int> B3 = {-5, 5, -2};
//     cout << solution(A3, B3, 3) << endl; // Output: -1

//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    int n = A.size();
    
    // Arrays to store the minimum maximum values
    vector<int> dp_upper(2), dp_lower(2);
    
    // Initialize dp values for the first column
    dp_upper[0] = A[0];
    dp_lower[0] = B[0];
    
    for (int i = 1; i < n; ++i) {
        int curr_upper = min(max(dp_upper[0], A[i]), max(dp_lower[0], A[i]));
        int curr_lower = min(max(dp_upper[0], B[i]), max(dp_lower[0], B[i]));
        
        // Roll over the dp arrays
        dp_upper[1] = curr_upper;
        dp_lower[1] = curr_lower;
        
        // Move to the next column
        dp_upper[0] = dp_upper[1];
        dp_lower[0] = dp_lower[1];
    }
    
    // Return the minimum of the last column values
    return min(dp_upper[0], dp_lower[0]);
}

int main() {
    // Example 1
    vector<int> A1 = {3, 4, 6};
    vector<int> B1 = {6, 5, 4};
    cout << solution(A1, B1) << endl; // Output: 5

    // Example 2
    vector<int> A2 = {1, 2, 1, 1, 1, 4};
    vector<int> B2 = {1, 1, 1, 3, 1, 1};
    cout << solution(A2, B2) << endl; // Output: 2

    // Example 3
    vector<int> A3 = {-5, -1, -3};
    vector<int> B3 = {-5, 5, -2};
    cout << solution(A3, B3) << endl; // Output: -1

    return 0;
}
