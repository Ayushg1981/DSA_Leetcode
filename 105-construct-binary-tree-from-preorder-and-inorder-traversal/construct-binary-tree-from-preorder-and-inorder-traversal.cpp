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
    TreeNode* f(vector<int>& pre, vector<int>& in,int a,int b,int c,int d){
        if(b<a || d<c) return NULL;
        TreeNode* temp=new TreeNode(pre[a]);
        if(b==a) return temp;
        int i=c,x=0;
        while(in[i]!=pre[a]){
            x++;
            i++;
        }
        temp->left=f(pre,in,a+1,a+x,c,i-1);
        temp->right=f(pre,in,a+x+1,b,i+1,d);
        return temp;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return f(pre,in,0,pre.size()-1,0,in.size()-1);
    }
};