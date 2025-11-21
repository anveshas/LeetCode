class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        string res;
        unordered_map<char, int> mp;
        for(char ch: s){
            mp[ch]++;
        }
        priority_queue<pair<int, char> > heap;
        for(auto [ch, freq]: mp){
            heap.push({freq, ch});
        }
        while(heap.size() >= 2){
            auto [freq1, ch1] = heap.top();
            heap.pop();
            auto [freq2, ch2] = heap.top();
            heap.pop();
            res += ch1; freq1--;
            res += ch2; freq2--;
            if(freq1 > 0){
                heap.push({freq1, ch1});
            }
            if(freq2 > 0){
                heap.push({freq2, ch2});
            }
        }
        if(!heap.empty()){
            auto [freq, ch] = heap.top();
            if(freq > 1){
                return "";
            }
            res += ch;
        }
        return res;
    }
};