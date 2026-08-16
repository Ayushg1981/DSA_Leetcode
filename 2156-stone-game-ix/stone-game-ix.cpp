class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();
        if(n==1) return false;
        if(n==2){
            if((stones[0]==1 && stones[1]==2) || (stones[0]==2 && stones[1]==1)) return true;
            else return false;
        }
        int a=0,b=0,c=0;
        for(int i=0;i<n;i++){
            if(stones[i]%3==0) a++;
            else if(stones[i]%3==1) b++;
            else c++;
        }
        if(a%2==0){
            if(b==0 || c==0) return false;
            return true;
        }
        else{
            if((b==0 || c==0) && (n-a)>2) return true;
            if(abs(b-c)>2) return true;
            else return false;
        }

    }
};