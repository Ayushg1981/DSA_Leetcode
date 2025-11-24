class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<vector<int>> v (5,vector<int> (2));
        v[0][0]=0;
        v[0][1]=1;
        v[1][0]=2;
        v[1][1]=3;
        v[2][0]=4;
        v[2][1]=0;
        v[3][0]=1;
        v[3][1]=2;
        v[4][0]=3;
        v[4][1]=4;
        int n=nums.size();
        vector<bool> ans(n);
        int x=nums[0];
        if(x==0) ans[0]=true;
        else ans[0]=false;
        for(int i=1;i<n;i++){
            x=v[x][nums[i]];
            if(x==0) ans[i]=true;
            else ans[i]=false;
        }
        return ans;
    }
};