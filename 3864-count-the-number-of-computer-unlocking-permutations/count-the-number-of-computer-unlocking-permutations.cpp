class Solution {
public:
    long long mult ;
    int factorial(int n) {
        if(n==0) return 1;
        else{
            mult = ((long long)n * (long long)factorial(n-1))%1000000007;
            return mult; 
        }
    }
    int countPermutations(vector<int>& c) {
        int x=c[0];
        sort(c.begin(),c.end());
        if(c[0]!=x || c[1]==x) return 0;
        return factorial(c.size()-1);
    }
};