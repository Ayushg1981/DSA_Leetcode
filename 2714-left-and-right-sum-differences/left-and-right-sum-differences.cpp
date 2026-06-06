class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> v1(n,0);
        int a=0;
        for(int i=1;i<n;i++){
            a+=nums[i-1];
            v1[i]=a;
        }
        a=0;
        for(int i=n-2;i>=0;i--){
            a+=nums[i+1];
            v1[i]=abs(v1[i]-a);
        }
        return v1;
    }
};