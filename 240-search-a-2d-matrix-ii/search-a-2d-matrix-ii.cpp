class Solution {
public:
    bool f(vector<vector<int>>& matrix, int & target,int i,int j){
        if(i>=matrix.size()) return false;
        if(j<0) return false;
        if(matrix[i][j]==target) return true;
        if(matrix[i][j]>target) return f(matrix,target,i,j-1);
        else return f(matrix,target,i+1,j);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix[0].size();
        return f(matrix,target,0,n-1);
    }
};