class Solution {
public:
    int maxFreqSum(string s) {
        int x=0,y=0;
        unordered_map<char,int> m1,m2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') m1[s[i]]++;
            else m2[s[i]]++;
        }
        for(auto a:m1){
            x=max(x,a.second);
        }
        for(auto b:m2){
            y=max(y,b.second);
        }
        return x+y;
    }
};