class Solution {
public:
    static bool f(int a,int b){
        int x=0,y=0;
        int c=a,d=b;
        while(a){
            a=a&a-1;
            x++;
        }
        while(b){
            b=b&b-1;
            y++;
        }
        if(x==y) return c<d;
        return x<y;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),f);
        return arr;
    }
};