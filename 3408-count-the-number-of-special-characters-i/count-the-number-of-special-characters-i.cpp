class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> v1(26,false),v2(26,false);
        int ans=0;
        for(int i=0;i<word.size();i++){
            if(word[i]<='z' && word[i]>='a'){
                v2[word[i]-'a']=1;
            }
            else{
                v1[word[i]-'A']=1;
            }
        }
        for(int i=0;i<26;i++){
            if(v1[i] && v2[i]) ans++;
        }
        return ans;
    }
};