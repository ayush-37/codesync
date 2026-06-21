class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans = 0;
        double min = minutes*6.0;
        double hr = hour*30.0 + minutes/2.0;
        if(abs(hr-min)>180.0)return 360.0-abs(hr-min);
        else return abs(hr-min);
    }
};