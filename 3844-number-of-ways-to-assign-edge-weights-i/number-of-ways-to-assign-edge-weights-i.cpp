class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> v(n+2);
        for(int i=0;i<edges.size();i++){
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n+2,false);
        int x=0;
        queue<int> q;
        q.push(1);
        vis[1]=true;
        while(q.size()>0){
            int k=q.size();
            x++;
            for(int i=0;i<k;i++){
                int a=q.front();
                q.pop();
                for(auto b:v[a]){
                    if(!vis[b]){
                        q.push(b);
                        vis[b]=true;
                    }
                }
            }
        }
        int ans=1;
        for(int i=0;i<x-2;i++){
            ans*=2;
            ans=ans%1000000007;
        }
        return ans;
    }
};