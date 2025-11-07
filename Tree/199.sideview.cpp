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
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        queue<pair<TreeNode*, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        while(!q.empty()){
            int line = q.front().second;
            TreeNode* node = q.front().first;
            q.pop();
            
            mp[line] = node -> val;
            if(node -> left){
                q.push({node -> left, line + 1});
            }
            if(node -> right){
                q.push({node -> right, line + 1});
            }
        }
        vector<int> ans;
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};