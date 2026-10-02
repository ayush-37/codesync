class NumArray {
public:
    vector<int> segTree, lazyTree;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.assign(4*n+1, 0);
        lazyTree.assign(4*n+1, 0);

        buildTree(0,0,n-1,nums);
    }
    void buildTree(int idx, int l, int r, vector<int>& nums){
        if(l == r){
            segTree[idx] = nums[r];
            return;
        }

        int mid = l + (r-l)/2;
        buildTree(2*idx+1, l, mid, nums);
        buildTree(2*idx+2, mid+1, r, nums);

        segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
    }
    
    void update(int index, int val) {
        updateTree(index, val, 0, 0, n-1);
    }
    void updateTree(int index, int val, int idx, int l, int r){
        if(l == index && l == r){
            segTree[idx] = val;
            return;
        }

        int mid = l + (r-l)/2;
        if(index <= mid)updateTree(index, val, 2*idx+1, l, mid);
        else updateTree(index, val, 2*idx+2, mid+1, r);

        segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
    }
    
    int sumRange(int left, int right) {
        return sum(left, right, 0, 0, n-1);
    }

    int sum(int start, int end, int idx, int l, int r){
        if(r < start || l > end)return 0;
        if(l >= start && r <= end)return segTree[idx];
        int mid = l + (r-l)/2;
        int left = sum(start, end, 2*idx+1, l, mid);
        int right = sum(start, end, 2*idx+2, mid+1, r);
        return left + right;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */