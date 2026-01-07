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
    int  func(TreeNode* root){
        if(root==NULL)return 0;
        return root->val+=func(root->left)+func(root->right);
    }
    long long gunc(TreeNode* root,long long k){
        if(root==NULL)return 0;
        long long g=0;
        if(root->left) g=((long long)(k-root->left->val)*root->left->val);
        if(root->right) g=max(g,(long long)(k-root->right->val)*root->right->val);
        g=max(g,gunc(root->left,k));
        g=max(g,gunc(root->right,k));
        return g;
    }
    int maxProduct(TreeNode* root) {
        long long k= func(root);
        return gunc(root,k)%1000000007;
    }
};