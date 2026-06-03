class Solution {
public:
    int earliestFinishTime(vector<int>& la, vector<int>& lan, vector<int>& wa, vector<int>& wat) {
        int a=INT_MAX;
        for(int i=0;i<la.size();i++){
            a=min(a,la[i]+lan[i]);
        }
        int y=INT_MAX;
        for(int i=0;i<wa.size();i++){
            y=min(y,max(a,wa[i])+wat[i]);
        }
        int x=INT_MAX;
        for(int i=0;i<wa.size();i++){
            x=min(x,wa[i]+wat[i]);
        }
        int z=INT_MAX;
        for(int i=0;i<la.size();i++){
            z=min(z,max(x,la[i])+lan[i]);
        }
        return min(y,z);
    }
};