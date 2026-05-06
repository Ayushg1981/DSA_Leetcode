class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();
        vector<vector<char>> ans(n,vector<char> (m));
        for(int i=0;i<m;i++){
            int k=n-1;
            for(int j=n-1;j>=0;j--){
                if(box[i][j]=='#'){
                    ans[k][m-i-1]='#';
                    k--;
                }
                else if(box[i][j]=='*'){
                    while(k>j){
                        ans[k][m-i-1]='.';
                        k--;
                    }
                    ans[k][m-i-1]='*';
                    k--;
                }
            }
            while(k>=0){
                ans[k][m-i-1]='.';
                k--;
            }
        }
        return ans;
    }
};