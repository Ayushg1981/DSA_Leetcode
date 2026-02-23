class Solution {
public:
    vector<int> parent,size;
    int component;
    int find(int u){
        if(parent[u]==u) return u;
        return parent[u]=find(parent[u]);
    }
    void union_(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv) return;
        if(size[pu]>=size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        component--;
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int V=adj.size();
        parent.resize(V+1);
        size.resize(V+1,1);
        for(int i=0;i<=V;i++) parent[i]=i;
        component=V;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]){
                    union_(i,j);
                }
            }
        }
        return component;
    }
};