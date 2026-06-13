class Solution {
public:
    string mapWordWeights(vector<string>& w, vector<int>& we) {
        string ans="";
        for(int i=0;i<w.size();i++){
            int x=0;
            for(int j=0;j<w[i].size();j++){
                x+=we[w[i][j]-'a'];
            }
            x=x%26;
            ans+=char('a'+25-x);
        }
        return ans;
    }
};