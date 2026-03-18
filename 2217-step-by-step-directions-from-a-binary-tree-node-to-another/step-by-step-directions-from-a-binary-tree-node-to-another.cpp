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
    TreeNode* lowestCommonAncestor(TreeNode* root,int p,int q) {
        if (root == NULL || root->val == p || root->val == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL){
            return root;
        }
        return left != NULL ? left : right;
    }
    void f(TreeNode* root,string& s,int& d,string& ans){
        if(root==NULL) return;
        if(root->val==d){
            ans+=s;
            return;
        }
        s+='L';
        f(root->left,s,d,ans);
        s.pop_back();
        s+='R';
        f(root->right,s,d,ans);
        s.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca=lowestCommonAncestor(root,startValue,destValue);
        string ans="";
        string s="";
        f(lca,s,startValue,ans);
        for(int i=0;i<ans.size();i++){
            ans[i]='U';
        }
        f(lca,s,destValue,ans);
        return ans;
    }
};