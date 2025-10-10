class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int> ans(k,0);
        vector<int> an(k,INT_MIN);
        for(int i=n-1;i>=0;i--){
           ans[i%k]+=energy[i];
           an[i%k]=max(an[i%k],ans[i%k]);
        }
        int a=an[0];
        for(int i=1;i<k;i++){
            a=max(a,an[i]);
        }
        return a;
    }
};