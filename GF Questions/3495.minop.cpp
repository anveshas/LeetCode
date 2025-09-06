class Solution {
public:
    static long long sumStepsUpTo(long long n) {
        if (n <= 0) return 0;
        long long ans = 0;
        long long k = 1;
        long long start = 1;
        while (start <= n) {
            long long end = min(n, start * 4 - 1);
            ans += (end - start + 1) * k;
            start *= 4;
            k++;
        }
        return ans;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long final_cnt = 0;
        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            if (l > r) swap(l, r);
            long long totalSteps = sumStepsUpTo(r) - sumStepsUpTo(l - 1);
            final_cnt += (totalSteps + 1) / 2;
        }
        return final_cnt;
    }
};


// TLE2
class Solution {
public:
    int steps(int num) {
        int cnt = 0;
        while(num > 0) {
            num /= 4;
            cnt++;
        }
        return cnt;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long final_cnt = 0;
        
        for(auto &q : queries) {
            int l = q[0], r = q[1];
            long long totalSteps = 0;
            
            for(int x = l; x <= r; x++) {
                totalSteps += steps(x);
            }
            
            final_cnt += (totalSteps + 1) / 2;
        }
        
        return final_cnt;
    }
};


// TLE
class Solution {
public:
    bool all_ele_zero(vector<int>& temp){
        for (int i : temp) {
            if (i != 0) return false;
        }
        return true;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long final_cnt = 0;
        for (auto& q : queries) {
            vector<int> temp;
            for (int j = q[0]; j <= q[1]; j++) {
                temp.push_back(j);
            }
            int cnt = 0;
            while (true) {
                if (all_ele_zero(temp)) {
                    final_cnt += cnt;
                    break;
                }
                sort(temp.rbegin(), temp.rend()); 
                int a = temp[0];
                int b = temp[1];
                temp[0] = a / 4;
                temp[1] = b / 4;

                cnt++;
            }
        }
        return final_cnt;
    }
};