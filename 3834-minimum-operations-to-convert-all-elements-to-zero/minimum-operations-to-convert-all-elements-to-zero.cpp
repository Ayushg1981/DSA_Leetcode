class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> s1,s2;
        int n=nums.size();
        vector<long long> a(n),b(n);
        for(int i=n-1; i>=0; i--){
            while(!s1.empty() && nums[s1.top()]>=nums[i]) s1.pop();
            if(s1.empty() || nums[s1.top()]>nums[i]) a[i]= n;
            else a[i]= s1.top();
            s1.push(i);
        }
        bool flag=false;
        for(int i=0; i<n; i++){
            if(nums[i]==0) flag=true;
            while(!s2.empty() && nums[s2.top()]>=nums[i]) s2.pop();
            if(s2.empty() || nums[s2.top()]>nums[i]) b[i]= -1;
            else b[i]= s2.top();
            s2.push(i);
        }
        unordered_set<long long> s;
        for(int i=0;i<n;i++){
            s.insert(a[i]*1000000+b[i]);
        }
        if(flag) return s.size()-1;
        return s.size();
    }
};