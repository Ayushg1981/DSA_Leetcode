class Solution {
public:
    int ans=INT_MAX;
    void f(vector<int>& v,int start,vector<int>&a,int k){
        if(start==v.size()){
            int an=INT_MIN;
            for(int i=0;i<k;i++){
                an=max(an,a[i]);
            }
            ans=min(ans,an);
            return;
        }
        for(int i=0;i<k;i++){
            a[i]+=v[start];
            f(v,start+1,a,k);
            a[i]-=v[start];
        }
        
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> a(k,0);
        f(cookies,0,a,k);
        return ans;
    }
};