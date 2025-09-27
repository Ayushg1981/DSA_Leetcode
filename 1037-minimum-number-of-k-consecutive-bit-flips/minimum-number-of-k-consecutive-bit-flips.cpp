class Solution {
public:
    int minKBitFlips(vector<int>& arr, int k) {
        vector<int> v(arr.size()+k,0);
        int x=0,ans=0;
        for(int i=0;i<arr.size();i++){
            x+=v[i];
            if(x%2==0 && arr[i]==0 || x%2==1 && arr[i]==1){
                ans++;
                x++;
                if(i+k>arr.size()) return -1;
                v[i+k]--;
            }
        }
        return ans;
    }
};