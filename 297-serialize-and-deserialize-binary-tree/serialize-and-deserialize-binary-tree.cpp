/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string s="";
        func(root,s);

        return s;
        
    }
    void func(TreeNode* root,string& s)
        {
            if(root==NULL)
            { s.append("#,");
             return;
            }
            s.append(to_string(root->val)+",");
            func(root->left,s);
            func(root->right,s);
        }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        vector<string>v;
        string s="";
        for(char c :data)
        {
            if(c==',')
            {
                v.push_back(s);
                s.clear();
                
            }
            else s+=c;
        }
        int i=0;
    TreeNode* w=func(v,i);
    return w;
    }
    TreeNode*func(vector<string>&data,int &i)
    {
        
        if(i>=data.size()||data[i]=="#")
        {
            i++;
            return  NULL;
        }
        
        TreeNode* n=new TreeNode(stoi(data[i++]));
        n->left=func(data,i);
        n->right=func(data,i);
        return n;

    }
      
   
};
