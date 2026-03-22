class Solution {
public:
    bool isSame(vector<vector<int>>& m,vector<vector<int>>& t){
        int n=m.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(m[i][j]!=t[i][j]) return false;
            }
        }
        return true;
    }
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            int j=0,k=n-1;
            while(j<k){
                swap(matrix[i][j],matrix[i][k]);
                j++;
                k--;
            }
        }
        return;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        bool ans=isSame(mat,target);
        rotate(mat);
        ans|=isSame(mat,target);
        rotate(mat);
        ans|=isSame(mat,target);
        rotate(mat);
        ans|=isSame(mat,target);
        return ans;
    }
};