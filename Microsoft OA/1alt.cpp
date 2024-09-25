#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(int start[], int dest[], int N, int limit[], int K) {
    int total_fee = 0;
    int max_station_vis = 0;

    for (int i = 0; i < N; i++) {
        max_station_vis = max(max_station_vis, max(start[i], dest[i]));

        int stationsTravelled = abs(dest[i] - start[i]);
        int tripFee = 1 + 2 * stationsTravelled;

        total_fee += tripFee;
    }
    total_fee = min(total_fee, limit[max_station_vis]);

    return total_fee;
}

int main() {
    // Example inputs
    int start[] = {2,2};
    int dest[] = {4,3};
    int N = 2;
    int limit[] = {1,1,1,1,9,1,1};
    int K = 7;

    int result = solution(start, dest, N, limit, K);
    cout << "Total fee charged: " << result << endl;

    return 0;
}