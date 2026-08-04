class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq; 
        for(int i = 0; i < n; i++){
            pq.push({matrix[0][i],{0,i}});
        }

        int ans = -1;

        while(!pq.empty() && k--){
            auto [s, p] = pq.top();
            ans = s;
            pq.pop();
            
            int x = p.first, y = p.second;
            if(x + 1 >= n)continue;

            pq.push({matrix[x+1][y], {x+1,y}});
        }
        return ans;
    }
};