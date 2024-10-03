class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for(auto it: roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int max_cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cnt = adj[i].size() + adj[j].size();
                if (find(adj[i].begin(), adj[i].end(), j) != adj[i].end()) {
                    cnt--;
                }
                max_cnt = max(max_cnt, cnt);
            }
        }
        return max_cnt;
    }
};

// more optimal

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<bool>> isConnected(n, vector<bool> (n, false));
        for(auto &it: roads){
            degree[it[0]]++;
            degree[it[1]]++;
            isConnected[it[0]][it[1]] = true;
            isConnected[it[1]][it[0]] = true;
        }
        int ans = -1e9;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int total = degree[i] + degree[j];
                if(isConnected[i][j]){
                    total--;
                }
                ans = max(ans, total);
            }
        }
        return ans;
    }
};