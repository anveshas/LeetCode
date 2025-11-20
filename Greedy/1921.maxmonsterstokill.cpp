// correct approch
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> time_to_reach(n);
        for(int i = 0; i < n; i++){
            time_to_reach[i] = (double)dist[i] / speed[i];
        }
        sort(time_to_reach.begin(), time_to_reach.end());
        for(int i = 0; i < n; i++){
            if(time_to_reach[i] <= i){
                return i;
            }
        }
        return n;
    }
};

// wrong answer
class Solution {
public:
    void reduceSpeed(vector<pair<int, int>>& vec){
        for(int i = 0; i < vec.size(); i++){
            vec[i].first -= vec[i].second;
        }
    }
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<pair<int, int>> vec;

        for(int i = 0; i < n; i++){
            vec.push_back({dist[i], speed[i]});
        }
        sort(vec.begin(), vec.end(), [](const pair<int,int> &a, const pair<int,int> &b){
            return a.first < b.first;
        });

        int killed = 0;
        while(!vec.empty()){
            if(vec[0].first <= 0)
                return killed;
            killed++;
            vec.erase(vec.begin());
            reduceSpeed(vec);
            for(auto &p : vec){
                if(p.first <= 0)
                    return killed;
            }
        }
        return killed;
    }
};

