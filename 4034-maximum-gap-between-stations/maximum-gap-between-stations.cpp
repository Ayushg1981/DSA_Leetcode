class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size();
        int m=station.size();
        if(n==1) return 0;

        char c=skill[0];
        vector<int> v(n,-1);
        int j=m-1;
        for(int i=n-1;i>0;i--){
            while(station[j]!=skill[i]) j--;
            v[i]=j;
            j--;
        }

        j=0;
        int ans=0;
        for(int i=1;i<n;i++){
            while(station[j]!=skill[i-1]) j++;
            ans=max(ans,v[i]-j);
            j++;
        }
        return ans;
    }
};