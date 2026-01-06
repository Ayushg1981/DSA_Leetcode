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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> a;
        while(!q.empty()){
            int sum=0;
            int k=q.size();
            for(int i=0;i<k;i++){
                TreeNode* x=q.front();
                sum+=x->val;
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
                q.pop();
            }
            a.push_back(sum);
        }
        int ans=0;
        for(int i=1;i<a.size();i++){
            if(a[ans]<a[i]) ans=i;
        }
        return ans+1;
    }
};