class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> mp(value,0);
        for(int i=0;i<nums.size();i++){
            mp[(nums[i]%value+value)%value]++;
        }
        int m=INT_MAX;
        int a=0;
        for(int i=0;i<value;i++){
            if(m>mp[i]){
                m=mp[i];
                a=i;
            }
        }
        return m*value+a;
    }
};