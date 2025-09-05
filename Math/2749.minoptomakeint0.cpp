class Solution {
    public:
        int makeTheIntegerZero(int num1, int num2) {
            long long ans = LLONG_MAX; 
            for (int k = 1; k <= 60; k++) {
                long long res = num1 - 1LL * num2 * k;
                if (res < 0) break;
                bool possible = false;
                for (int i = 0; i <= 60; i++) {
                    long long power = (1LL << i);
                    if (res == power) {
                        possible = true;
                        break;
                    }
                }
                if (__builtin_popcountll(res) <= k && k <= res) {
                    ans = min(ans, (long long)k);
                }
            }
            return (ans == LLONG_MAX ? -1 : (int)ans);
        }
    };
    