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
    int f(TreeNode* root,int sum){
        if(root->left==NULL && root->right==NULL) return sum*2+root->val;
        if(root->left && root->right) return f(root->left,sum*2+root->val)+f(root->right,sum*2+root->val);
        if(root->left) return f(root->left,sum*2+root->val);
        return f(root->right,sum*2+root->val);
    }
    int sumRootToLeaf(TreeNode* root) {
        return f(root,0);
    }
};