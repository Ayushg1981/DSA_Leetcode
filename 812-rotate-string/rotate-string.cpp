class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        s=s+s;
        for(int i=0;i<s.size();i++){
            int k=0;
            int j=i;
            while(k<goal.size() && s[j]==goal[k]){
                j++;
                k++;
            }
            if(k==goal.size()) return true;

        }
        return false;
    }
};