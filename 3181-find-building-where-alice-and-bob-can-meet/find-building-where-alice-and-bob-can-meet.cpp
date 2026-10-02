class Solution {
public:
    vector<int> segTree;
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        segTree.assign(4*n+1,0);
        buildTree(0,0,n-1,heights);

        vector<int>res;
        for(auto q: queries){
            int a = min(q[0],q[1]), b = max(q[0],q[1]);
            // Same building
            if (a == b) {
                res.push_back(a);
                continue;
            }

            // If we can directly move from a to b
            if (heights[b] > heights[a]) {
                res.push_back(b);
                continue;
            }

            int l = b+1, r = n-1;
            int ans = -1;
            while(l <= r){
                int mid = l + (r-l)/2;
                int mxIdx = findMax(l,mid,0,0,n-1,heights);
                if(heights[mxIdx] > heights[a]){
                    ans = mxIdx;
                    r = mid-1;
                }
                else l = mid+1;
            }

            res.push_back(ans);
        }
        return res;
    }
    int findMax(int start, int end, int idx, int l, int r, vector<int>& heights){
        if(r < start || l > end)return -1;
        if(l >= start && r <= end)return segTree[idx];

        int mid = l + (r-l) / 2;
        int left = findMax(start, end, 2*idx+1, l, mid, heights);
        int right = findMax(start, end, 2*idx+2, mid+1, r, heights);
        
        if(left == -1)return right;
        if(right == -1)return left;

        if(heights[left] >= heights[right]){
            return left;
        }
        else{
            return right;
        }
        
    }
    int buildTree(int idx, int l, int r, vector<int>& heights){
        if(l == r){
            return segTree[idx] = l;
        }

        int mid = l + (r-l) / 2;
        int left = buildTree(2*idx+1, l, mid, heights);
        int right = buildTree(2*idx+2, mid+1, r, heights);

        if(heights[left] >= heights[right]){
            return segTree[idx] = left;
        }
        else{
            return segTree[idx] = right;
        }
    }
};