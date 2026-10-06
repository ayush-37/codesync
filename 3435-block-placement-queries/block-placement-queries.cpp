class Solution {
public:
    vector<int> seg;
    vector<bool> getResults(vector<vector<int>>& queries) {
        int qn = queries.size(), n = min(50001, 3*qn);
        seg.assign(4*n, 0);
        vector<bool> ans;
        set<int> st;
        st.insert(0);

        for(auto q: queries){
            int type = q[0];
            if(type == 1){
                auto it = st.lower_bound(q[1]);
                int last = *prev(it);
                update(q[1], q[1] - last, 0, 0, n-1);
                if(it != st.end()){
                    int next = *it;
                    update(next, next - q[1], 0, 0, n-1);
                }
                st.insert(q[1]);
            }
            else{
                auto it = st.lower_bound(q[1]);
                int last = *prev(it);
                int maxi = query(0, last, 0, 0, n-1);
                maxi = max(maxi, q[1] - last);

                ans.push_back(maxi >= q[2]);
            }
        }
        return ans;
    }

    void update(int i, int val, int idx, int l, int r){
        if(l == r){
            seg[idx] = val;
            return;
        }

        int mid = l + (r-l)/2;

        if(i <= mid)update(i,val,2*idx+1,l, mid);
        else update(i,val,2*idx+2,mid+1,r);

        seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
    }

    int query(int start , int end, int idx, int l, int r){
        if(l > end || r < start)return -1;
        if(l >= start && r <= end)return seg[idx];

        int mid = l + (r-l)/2;

        int left = query(start, end, 2*idx+1, l, mid);
        int right = query(start, end, 2*idx+2, mid+1, r);

        return max(left, right);
    }
};