class Solution {
public:
    vector<int> segMin, segMax, lazy;
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        segMin.assign(4*n,0);
        segMax.assign(4*n,0);
        lazy.assign(4*n,0);

        int maxLen = 0;
        unordered_map<int,int> seen;

        for(int i = 0; i < n; i++){
            int val = (nums[i]%2 == 0)? -1: 1;
            int prev = -1;
            if(seen.count(nums[i]))prev = seen[nums[i]];

            if(prev != -1)update(0, prev, 0, 0, n-1,-val);

            update(0, i, 0, 0, n-1, val);

            int last = findZero(0,0,n-1);
            if(last != -1)maxLen = max(maxLen, i - last + 1);
            seen[nums[i]] = i;
        }

        return maxLen;
    }

    void update(int start, int end, int idx, int l, int r, int val){
        propagate(idx, l, r);

        if(l > end || r < start)return;

        if(l >= start && r <= end){
            lazy[idx] += val;
            propagate(idx, l, r);
            return;
        }

        int mid = l + (r-l)/2;
        update(start, end, 2*idx+1, l, mid, val);
        update(start, end, 2*idx+2, mid+1, r, val);

        segMin[idx] = min(segMin[2*idx+1], segMin[2*idx+2]);
        segMax[idx] = max(segMax[2*idx+1], segMax[2*idx+2]);
    }

    int findZero(int idx, int l, int r){
        propagate(idx, l, r);

        if(segMin[idx] > 0 || segMax[idx] < 0)return -1;
        if(l == r)return l;

        int mid = l + (r-l)/2;
        int left = findZero(2*idx+1, l, mid);
        if(left != -1)return left;

        return findZero(2*idx+2, mid+1, r);
    }

    void propagate(int idx, int l, int r){
        if(lazy[idx] != 0){
            segMin[idx] += lazy[idx];
            segMax[idx] += lazy[idx];

            if(l != r){
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }

            lazy[idx] = 0;
        }
    }
};