class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> s;
        for(int i=0;i<nums.size();i++){
            s.push(nums[i]);
            while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            int x=__gcd(a,b);
            if(x==1){
                s.push(b);
                s.push(a);
                break;
            }
            else{
                s.push(((long long)(a)*(long long)(b))/x);
            }
            }
        }
        vector<int> ans(s.size());
        int i=s.size()-1;
        while(!s.empty()){
            ans[i]=s.top();
            s.pop();
            i--;
        }
        return ans;
    }
};