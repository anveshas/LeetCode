class Solution {
public:
    static bool solve(vector<int> stations, long long minPower, int r, int k, int n){
        long long power = reduce(stations.begin(), stations.begin() + r + 1, 0LL);
        for(int i = 0; i < n; i++){
            if(power < minPower){
                long long need = minPower - power;
                if(need > k){
                    return 0;
                }
                k -= need;
                int pos = min(n - 1, i + r);
                stations[pos] += need;
                power += need;
            }
            if(i >= r){
                power -= stations[i - r];
            }
            if(i + r + 1 < n){
                power += stations[i + r + 1];
            }
        }
        return 1;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        const int n = stations.size();
        long long low = 0, high = reduce(stations.begin(), stations.end(), 0LL) + k;
        long long ans = 0;
        while(low <= high){
            long long mid = low + (high - low)/2;
            if(solve(stations, mid, r, k, n)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};