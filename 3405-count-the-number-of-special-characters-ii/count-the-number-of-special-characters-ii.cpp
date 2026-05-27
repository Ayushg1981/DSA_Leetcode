class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> v(26,0);
        for(int i=0;i<word.size();i++){
            if(word[i]>='a' && word[i]<='z') v[word[i]-'a']++;
        }
        vector<int> a(26,0);
        vector<bool> flag(26,false);
        int ans=0;
        for(int i=0;i<word.size();i++){
            if(word[i]>='A' && word[i]<='Z'){
                if(!flag[word[i]-'A']){
                    flag[word[i]-'A']=true;
                    if(v[word[i]-'A']>0 && v[word[i]-'A']==a[word[i]-'A']) ans++;
                }
            }
            else a[word[i]-'a']++;
        }
        return ans;
    }
};