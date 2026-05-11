class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            vector<int> a;
            while(x){
                int y=x%10;
                a.push_back(y);
                x/=10;
            }
            for(int j=a.size()-1;j>=0;j--){
                ans.push_back(a[j]);
            }
        }
        return ans;
    }
};