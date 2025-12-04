class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> mp;
        long long x=0,ans=0;
        for(int i=0;i<points.size();i++){
            mp[points[i][1]]++;
        }
        for(auto c:mp){
            long long i=c.second;
            ans=(ans+x*(i*(i-1))/2)%1000000007;
            x+=(i*(i-1))/2;
        }
        return ans;
    }
};