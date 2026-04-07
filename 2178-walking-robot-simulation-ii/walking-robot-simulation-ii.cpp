class Robot {
public:
    vector<vector<int>> grid;
    vector<int> pos;
    int n,m,par,dir;
    vector<string> s={"East","North","West","South"};
    Robot(int width, int height) {
        n=height;
        m=width;
        grid.resize(n,vector<int>(m,0));
        pos={0,0};
        dir=0;
        par=2*(n+m)-4;
    }
    
    void step(int num) {
        int x=pos[0];
        int y=pos[1];
        num=num%par;
        if (num == 0) {
            if (x == 0 && y == 0) dir = 3; 
            else if (x == m - 1 && y == 0) dir = 0;
            else if (x == m - 1 && y == n - 1) dir = 1;
            else if (x == 0 && y == n - 1) dir = 2;
        
        }
        else{
            while(num>0){
                if(dir==0){
                    int step=min(num,m-1-x);
                    x+=step;
                    num-=step;
                }
                else if(dir==1){
                    int step=min(num,n-1-y);
                    y+=step;
                    num-=step;
                }
                else if(dir==2){
                    int step=min(num,x);
                    x-=step;
                    num-=step;
                }
                else{
                    int step=min(num,y);
                    y-=step;
                    num-=step;
                }
                if(num>0) dir++;
                dir=dir%4;
            }
        }
        pos={x,y};
    }
    
    vector<int> getPos() {
        return pos;
    }
    
    string getDir() {
        return s[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */