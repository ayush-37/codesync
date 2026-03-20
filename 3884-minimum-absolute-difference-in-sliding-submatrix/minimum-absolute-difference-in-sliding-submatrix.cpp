class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if(i+k > n)break;
            vector<int> temp;
            for(int j = 0; j < m; j++){
                set<int> st;

                if(j+k > m)break;
                for(int x = i;x < i+k && x < n; x++){
                    for(int y = j;y < j+k && y < m; y++)st.insert(grid[x][y]);
                }

                int diff = INT_MAX;

                auto it = st.begin();
                auto prev = it;
                it++;

                while(it != st.end()){
                    diff = min(diff, abs(*it - *prev));
                    prev = it;
                    it++;
                }
                if(diff == INT_MAX)diff = 0;
                temp.push_back(diff);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};