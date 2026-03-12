class Solution {
public:
    map<int,map<int,multiset<int>>> mp;
    void f(int i,int j,TreeNode* root){
        if(root==NULL) return;
        mp[i][j].insert(root->val);
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
                    a.push_back(z);
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};