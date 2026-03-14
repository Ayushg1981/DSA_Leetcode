class Solution {
public:
    void helper(vector<string>& s,int n,int i,string a){
        if(n==i){
            s.push_back(a);
            return;
        }
        if(i==0){
            helper(s,n,i+1,a+'a');
            helper(s,n,i+1,a+'b');
            helper(s,n,i+1,a+'c');
        }
        else{
            if(a[i-1]!='a') helper(s,n,i+1,a+'a');
            if(a[i-1]!='b') helper(s,n,i+1,a+'b');
            if(a[i-1]!='c') helper(s,n,i+1,a+'c');
        }
    }
    string getHappyString(int n, int k) {
        vector<string> s;
        string a="";
        helper(s,n,0,a);
        if(k>s.size()) return "";
        return s[k-1];
    }
};