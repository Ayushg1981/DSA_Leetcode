class Solution {
public:
    bool threeFibonacciSum(int n) {
        if(n==1) return false;
        vector<int> v(100000);
        v[0]=0;
        v[1]=1;
        v[2]=1;
        for(int i=3;i<100000;i++){
            int x=v[i-1]+v[i-2]+v[i-3];
            if(n==x) return true;
            if(n<x) return false;
            v[i]=v[i-1]+v[i-2];
        }
        return false;
    }
};