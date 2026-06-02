class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<bool> v1(n,false),v2(m,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    v1[i]=true;
                    v2[j]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(v1[i]){
                for(int j=0;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=0;i<m;i++){
            if(v2[i]){
                for(int j=0;j<n;j++){
                    matrix[j][i]=0;
                }
            }
        }
    }
};