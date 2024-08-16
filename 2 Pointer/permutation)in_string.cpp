class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        for(char ch: s1){
            mp[ch]++;
        }
        int left = 0, right = 0;
        int count = mp.size();
        while(right < s2.size()){
            if(mp.find(s2[right]) != mp.end()){
                mp[s2[right]]--;
                if(mp[s2[right]] == 0){
                    count--;
                }
            }
            while(count == 0){
                if(right - left + 1 == s1.size()){
                    return true;
                }
                if(mp.find(s2[left]) != mp.end()){
                    mp[s2[left]]++;
                    if(mp[s2[left]] > 0){
                        count++;
                    }
                }
                left++;
            }
            right++;
        }
        return false;
    }
};