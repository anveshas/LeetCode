class Solution {
public:
    bool couldShip(vector<int>& weights, int k, int days){
        int sum = 0, day_cnt = 1;
        for (int wt : weights) {
            if (sum + wt > k) {
                day_cnt++;
                sum = wt;
                if (day_cnt > days) return false;
            } else {
                sum += wt;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(couldShip(weights, mid, days)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};