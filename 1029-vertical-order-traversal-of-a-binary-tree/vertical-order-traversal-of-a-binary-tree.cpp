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
    map<int,map<int,map<int,int>>> mp;
    void f(int i,int j,TreeNode* root){
        if(root==NULL) return;
        mp[i][j][root->val]++;
        f(i-1,j+1,root->left);
        f(i+1,j+1,root->right);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        f(0,0,root);
        vector<vector<int>> ans;
        for(auto x:mp){
            vector<int> a;
            for(auto y:x.second){
                for(auto z:y.second){
                    while(z.second--) a.push_back(z.first);
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};