class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        vector<int> pre(n+1,0);
        pre[1]=card[0];
        for(int i=1;i<n;i++){
            pre[i+1]=pre[i]+card[i];
        }
        int ans=0;
        for(int i=0;i<=k;i++){
            ans=max(ans,pre[i]+pre[n]-pre[n-k+i]);
        }
        return ans;
    }
};