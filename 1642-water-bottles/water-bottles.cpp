class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // int ans=0;
        // int a=0;
        // while(numBottles>0){
        //     ans+=numBottles;
        //     numBottles+=a;
        //     a=numBottles%numExchange;
        //     numBottles/=numExchange;
        // }
        // return ans;
        return numBottles+((numBottles-1)/(numExchange-1));
    }
};