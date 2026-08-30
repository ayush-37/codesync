class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<int> row(n,1);
        int sum = 0, temp = 1;
        for(int i = 0; i < n; i++)sum += mat[i][0];
        if(k == 1)return sum;

        priority_queue<
                pair<int,vector<int>>, 
                vector<pair<int,vector<int>>>, 
                greater<pair<int,vector<int>>>
        > pq;

        set<pair<int, vector<int>>> st;

        pq.push({sum, row});
        st.insert({sum,row});

        int ans = -1;
        while(!pq.empty()){
            auto[s, v] = pq.top();
            pq.pop();

            if(temp == k){
                ans = s;
                break;
            }

            for(int i = 0; i < n; i++){
                if(v[i] == m)continue;

                int ts = s - mat[i][v[i] - 1] + mat[i][v[i]];
                v[i] += 1;
                if(st.insert({ts,v}).second)pq.push({ts, v});
                v[i] -= 1;
            }

            temp++;
        }

        return ans;
    }
};