class Solution {
public:
    pair<int,int> f(TreeNode* root){
        if(root==NULL) return {0,0};
        auto x=f(root->left);
        auto y=f(root->right);
        return {max(x.first,x.second)+max(y.first,y.second),root->val+x.first+y.first};
    }
    int rob(TreeNode* root) {
        auto ans=f(root);
        return max(ans.first,ans.second);
    }
};