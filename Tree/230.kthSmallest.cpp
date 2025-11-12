// TC: O(N) SC: O(N)
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& inorderTraversal){
        if(!root) return;
        inorder(root->left, inorderTraversal);
        inorderTraversal.push_back(root->val);
        inorder(root->right, inorderTraversal);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorderTraversal;
        inorder(root, inorderTraversal);
        return inorderTraversal[k-1];
    }
};

// TC: O(H + k) SC: O(1)
class Solution {
public:
    void solve(TreeNode* root, int k, int& cnt, int& ans){
        if(root == NULL){
            return;
        }
        solve(root -> left, k, cnt, ans);
        cnt++;
        if(cnt == k){
            ans = root -> val;
            return;
        }
        solve(root -> right, k, cnt, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, ans = 0;
        solve(root, k, cnt, ans);
        return ans;
    }
};