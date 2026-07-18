class Solution {
public:
    int gcd(int a,int b){
        if (a == 0) return b;
        if (b == 0) return a;
        if (a == b) return a;
        if (a > b) return gcd(a - b, b);
        return gcd(a, b - a);
    }
    int findGCD(vector<int>& nums) {
        int a=nums[0],b=nums[0];
        for(int i=1;i<nums.size();i++){
            if(a>nums[i]) a=nums[i];
            if(b<nums[i]) b=nums[i];
        }
        return gcd(a,b);
    }
};