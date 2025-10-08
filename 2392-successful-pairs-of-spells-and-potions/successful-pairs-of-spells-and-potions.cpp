class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size();
        int m=potions.size();
        vector<int> an(n);
        for(int i=0;i<n;i++){
            int l=0,h=m-1;
            int ans=m;
            while(l<=h){
                int mid=l+(h-l)/2;
                long long x=(long long)potions[mid]*spells[i];
                if(x>=success){
                    ans=mid;
                    h=mid-1;
                }
                else l=mid+1;
            }
            an[i]=m-ans;
        }
        return an;
    }
};