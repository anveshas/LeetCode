class Solution {
public:
    long long total_hrs1(vector<int>& piles, int hrs){
        long long n = piles.size();
        long long cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += ceil((double)piles[i] / (double)hrs);
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1, high = *max_element(piles.begin(), piles.end());
        long long mid = low + (high-low)/ 2;
        while(low <= high){
            mid = low + (high-low)/ 2;
            long long total_hrs = total_hrs1(piles, mid);
            // if(total_hrs == h){
            //     return mid;
            // }
            if(total_hrs <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};