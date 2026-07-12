class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int hrSt = (startTime[0]-'0')*10+((startTime[1]-'0'));
        int minSt = (startTime[3]-'0')*10+((startTime[4]-'0'));
        int secSt = (startTime[6]-'0')*10+((startTime[7]-'0'));

        int hrEnd = (endTime[0]-'0')*10+((endTime[1]-'0'));
        int minEnd = (endTime[3]-'0')*10+((endTime[4]-'0'));
        int secEnd = (endTime[6]-'0')*10+((endTime[7]-'0'));

        return (hrEnd*3600 + minEnd*60 + secEnd) - (hrSt*3600 + minSt*60 + secSt);
    }
};