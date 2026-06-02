class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int minLandFinish = INT_MAX, minWaterFinish = INT_MAX;

        for(int i = 0; i < n; i++)minLandFinish = min(minLandFinish,landStartTime[i] + landDuration[i]);
        for(int i = 0; i < m; i++)minWaterFinish = min(minWaterFinish,waterStartTime[i] + waterDuration[i]);

        int res = INT_MAX;

        for(int i = 0; i < m; i++){
            res = min(res,waterDuration[i] + max(minLandFinish,waterStartTime[i]));
        }
        for(int i = 0; i < n; i++){
            res = min(res,landDuration[i] + max(minWaterFinish,landStartTime[i]));
        }
        return res;
    }
};