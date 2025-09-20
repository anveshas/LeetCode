// Better Approch
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> userLang(m);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                userLang[i].insert(lang);
            }
        }

        unordered_set<int> unknownUsers;
        for (auto &it : friendships) {
            int u = it[0] - 1;
            int v = it[1] - 1;
            
            bool canTalk = false;
            for (int lang : userLang[u]) {
                if (userLang[v].count(lang)) {
                    canTalk = true;
                    break;
                }
            }

            if (!canTalk) {
                unknownUsers.insert(u);
                unknownUsers.insert(v);
            }
        }

        if (unknownUsers.empty()) return 0;

        vector<int> knowsCount(n + 1, 0);
        for (int user : unknownUsers) {
            for (int lang : userLang[user]) {
                knowsCount[lang]++;
            }
        }

        int maxKnown = 0;
        for (int lang = 1; lang <= n; lang++) {
            maxKnown = max(maxKnown, knowsCount[lang]);
        }

        return (int)unknownUsers.size() - maxKnown;
    }
};



// Old Approch

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();

        unordered_set<int> unknownUsers;
        for(auto it: friendships){
            int u = it[0], v = it[1];

            vector<int> lang1 = languages[u - 1];
            vector<int> lang2 = languages[v - 1];

            vector<int> res;
            sort(lang1.begin(), lang1.end());
            sort(lang2.begin(), lang2.end());
            set_intersection(lang1.begin(), lang1.end(), lang2.begin(), lang2.end(), back_inserter(res));
            if(res.empty()){
                unknownUsers.insert(u);
                unknownUsers.insert(v);
            }
        }
        if (unknownUsers.empty()) return 0;

        int minTeach = INT_MAX;
        for(int lang = 1; lang <= n; lang++){
            int cnt = 0;
            for(auto user: unknownUsers){
                if(find(languages[user-1].begin(), languages[user-1].end(), lang) == languages[user - 1].end()){
                    cnt++;
                }
            }
            minTeach = min(minTeach, cnt);
        }
        return minTeach;
    }
};