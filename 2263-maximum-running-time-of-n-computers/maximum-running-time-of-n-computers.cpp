class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long i=1,j=0;
        for(int k=0;k<batteries.size();k++){
            j+=batteries[k];
        }
        j/=n;
        long long ans=0;
        while(i<=j){
            long long mid=i+(j-i)/2;
            long long x=0;
            for(int k=0;k<batteries.size();k++){
                x+=min((long long)batteries[k],mid);
            }
            if(x>=mid*n){
                ans=mid;
                i=mid+1;
            }
            else j=mid-1;
        }
        return ans;
    }
};