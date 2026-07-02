class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();

        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};

        vector<vector<bool>> vis(n,vector<bool>(m,0));
        priority_queue<tuple<int,int,int>> q;

        if(grid[0][0]==1) health--;
        if(health==0) return false;

        q.push({health,0,0});
        vis[0][0]=1;

        while(q.size()>0){
            auto [h,i,j]=q.top();
            q.pop();
            if(i==n-1 && j==m-1) return true;
            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                int nh=h;
                if(ni<0 || nj<0 || ni>=n || nj>=m || vis[ni][nj]) continue;
                if(grid[ni][nj]==1) nh--;
                vis[ni][nj]=true;
                if(nh==0) continue;
                q.push({nh,ni,nj});
            }
        }
        return false;
    }
};