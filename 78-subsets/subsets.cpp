class Solution {
public:
    void helper(vector<vector<int>>& a,vector<int>& n,int idx,vector<int>& nums){
        if(nums.size()==idx){
            a.push_back(n);
            return;
        }
        n.push_back(nums[idx]);
        helper(a,n,idx+1,nums);
        n.pop_back();
        helper(a,n,idx+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> n;
        vector <int> m;
        helper(n,m,0,nums);
        return n;
    }
};