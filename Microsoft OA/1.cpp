#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int>& start, vector<int>& dest, int N, vector<int>& limit, int K) {
    int total_cost = 0;
    int max_station = 0;

    for (int i = 0; i < N; ++i) {
        int distanceCost = 2 * abs(start[i] - dest[i]);
        int rideCost = 1 + distanceCost;
        total_cost += rideCost;

        max_station = max(max_station, max(start[i], dest[i]));
    }

    if (total_cost > limit[max_station]) {
        total_cost = limit[max_station];
    }

    return total_cost;
}

int main() {
    vector<int> start = {1, 0, 2, 4};
    vector<int> dest = {2, 2, 0, 5};
    vector<int> limit = {3, 17, 7, 4, 5, 17};
    int N = start.size();
    int K = limit.size();

    cout << solution(start, dest, N, limit, K) << endl;
    
    vector<int> start2 = {1, 2, 0, 2, 3};
    vector<int> dest2 = {2, 1, 2, 1, 2};
    vector<int> limit2 = {4, 8, 18, 16, 20};
    
    cout << solution(start2, dest2, start2.size(), limit2, limit2.size()) << endl;  // Output: 16

    // Example 3
    vector<int> start3 = {2, 2};
    vector<int> dest3 = {4, 3};
    vector<int> limit3 = {1, 1, 1, 1, 9, 1, 1};
    
    cout << solution(start3, dest3, start3.size(), limit3, limit3.size()) << endl;  // Output: 8

    return 0;
}
