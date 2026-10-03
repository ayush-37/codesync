class Solution {
public:
    vector<int> segTree;
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        segTree.resize(4*n,0);
        buildTree(0,0,n-1,baskets);

        int ans = 0;
        for(int i = 0; i < n; i++){
            bool can = query(0,0,n-1,fruits[i]);
            if(!can)ans++;
        }

        return ans;
    }

    void buildTree(int idx, int l, int r, vector<int>& baskets){
        if(l == r){
            segTree[idx] = baskets[l];
            return;
        }

        int mid = l + (r-l)/2;
        buildTree(2*idx+1, l, mid, baskets);
        buildTree(2*idx+2, mid+1, r, baskets);

        segTree[idx] = max(segTree[2*idx+1], segTree[2*idx+2]);
    }

    bool query(int idx, int l, int r, int fruit){
        if(segTree[idx] < fruit)return false;

        if(l == r){
            if(segTree[idx] >= fruit){
                segTree[idx] = -1;
                return true;
            }
            return false;
        }

        int mid = l + (r-l)/2;
        bool placed = false;
        if(segTree[2*idx+1] >= fruit) placed = query(2*idx+1, l, mid, fruit);
        else placed = query(2*idx+2, mid+1, r, fruit);

        segTree[idx] = max(segTree[2*idx+1], segTree[2*idx+2]);
        return placed;
    }
};