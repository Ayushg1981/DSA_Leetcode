class Solution {
public:
    int minOperations(vector<int>& arr) {
        int x=0,ans=0;
        for(int i=0;i<arr.size();i++){
            if(x%2==0 && arr[i]==0 || x%2==1 && arr[i]==1){
                ans++;
                x++;
            }
        }
        return ans;
    }
};