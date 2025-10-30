class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=0,x=0;
        for(int i=0;i<target.size();i++){
            if(target[i]>x) ans+=target[i]-x;
            x=target[i];
        }
        return ans;
    }
};