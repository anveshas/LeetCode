/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> map;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            map[r][c].insert(node->val);
            if(node -> left){
                q.push({node -> left, {r-1, c+1}});
            }
            if(node -> right){
                q.push({node -> right, {r+1, c+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p: map){
            vector<int> col;
            for(auto q: p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};