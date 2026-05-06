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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=1;
        queue<pair<TreeNode*,long long>> q;
        if(root) q.push({root,1});
        while(!q.empty()){
            int k=q.size();
            long long l,r;
            for(int i=0;i<k;i++){
                auto a=q.front();
                q.pop();
                TreeNode* n=a.first;
                long long x=a.second%(100*(long long)(INT_MAX));
                if(i==0) l=x;
                if(i==k-1) r=x;
                if(n->left) q.push({n->left,2*x-1});
                if(n->right) q.push({n->right,2*x});
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};