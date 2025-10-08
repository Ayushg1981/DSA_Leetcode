class Solution {
public:
    string removeSubstring(string s, int k) {
        int n=s.size();
        string temp;
        for(int i=0;i<n;i++){
            bool f=1;
            temp.push_back(s[i]);
            int n=temp.size();
            if(n>=2*k){
                for(int i=n-k;i<n;i++){
                    if(temp[i]=='('){
                        f=0;
                        break;
                    }
                }
                if(f){
                    for(int i=n-2*k;i<n-k;i++){
                        if(temp[i]==')'){
                            f=0;
                            break;
                        }
                    }
                    if(f){
                        int c=2*k;
                        while(c--){
                            temp.pop_back();
                        }
                    }
                }
            }
        }
        return temp;
    }
};