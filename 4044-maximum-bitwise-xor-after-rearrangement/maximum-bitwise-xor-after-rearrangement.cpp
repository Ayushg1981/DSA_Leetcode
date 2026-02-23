class Solution {
public:
    string maximumXor(string s, string t) {
        int a=0,b=0;
        for(int i=0;i<t.size();i++){
            if(t[i]=='0') a++;
            else b++;
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(a && b){
                ans+='1';
                if(s[i]=='0') b--;
                else a--;
            }
            else{
                if(s[i]=='0' && b){
                    b--;
                    ans+='1';
                }
                else if(s[i]=='0'){
                    ans+='0';
                }
                else if(s[i]=='1' && a){
                    a--;
                    ans+='1';
                }
                else{
                    ans+='0';
                }
            }
        }
        return ans;
    }
};