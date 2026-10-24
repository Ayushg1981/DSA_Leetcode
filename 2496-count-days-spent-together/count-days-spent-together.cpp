class Solution {
public:
    int f(string a,string b){
        vector<int> v={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int montha=(a[0]-'0')*10+a[1]-'0';
        int monthb=(b[0]-'0')*10+b[1]-'0';
        int datea=(a[3]-'0')*10+a[4]-'0';
        int dateb=(b[3]-'0')*10+b[4]-'0';
        if(montha>monthb) return 0;
        if(montha==monthb && datea>dateb) return 0;
        int ans=0;
        if(montha==monthb) return dateb-datea+1;
        if(montha<monthb){
            ans+=v[montha-1]-datea+1;
            montha++;
        }
        while(montha<monthb){
            ans+=v[montha-1];
            montha++;
        }
        return ans+dateb;
    }
    string ma(string a,string b){
        int montha=(a[0]-'0')*10+a[1]-'0';
        int monthb=(b[0]-'0')*10+b[1]-'0';
        int datea=(a[3]-'0')*10+a[4]-'0';
        int dateb=(b[3]-'0')*10+b[4]-'0';
        if(montha>monthb) return a;
        else if(montha<monthb) return b;
        else if(datea>dateb) return a;
        else return b;
    }
    string mi(string a,string b){
        int montha=(a[0]-'0')*10+a[1]-'0';
        int monthb=(b[0]-'0')*10+b[1]-'0';
        int datea=(a[3]-'0')*10+a[4]-'0';
        int dateb=(b[3]-'0')*10+b[4]-'0';
        if(montha<monthb) return a;
        else if(montha>monthb) return b;
        else if(datea<dateb) return a;
        else return b;
    }
    int countDaysTogether(string aA, string lA, string aB, string lB) {
        return f(ma(aA,aB),mi(lA,lB));
    }
};