class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int time = top[0], i = top[1], j = top[2];
            if (i == n - 1 && j == n - 1)
                return time;
            if (vis[i][j])
                continue;
            vis[i][j] = true;

            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && nj >= 0 && ni < n && nj < n && !vis[ni][nj]) {
                    int newTime = max(time, grid[ni][nj]);
                    if (newTime < dist[ni][nj]) {
                        dist[ni][nj] = newTime;
                        pq.push({newTime, ni, nj});
                    }
                }
            }
        }
        return -1;
    }
};