class Solution {
public:
    vector<int> parent,s;
    int find(int u){
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u]);
    }
    void union_(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv) return;
        if(s[pu]>=s[pv]){
            parent[pv]=pu;
            s[pu]+=s[pv];
        }
        else{
            parent[pu]=pv;
            s[pv]+=s[pu];
        }
    }
    bool equationsPossible(vector<string>& equations) {
        s.resize(26,1);
        parent.resize(26);
        for(int i=0;i<26;i++) parent[i]=i;

        for(int i=0;i<equations.size();i++){
            int a=equations[i][0]-'a';
            int b=equations[i][3]-'a';
            char c=equations[i][1];
            if(c=='=') union_(a,b);
        }
        for(int i=0;i<equations.size();i++){
            int a=equations[i][0]-'a';
            int b=equations[i][3]-'a';
            char c=equations[i][1];
            int pa=find(a);
            int pb=find(b);
            if(c=='!' && pa==pb) return false;
        }
        return true;
    }
};