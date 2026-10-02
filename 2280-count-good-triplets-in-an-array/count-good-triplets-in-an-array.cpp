class Solution {
public:
    using ll = long long;
    vector<ll> segTree;
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        segTree.assign(4*n,0);
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++)mp[nums2[i]] = i;
        update(0,0,n-1,mp[nums1[0]]);

        ll cnt = 0;
        for(int i = 1; i < n; i++){
            int idx = mp[nums1[i]];
            ll leftCommon = query(0,idx-1,0,0,n-1);
            ll leftUncommon = i - leftCommon;
            ll eleAfterIdx = n-1 - idx;
            ll rightCommon = eleAfterIdx - leftUncommon;

            cnt += (leftCommon * rightCommon);
            update(0,0,n-1,idx);
        }

        return cnt;
    }

    void update(int idx, int l, int r, int index){
        if(l == r){
            segTree[idx] = 1;
            return;
        }

        int mid = l + (r-l)/2;
        if(index <= mid)update(2*idx + 1, l, mid, index);
        else update(2*idx + 2, mid+1, r, index);
        
        segTree[idx] = segTree[2*idx + 1] + segTree[2*idx + 2];
    }

    ll query(int start, int end, int idx, int l, int r){
        if(r < start || l > end)return 0LL;
        if(l >= start && r <= end)return segTree[idx];

        int mid = l + (r-l)/2;
        ll left = query(start, end, 2*idx + 1, l, mid);
        ll right = query(start, end, 2*idx + 2, mid+1, r);

        return left + right;
    }
};