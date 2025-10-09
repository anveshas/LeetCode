class Solution {
public:
    int n;
    bool isBound(int i, int j, vector<vector<int>>& grid){
        if(i < n && j < n && i >= 0 && j >= 0){
            return true;
        }
        return false;
    }

    bool isPossible(vector<vector<int>>& grid, int i, int j, int time, vector<vector<bool>>& vis){
        if(!isBound(i, j, grid) || vis[i][j] || grid[i][j] > time){
            return false;
        }
        if(i == n-1 && j == n-1){
            return true;
        }
        vis[i][j] = true;
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        for(int k = 0; k < 4; k++){
            int i_ = i + dx[k];
            int j_ = j + dy[k];

            if(isPossible(grid, i_, j_, time, vis)){
                return true;
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int l = grid[0][0], r = n*n - 1;
        int result = 0;
        while(l <= r){
            int mid = l + (r - l)/2;
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            if(isPossible(grid, 0, 0, mid, vis)){
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return result;
    }
};