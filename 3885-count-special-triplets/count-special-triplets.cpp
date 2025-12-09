class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int> m1,m2;
        for(int i=2;i<nums.size();i++){
            m2[nums[i]]++;
        }
        m1[nums[0]]++;
        long long ans=0;
        for(int i=1;i<nums.size()-1;i++){
            int x=nums[i]*2;
            ans+=((long long)m1[x]*(long long)m2[x])%1000000007;
            ans=ans%1000000007;
            m1[nums[i]]++;
            if(m2[nums[i+1]]==1){
                m2.erase(nums[i+1]);
            }
            else m2[nums[i+1]]--;
        }
        return ans;
    }
};