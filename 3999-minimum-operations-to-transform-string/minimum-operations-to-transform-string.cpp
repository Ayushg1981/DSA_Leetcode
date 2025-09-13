class Solution {
public:
    int minOperations(string s) {
        int m=26;
        for(int i=0;i<s.size();i++){
            if(s[i]!='a')m=min(m,(int)(s[i]-'a'));
        }
        cout<<m;
        return (26-m)%26;
    }
};