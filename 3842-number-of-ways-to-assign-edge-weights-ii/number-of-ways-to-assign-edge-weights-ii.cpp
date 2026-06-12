class Solution {
public:
    vector<vector<int>> par;
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size();
        par.resize(n+2,vector<int>(20,-1));
        vector<vector<int>> v(n+2);
        for(int i=0;i<edges.size();i++){
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n+2,false);
        vector<int> h(n+2,0);
        queue<int> q;
        q.push(1);
        vis[1]=true;
        par[1][0]=-1;
        h[1]=0;
        while(q.size()>0){
            int a=q.front();
            q.pop();
            for(auto b:v[a]){
                if(!vis[b]){
                    q.push(b);
                    vis[b]=true;
                    par[b][0]=a;
                    h[b]=h[a]+1;
                }
            }
        }

        for(int i=1;i<20;i++){
            for(int j=1;j<=n+1;j++){
                int x=par[j][i-1];
                if(x==-1) continue;
                par[j][i]=par[x][i-1];
            }
        }
        vector<int> ans(n+2);
        ans[0]=0;
        int x=1;
        for(int i=1;i<n+2;i++){
            ans[i]=x;
            x=x*2%1000000007;
        }
        vector<int> answer(queries.size());
        for(int i=0;i<queries.size();i++){
            int dis=0;
            int a=queries[i][0],b=queries[i][1];
            int ha=h[a],hb=h[b];

            if(ha<hb){
                dis+=hb-ha;
                b=getkth(dis,b);
            }
            else{
                dis+=ha-hb;
                a=getkth(dis,a);
            }
            ha=min(ha,hb);
            for(int i=19;i>=0;i--){
                if(par[a][i]==par[b][i]) continue;
                a=par[a][i];
                b=par[b][i];
                dis += 2 * (1 << i);
            }
            if(a!=b) dis+=2;
            answer[i]=ans[dis];
        }
        return answer;
    }

    int getkth(int k,int a){
        for(int i=0;i<20;i++){
            if(k&1){
                a=par[a][i];
            }
            if(a==-1) return -1;
            k=k>>1;
        }
        return a;
    }
};