class SegmentTree{
public:
    int n;
    vector<int> seg;

    SegmentTree(int m){
        n = m;
        seg.assign(4*n,0);
    }

    void updateRange(int idx, int l, int r, int index){
        if(l == r){
            seg[idx]++;
            return;
        }
        
        int mid = l + (r-l)/2;
        if(index <= mid)updateRange(2*idx+1, l, mid, index);
        else updateRange(2*idx+2, mid+1, r, index);

        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }

    void update(int ind){
        updateRange(0,0,n-1,ind);
    }

    int queryRange(int start, int end, int idx, int l, int r){
        if(l > end || r < start)return 0;

        if(l >= start && r <= end)return seg[idx];

        int mid = l + (r-l)/2;

        int left = queryRange(start, end, 2*idx+1, l, mid);
        int right = queryRange(start, end, 2*idx+2, mid+1, r);

        return left + right;
    }

    int query(int start, int end){
        return queryRange(start, end, 0, 0, n-1);
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        unordered_map<int,int> mp;
        for(auto x: temp){
            if(mp.count(x) == 0){
                mp[x] = (int)mp.size();
            }
        }

        int m = mp.size();

        SegmentTree seg1(m), seg2(m);

        vector<int> nums1, nums2;

        nums1.push_back(nums[0]);
        seg1.update(mp[nums[0]]);

        nums2.push_back(nums[1]);
        seg2.update(mp[nums[1]]);

        for(int i = 2; i < n; i++){
            int cv = mp[nums[i]];
            int cnt1 = seg1.query(cv+1,m-1), cnt2 = seg2.query(cv+1,m-1);

            bool addIntoOne = true;

            if(cnt1 < cnt2)addIntoOne = false;
            else if(cnt1 == cnt2){
                addIntoOne = (nums1.size() <= nums2.size());
            }

            if(addIntoOne){
                nums1.push_back(nums[i]);
                seg1.update(cv);
            }
            else{
                nums2.push_back(nums[i]);
                seg2.update(cv);
            }
        }
        
        nums1.insert(end(nums1), begin(nums2), end(nums2));

        return nums1;
    }
};