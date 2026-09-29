class Solution {
public:
    string f(string s){
        unordered_set<char> st;
        for(int i=0;i<s.size();i++){
            st.insert(s[i]);
        }
        string a="";
        string ans="";
        bool flag=true;
        for(int i=0;i<s.size();i++){
            char y;
            if(s[i]>='a' && s[i]<='z') y=char(s[i]-'a'+'A');
            else y=char(s[i]-'A'+'a');

            if(st.find(y)==st.end()){
                string b="";
                for(int j=i+1;j<s.size();j++){
                    b+=s[j];
                }
                string c=f(a);
                string d=f(b);
                if(c.size()>=d.size()) ans=c;
                else ans=d;

                flag=false;
                break;
            }
            else a+=s[i];
        }
        if(flag) ans=s; 
        return ans;
    }
    string longestNiceSubstring(string s) {
        return f(s);
    }
};