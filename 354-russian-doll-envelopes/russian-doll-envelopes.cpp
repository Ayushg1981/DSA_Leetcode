class Solution {
public:
    static bool f(vector<int>& a,vector<int>& b){
        if(a[0]==b[0]) return a[1]>b[1];
        else return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& en) {
        sort(en.begin(),en.end(),f);
        vector<int> temp;
        temp.push_back(en[0][1]);
        for(int i=1;i<en.size();i++){
            int x=en[i][1];
            if(en[i][1]>temp.back()){
                temp.push_back(x);
            }
            else{
                int j=lower_bound(temp.begin(),temp.end(),x)-temp.begin();
                temp[j]=en[i][1];
            }
        }
        return temp.size();
    }
};