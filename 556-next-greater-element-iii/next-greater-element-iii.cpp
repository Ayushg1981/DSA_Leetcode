class Solution {
public:
    int nextGreaterElement(int m) {
        long long n=m;
        string s=to_string(n);
        int x=s.size();
        int i=x-1;
        for(i=x-1;i>0;i--){
            if(s[i-1]<s[i])break;
        }
        if(i==0) return -1;
        reverse(s.begin()+i,s.end());
        for(int j=i;j<x;j++){
            if(s[i-1]<s[j]){
                swap(s[i-1],s[j]);
                break;
            }
        }
        n=stoll(s);
        if(n>INT_MAX) return -1;
        return n;
    }
};