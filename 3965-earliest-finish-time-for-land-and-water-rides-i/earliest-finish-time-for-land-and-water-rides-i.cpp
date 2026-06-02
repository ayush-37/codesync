class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        // vector<vector<int>> landFirst(n,vector<int>(m,0)), waterFirst(m,vector<int>(n,0));
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(waterStartTime[j] <= landStartTime[i] + landDuration[i]){
                    ans = min(ans,landStartTime[i] + landDuration[i] + waterDuration[j]);
                }
                else{
                    ans = min(ans,waterStartTime[j] + waterDuration[j]);
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(landStartTime[j] <= waterStartTime[i] + waterDuration[i]){
                    ans = min(ans,waterStartTime[i] + waterDuration[i] + landDuration[j]);
                }
                else{
                    ans = min(ans,landStartTime[j] + landDuration[j]);
                }
            }
        }
        return ans;
    }
};