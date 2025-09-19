class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        if(source == target)
            return 0;
        unordered_map<int, vector<int>> adj;

        for(int route=0; route<n; route++){
            for(auto stop: routes[route]){
                adj[stop].push_back(route);
            }
        }

        vector<bool> vis(501, false);
        queue<int> queue;
        for(auto route: adj[source]){
            queue.push(route);
        }

        int busCount = 1;
        while(!queue.empty()){
            int size = queue.size();
            while(size--){
                int route = queue.front();
                queue.pop();
                for(auto stop: routes[route]){
                    if(stop == target) return busCount;

                    for(auto nextRoute: adj[stop]){
                        if(!vis[nextRoute]){
                            vis[nextRoute] = true;
                            queue.push(nextRoute);
                        }
                    }
                }
                
            }
            busCount++;
        }
        return -1;
    }
};