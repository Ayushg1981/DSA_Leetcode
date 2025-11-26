class Solution {
public:
    void f(set<vector<int>>& st,vector<int>& nums,vector<int>& a,int i){
        if(i==nums.size()){
            if(a.size()>1) st.insert(a);
            return;
        }
        int n=a.size();
        f(st,nums,a,i+1);
        if(n==0 || a[n-1]<=nums[i]){
            a.push_back(nums[i]);
            f(st,nums,a,i+1);
            a.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> a;
        f(st,nums,a,0);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};