class Solution {
public:
    void computeLPS(string pattern, vector<int>& lps){
        int m = pattern.size();
        lps[0] = 0;
        int length = 0, i = 1;
        while(i < m){
            if(pattern[i] == pattern[length]){
                length++;
                lps[i] = length;
                i++;
            }
            else{
                if(length != 0){
                    length = lps[length - 1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    int strStr(string txt, string pat) {
        int m = pat.size();
        vector<int> lps(m, 0);
        computeLPS(pat, lps);
        int n = txt.size();
        int i = 0, j = 0;
        while(i < n){
            if(txt[i] == pat[j]){
                i++; j++;
            }
            if(j == m){
                return i-j;
            }
            else if(pat[j] != txt[i]){
                if(j != 0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return -1;
    }
};