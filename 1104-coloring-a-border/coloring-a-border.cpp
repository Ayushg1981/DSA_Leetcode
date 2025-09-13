class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n) return false;
        return true;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>> q;
        int co=color;
        q.push({sr,sc});
        swap(image[sr][sc],color);
        unordered_set<int> s;
        s.insert(sr*1000+sc);
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            int x=0;
            image[i][j]=co;
            q.pop();
            if(isValid(i+1,j,m,n) && (image[i+1][j]==color || s.find((i+1)*1000+j)!=s.end())) x++;
            if(isValid(i,j+1,m,n) && (image[i][j+1]==color || s.find((i)*1000+j+1)!=s.end())) x++;
            if(isValid(i-1,j,m,n) && (image[i-1][j]==color || s.find((i-1)*1000+j)!=s.end())) x++;
            if(isValid(i,j-1,m,n) && (image[i][j-1]==color || s.find((i)*1000+j-1)!=s.end())) x++;
            if(isValid(i+1,j,m,n) && image[i+1][j]==color && s.find((i+1)*1000+j)==s.end()){
                s.insert((i+1)*1000+j);
                q.push({i+1,j});
            }
            if(isValid(i,j+1,m,n) && image[i][j+1]==color && s.find((i)*1000+j+1)==s.end()){
                s.insert((i)*1000+j+1);
                q.push({i,j+1});
            }
            if(isValid(i-1,j,m,n) && image[i-1][j]==color && s.find((i-1)*1000+j)==s.end()){
                s.insert((i-1)*1000+j);
                q.push({i-1,j});
            }
            if(isValid(i,j-1,m,n) && image[i][j-1]==color && s.find((i)*1000+j-1)==s.end()){
                s.insert((i)*1000+j-1);
                q.push({i,j-1});
            }
            if(x==4) image[i][j]=color;
        }
        return image;
    }
};