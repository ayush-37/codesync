class Solution {
public:
    struct Node{
        int maxLen, pref, suff;
        char rightMost, leftMost;

        Node(int x, int p, int s, char a, char b){
            maxLen = x;
            pref = p;
            suff = s;
            leftMost = a;
            rightMost = b;
        }
    };

    vector<Node> seg;
    int n;
    string s;

    void build(int idx, int l, int r){
        if(l == r){
            seg[idx] = Node(1,1,1,s[l],s[l]);
            return;
        }

        int mid = l + (r-l)/2;

        build(2*idx+1, l, mid);
        build(2*idx+2, mid+1, r);

        Node left = seg[2*idx+1];
        Node right = seg[2*idx+2];

        int leftLen = mid - l + 1, rightLen = r - mid;

        seg[idx] = merge(left, right, leftLen, rightLen);
    }

    void update(int index, char newChar, int idx, int l, int r){
        if(l == r){
            seg[idx] = Node(1, 1, 1, newChar, newChar);
            return;
        }

        int mid = l + (r-l)/2;

        if(index <= mid){
            update(index, newChar, 2*idx+1, l, mid);
        }
        else update(index, newChar, 2*idx+2, mid+1, r);

        Node left = seg[2*idx+1];
        Node right = seg[2*idx+2];

        int leftLen = mid - l + 1, rightLen = r - mid;

        seg[idx] = merge(left, right, leftLen, rightLen);
    }

    Node merge(Node left, Node right, int leftLen, int rightLen){
        Node curr = {1,1,1,'0','0'};
        curr.maxLen = max(left.maxLen, right.maxLen);

        if(left.rightMost == right.leftMost){
            curr.maxLen = max(curr.maxLen, left.suff + right.pref);
        }

        curr.leftMost = left.leftMost;
        curr.rightMost = right.rightMost;

        curr.pref = left.pref;
        if(left.pref == leftLen && left.rightMost == right.leftMost)curr.pref = leftLen + right.pref;

        curr.suff = right.suff;
        if(right.suff == rightLen && left.rightMost == right.leftMost)curr.suff = rightLen + left.suff;

        return curr;
    }
    vector<int> longestRepeating(string str, string queryCharacters, vector<int>& queryIndices) {
        s = str;
        n = str.size();
        seg.assign(4*n, Node(1,1,1,'0','0'));

        build(0,0,n-1);

        int qn = queryIndices.size();
        vector<int> ans;
        for(int i = 0; i < qn; i++){
            update(queryIndices[i], queryCharacters[i], 0, 0, n-1);
            ans.push_back(seg[0].maxLen);
        }

        return ans;
    }
};