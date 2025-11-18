class Solution {
public:
    void f(vector<char>& s,int i,int j){
        if(i>j) return;
        swap(s[i],s[j]);
        f(s,i+1,j-1);
    }
    void reverseString(vector<char>& s) {
        int n=s.size();
        f(s,0,n-1);
    }
};