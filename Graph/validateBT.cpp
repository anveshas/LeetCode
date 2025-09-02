class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n, 0);
        for(int i = 0; i < n; i++){
            int l = leftChild[i];
            int r = rightChild[i];
            if(l != -1) {
                parent[l]++;
                if(parent[l] > 1) {
                    return false;
                }
            }
            if(r != -1) { 
                parent[r]++;
                if(parent[r] > 1) {
                    return false;
                }
            }
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (parent[i] == 0) {
                if (root == -1) root = i;
                else return false;
            }
        }
        if (root == -1) return false;

        vector<bool> visited(n, false);
        
        
        int visitedCount = 0;
        queue<int> q;
        q.push(root);
        visited[root] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visitedCount++;
            
            if (leftChild[node] != -1 && !visited[leftChild[node]]) {
                visited[leftChild[node]] = true;
                q.push(leftChild[node]);
            }
            if (rightChild[node] != -1 && !visited[rightChild[node]]) {
                visited[rightChild[node]] = true;
                q.push(rightChild[node]);
            }
        }
        return visitedCount == n;
    }
};