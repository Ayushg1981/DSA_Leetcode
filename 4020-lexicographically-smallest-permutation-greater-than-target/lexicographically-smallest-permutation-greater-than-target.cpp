class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> mp(26,0);
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a']++;
        }
        string ans="";
        bool f=true;
        int x=target.size();
        for(int i=0;i<target.size();i++){
            if(mp[target[i]-'a']>0){
                mp[target[i]-'a']--;
                ans+=target[i];
            }
            else{
                for(int j=target[i]-'a'+1;j<26;j++){
                    if(mp[j]>0){
                        ans+=char(j+'a');
                        mp[j]--;
                        f=false;
                        break;
                    }
                }
                if(f) break;
                for(int k=0;k<26;k++){
                    while(mp[k]>0){
                        ans+=char(k+'a');
                        mp[k]--;
                    }
                }
                return ans;
            }
        }
        bool a=true;
        if(f){
            int i=ans.size()-1;
            while(a&& i>=0){
                char b=ans[i];
                mp[ans[i]-'a']++;
                ans.erase(ans.begin()+i);
                i--;
                for(int j=b-'a'+1;j<26;j++){
                    if(mp[j]>0){
                        ans+=char(j+'a');
                        mp[j]--;
                        a=false;
                        break;
                    }
                }
            }
        }
        if(a==false){
            for(int k=0;k<26;k++){
                while(mp[k]>0){
                    ans+=char(k+'a');
                    mp[k]--;
                }
            }
            return ans;
        }
        return "";
    }
};