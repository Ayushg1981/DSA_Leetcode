class Solution {
public:
    int compareVersion(string v1, string v2) {
        int x=0,y=0;
        int i=0,j=0;
        while(i<v1.size() && j<v2.size()){
            x=0;
            y=0;
            while(i<v1.size() && v1[i]!='.'){
                x=x*10+(v1[i]-'0');
                i++;
            }
            while(j<v2.size() && v2[j]!='.'){
                y=y*10+(v2[j]-'0');
                j++;
            }
            i++;
            j++;
            if(x>y) return 1;
            if(y>x) return -1;
        }
        while(i<v1.size()){
            x=0;
            while(i<v1.size() && v1[i]!='.'){
                x=x*10+(v1[i]-'0');
                i++;
            }
            i++;
            if(x!=0) return 1;
        }
        while(j<v2.size()){
            y=0;
            while(j<v2.size() && v2[j]!='.'){
                y=y*10+(v2[j]-'0');
                j++;
            }
            j++;
            if(y!=0) return -1;
        }
        return 0;
    }
};