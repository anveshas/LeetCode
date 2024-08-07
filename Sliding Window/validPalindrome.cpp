class Solution {
public:
    bool isPalindrome(string s, int left, int right){
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n-1;
        while(l < r){
            if(s[l] == s[r]){
                l++;
                r--;
            }
            else{
                
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }
        }
        return true;
    }
};