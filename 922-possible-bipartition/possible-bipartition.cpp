class Solution {
public:
    bool dfs(vector<vector<int>>& adj,vector<int>& grp,int i,int g){
        grp[i]=g;
        for(auto v:adj[i]){
            if(grp[v]==-1){
                if(!dfs(adj,grp,v,1-g)) return false;
            }
            else if(grp[i]==grp[v]) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1,vector<int>());
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> grp(n+1,-1);
        for(int i=1;i<=n;i++){
            if(grp[i]==-1){
                if(!dfs(adj,grp,i,0)) return false;
            }
        }
        return true;
    }
};