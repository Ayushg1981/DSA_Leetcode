class Solution {
public:
    bool dfs(vector<vector<int>>& g,vector<int>& v,int a,int& d){
        v[a]=1;
        for(auto x:g[a]){
            if(x==d) return true;
            if(v[x]==0){
                if(dfs(g,v,x,d)) return 1;;
            }
        }
        return false;
    }
    bool validPath(int V, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;
        vector<vector<int>> g(V,vector<int> ());
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> v(V,0);
        return dfs(g,v,source,destination);
    }
};