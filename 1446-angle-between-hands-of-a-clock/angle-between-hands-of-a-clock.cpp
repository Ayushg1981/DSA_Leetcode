class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m=minutes*6;
        double x=(hour*30)%360;
        x+=minutes*0.5;
        return min(abs(m-x),360-abs(m-x));
    }
};