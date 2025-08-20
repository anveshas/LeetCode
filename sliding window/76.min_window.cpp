class Solution {
    public:
        string minWindow(string s, string t) {
            int n = s.size(), m = t.size();
            int hash[256] = {0}, left = 0, right = 0;
            int min_len = INT_MAX, start_idx = -1, cnt = 0;
            for(char ch: t){
                hash[ch]++;
            }
            while(right < n){
                if(hash[s[right]] > 0){
                    cnt++;
                }
                hash[s[right]]--;
                while(cnt == m){
                    if(min_len > right-left+1){
                        min_len = right-left+1;
                        start_idx = left;
                    }
                    hash[s[left]]++;
                    if(hash[s[left]] > 0){
                        cnt--;
                    }
                    left++;
                }
                right++;
            }
            return start_idx == -1 ? "" : s.substr(start_idx, min_len);
        }
    };