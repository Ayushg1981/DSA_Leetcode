class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> mat(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            mat[i][0]=matrix[i][0]-'0';
            if(mat[i][0]==1)ans=1;
        }
        for(int i=0;i<n;i++)
        {
            mat[0][i]=matrix[0][i]-'0';
            if(mat[0][i]==1)ans=1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]-'0'==1)
                {
                    mat[i][j]=1+min(mat[i][j-1],min(mat[i-1][j],mat[i-1][j-1]));
                    ans=max(ans,mat[i][j]);
                }
            }
        }
        return ans*ans;
    }
};