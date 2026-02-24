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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        s.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
        for(int i=0;i<n;i++){
            int pa=find(edges[i][0]);
            int pb=find(edges[i][1]);
            if(pa==pb) return {edges[i][0],edges[i][1]};
            union_(edges[i][0],edges[i][1]);
        }
        return {};
    }
};