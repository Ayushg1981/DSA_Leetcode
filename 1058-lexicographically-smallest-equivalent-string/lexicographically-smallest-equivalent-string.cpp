class Solution {
public:
    vector<int> parent;
    int find(int u){
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u]);
    }
    void union_(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv) return;
        if(pu<pv) parent[pv]=pu;
        else parent[pu]=pv;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        for(int i=0;i<26;i++) parent[i]=i;
        for(int i=0;i<s1.size();i++){
            union_(s1[i]-'a',s2[i]-'a');
        }
        string ans="";
        for(int i=0;i<baseStr.size();i++){
            ans+=char(find(baseStr[i]-'a')+'a');
        }
        return ans;
    }
};