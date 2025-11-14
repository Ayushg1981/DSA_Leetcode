class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> v(n,vector<int>(n,0));
        int m=q.size();
        for(int i=0;i<m;i++){
            for(int j=q[i][0];j<=q[i][2];j++){
                v[j][q[i][1]]++;
                if(q[i][3]+1<n) v[j][q[i][3]+1]--;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                v[i][j]+=v[i][j-1];
            }
        }
        return v;
    }
};