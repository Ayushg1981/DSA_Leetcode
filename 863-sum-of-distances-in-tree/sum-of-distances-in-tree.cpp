class Solution {
public:
    vector<int> size,ans;
    int n;
    int dfs(vector<vector<int>>& adj,int x){
        int sum=0;
        for(auto a:adj[x]){
            sum+=dfs(adj,a)+1;
        }
        return size[x]=sum;
    }
    void d(vector<vector<int>>& adj,int x){
        for(auto a:adj[x]){
            ans[a]=ans[x]-size[a]-1+n-size[a]-1;
            d(adj,a);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n=n;
        size.resize(n,0);
        ans.resize(n);
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<int>> v(n);
        queue<int> qu;
        vector<int> vis(n,0);
        vis[0]=1;
        qu.push(0);
        while(qu.size()>0){
            int x=qu.front();
            qu.pop();
            for(auto a:adj[x]){
                if(vis[a]==1) continue;
                vis[a]=1;
                v[x].push_back(a);
                qu.push(a);
            }
        }
        int a=dfs(v,0);
        int x=0;
        for(int i=0;i<n;i++){
            x+=size[i];
        }
        ans[0]=x;
        d(v,0);
        return ans;
    }
};