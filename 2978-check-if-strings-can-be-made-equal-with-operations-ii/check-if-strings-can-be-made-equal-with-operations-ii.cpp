class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        vector<int> a(26,0),b(26,0),c(26,0);
        for(int i=0;i<n;i++){
            if(i%2==0){
                a[s1[i]-'a']++;
                a[s2[i]-'a']--;
            }
            else{
                b[s1[i]-'a']++;
                b[s2[i]-'a']--;
            }
        }
        return a==c && b==c;
    }
};