class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int full = numBottles, empty = 0, res = 0, exchange = numExchange;
        while (full > 0) {
            res += full;
            empty += full;
            full = 0;

            if (empty >= exchange) {
                empty -= exchange;
                full += 1;
                exchange++;
            }
        }
        return res;
    }
};