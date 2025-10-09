class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();
        vector<long long> ans(n+1,0);
        for(int i=0;i<n;i++){
            ans[i+1]=ans[i]+skill[i]*mana[0];
        }
        for(int i=1;i<m;i++){
            vector<long long> a(n+1,0);
            long long y=0,z=0;
            for(int j=0;j<n;j++){
                int x=skill[j]*mana[i];
                a[j+1]=a[j]+x;
                y=max(y,ans[j+1]-z);
                z+=x;
            }
            for(int j=0;j<=n;j++){
                a[j]+=y;
            }
            swap(ans,a);
        }
        return ans[n];
    }
};