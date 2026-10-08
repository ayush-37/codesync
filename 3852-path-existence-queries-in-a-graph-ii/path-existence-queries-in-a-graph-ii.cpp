class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> p;
        for(int i = 0; i < n; i++){
            p.push_back({nums[i],i});
        }
        sort(p.begin(), p.end());

        vector<int> nodeToIndex(n,0);
        for(int i = 0; i < n; i++){
            nodeToIndex[p[i].second] = i;
        }
        
        int jumps = log2(n) + 1;
        vector<vector<int>> anc(n, vector<int>(jumps, -1));

        auto search = [&](int target){
            int s= 0, e = n-1;
            int canJump = -1;
            while(s <= e){
                int mid = s + (e-s)/2;
                if(p[mid].first <= target){
                    canJump = mid;
                    s = mid+1;
                }
                else e = mid-1;
            }

            return canJump;
        };

        for(int i = 0; i < n; i++){
            int x = p[i].first;
            int mxj = x + maxDiff;

            int mj = search(mxj);
            if(mj == -1)mj = i;

            anc[i][0] = mj;
        }

        for(int i = 1; i < jumps; i++){
            for(int j = 0; j < n; j++){
                if(anc[j][i-1] == -1)continue;
                anc[j][i] = anc[anc[j][i-1]][i-1];
            }
        }

        vector<int> ans;
        for(auto q: queries){
            int node1 = nodeToIndex[q[0]], node2 = nodeToIndex[q[1]];
            if(node1 > node2)swap(node1, node2);
            if(node1 == node2){
                ans.push_back(0);
                continue;
            }

            int mnj = 0;
            for(int j = jumps-1; j >= 0; j--){
                if(anc[node1][j] < node2){
                    node1 = anc[node1][j];
                    mnj += (1<<j);
                }
            }

            if(anc[node1][0] >= node2)ans.push_back(mnj+1);
            else ans.push_back(-1);
        }

        return ans;
    }
};