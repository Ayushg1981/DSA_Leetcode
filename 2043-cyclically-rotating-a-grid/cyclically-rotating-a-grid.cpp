class Solution {
public:
    pair<int,int> f(int x,int y,int k,int n,int m,int d,int a,int b){
        int i=2*(n-a)+2*(m-b)-4;
        k=k%i;
        while(k){
            if(d==1){
                if(k>(n-1-x)){
                    k-=n-1-x;
                    x=n-1;
                }
                else{
                    x=x+k;
                    break;
                }
                d++;
            }
            else if(d==2){
                if(k>(m-1-y)){
                    k-=m-1-y;
                    y=m-1;
                }
                else{
                    y=y+k;
                    break;
                }
                d++;
            }
            else if(d==3){
                if(k>(x-a)){
                    k-=x-a;
                    x=a;
                }
                else{
                    x=x-k;
                    break;
                }
                d++;
            }
            else if(d==4){
                if(k>(y-b)){
                    k-=y-b;
                    y=b;
                }
                else{
                    y=y-k;
                    break;
                }
                d=1;
            }
        }
        return {x,y};
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        int x=n,y=0,a=m,b=0;
        for(int i=min(n,m);i>0;i-=2){
            for(int j=a-1;j>b;j--){
                auto l=f(y,j,k,x,a,4,y,b);
                ans[l.first][l.second]=grid[y][j];
            }
            for(int j=y;j<x-1;j++){
                auto l=f(j,b,k,x,a,1,y,b);
                ans[l.first][l.second]=grid[j][b];
            }
            for(int j=b;j<a-1;j++){
                auto l=f(x-1,j,k,x,a,2,y,b);
                ans[l.first][l.second]=grid[x-1][j];
            }
            for(int j=x-1;j>y;j--){
                auto l=f(j,a-1,k,x,a,3,y,b);
                ans[l.first][l.second]=grid[j][a-1];
            }
            x--;
            y++;
            a--;
            b++;
        }
        return ans;
    }
};