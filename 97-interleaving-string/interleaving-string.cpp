class Solution {
public:
    bool solve(string& s1, string& s2, int i, int j, int k, string& s3,map<tuple<int,int>,bool>& mp){
        if(k == s3.size())return true;
        if(mp.count({i,j}))return mp[{i,j}];
        bool t1 = false;
        if(i < s1.size() && s1[i] == s3[k])t1 |= solve(s1,s2,i+1,j,k+1,s3,mp);
        if(j < s2.size() && s2[j] == s3[k])t1 |= solve(s1,s2,i,j+1,k+1,s3,mp);

        return mp[{i,j}] = t1;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if((int)s1.size() + (int)s2.size() != (int)s3.size())return false;
        map<tuple<int,int>,bool> mp;
        int n = s1.size(), m = s2.size(), s = s3.size();
        return solve(s1,s2,0,0,0,s3,mp);
    }
};