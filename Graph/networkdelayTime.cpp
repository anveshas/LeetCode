class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>> > adj(n+1);
        for(auto it: times){
            int src = it[0];
            int dest = it[1];
            int time = it[2];
            adj[src].push_back({dest, time});
        }
        vector<int> time(n+1, INT_MAX);
        time[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});
        while(!q.empty()){
            auto [curr_time, node] = q.top();
            q.pop();
            if (curr_time > time[node]) continue;

            for(auto [adjNode, reach_time]: adj[node]){
                if(time[adjNode] > curr_time + reach_time){
                    time[adjNode] = curr_time + reach_time;
                    q.push({curr_time + reach_time, adjNode});
                }
            }
        }
        int max_time = INT_MIN;
        for(int i = 1; i <= n; i++){
            if(time[i] == INT_MAX){
                return -1;
            }
            max_time = max(max_time, time[i]);
        }
        return max_time;
    }
};