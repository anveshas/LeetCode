class Solution {
public:
    bool isHappy(int n) {
        int num = n;
        while(true){
            if(num == 1){
                return true;
            }
            int sum = 0;
            while (num > 0) {
                int digit = num % 10;
                sum += digit * digit;
                num /= 10;
            }
            num = sum;
            if(num == 4){
                return false;
            }
        }
        return false;
    }
};