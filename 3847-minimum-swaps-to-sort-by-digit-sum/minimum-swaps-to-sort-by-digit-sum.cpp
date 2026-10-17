class Solution {
public:
    static int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
    static bool custom(int a, int b) {
    int sumA = digitSum(a);
    int sumB = digitSum(b);
    if (sumA == sumB) return a < b;
    return sumA < sumB;
}
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
            {ans.push_back(nums[i]);
            }
        
    
        sort(nums.begin(),nums.end(),custom);
        
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        m[nums[i]]=i;
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(m[ans[i]]!=i){
            count++;
            swap(ans[i],ans[m[ans[i]]]);
            i--;
        }
    }
    
    return count;
    }
};