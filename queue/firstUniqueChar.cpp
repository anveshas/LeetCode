class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> q;
        vector<int> arr(26, 0);
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            q.push(i);
            arr[ch - 'a']++;
            while(!q.empty()){
                if(arr[s[q.front()] - 'a'] > 1){
                    q.pop();
                }
                else{
                    break;
                }
            }
        }
        if(q.empty()){
            return -1;
        }
        return q.front();
    }
};

/* Hash Map */

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for(auto ch: s){
            mp[ch]++;
        }
        for(int i = 0; i < s.size(); i++){
            if(mp[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};