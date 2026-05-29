class Solution {
public:
    int minElement(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            string a=to_string(nums[i]);
            int sum=0;
            for(int j=0;j<a.size();j++){
                sum+=(a[j]-'0');
            }
            nums[i]=sum;
        }
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            ans=min(ans,nums[i]);
        }
        return ans;
    }
};