class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        vector<int> xmax(n+1,INT_MIN),xmin(n+1,INT_MAX),ymax(n+1,INT_MIN),ymin(n+1,INT_MAX);
        for(int i=0;i<b.size();i++){
            xmax[b[i][0]]=max(xmax[b[i][0]],b[i][1]);
            xmin[b[i][0]]=min(xmin[b[i][0]],b[i][1]);
            ymax[b[i][1]]=max(ymax[b[i][1]],b[i][0]);
            ymin[b[i][1]]=min(ymin[b[i][1]],b[i][0]);
        }
        int ans=0;
        for(int i=0;i<b.size();i++){
            if(b[i][1]<xmax[b[i][0]] && b[i][1]>xmin[b[i][0]] && b[i][0]<ymax[b[i][1]] && b[i][0]>ymin[b[i][1]]) ans++;
        }
        return ans;
    }
};