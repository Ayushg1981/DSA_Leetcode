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
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        component=n;
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
        priority_queue<vector<int>> pq;

        int x=INT_MAX;
        for(int i=0;i<edges.size();i++){
            if(edges[i][3]==1){
                x=min(x,edges[i][2]);
                int pu=find(edges[i][0]);
                int pv=find(edges[i][1]);
                if(pu==pv) return -1;
                union_(edges[i][0],edges[i][1]);
            }
            else{
                pq.push({edges[i][2],edges[i][0],edges[i][1]});
            }
        }

        while(pq.size()>0){
            auto a=pq.top();pq.pop();

            int pu=find(a[1]);
            int pv=find(a[2]);
            if(pu==pv) continue;
            union_(a[1],a[2]);

            if(a[0]<x){
                int y=a[0]*2;
                if(k>component-1){
                    x=min(x,y);
                    k--;
                }
                else x=min(x,y/2);
            }
        }
        if(component!=1) return -1;
        return x;
    }
};