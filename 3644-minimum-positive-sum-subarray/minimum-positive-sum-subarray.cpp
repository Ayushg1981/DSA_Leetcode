class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        vector<int> pre(nums.size(),0);
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]=nums[i]+pre[i-1];
        }
        int ans=INT_MAX;
        for(int i=l-1;i<nums.size();i++){
            int x=r-l+1;
            int y=i;
            int z=l;
            while(x>0){
                if(y-z>=-1){
                    if(y-z==-1){
                        int a=pre[i];
                        if(a>0) ans=min(ans,a);
                    }
                    else{
                        int a=pre[i]-pre[i-z];
                        if(a>0) ans=min(ans,a);
                    }
                    z++;
                }
                x--;
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};