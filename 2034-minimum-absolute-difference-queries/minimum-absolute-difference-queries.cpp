class Solution {
public:

    // if i can know which numbers between 1 and 100 are present in the range l and r, i can find the answer
    
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> pref(n+1, vector<int>(101,0));
        for(int i = 0 ; i < n; i++){
            for(int j = 1; j <= 100; j++){
                pref[i+1][j] = pref[i][j];
                if(j == nums[i])pref[i+1][j]++;
            }
        }

        vector<int> ans;

        for(int i = 0; i < queries.size(); i++){
            int l = queries[i][0], r = queries[i][1];
            int mini = INT_MAX, last = -1;

            for(int j = 1; j <= 100; j++){
               int cnt = pref[r+1][j] - pref[l][j];
               if(cnt != 0){
                    if(last != -1)mini = min(mini, j - last);
                    last = j;
                }
            }

            if(mini == INT_MAX)mini = -1;
            ans.push_back(mini);
        }

        return ans;
    }
};