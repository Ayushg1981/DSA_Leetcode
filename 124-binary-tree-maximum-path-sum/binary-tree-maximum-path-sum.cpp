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
    int helper(TreeNode* root, int &ans){
        if(!root)return 0;
        int l = helper(root->left, ans);
        int r = helper(root->right, ans);
        int val = root->val + max(l, 0) + max(r, 0);
        ans = max(ans, val);
        return root->val + max({l, r, 0});
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};