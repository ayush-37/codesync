class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 1, r = removable.size();
        int n = s.size();
        vector<int> mp(n,INT_MAX);
        for(int i = 0; i < removable.size(); i++){
            mp[removable[i]] = i+1;
        }

        int mid, ans = 0;
        while(l <= r){
            mid = l + (r-l)/2;
            if(is_subSeq(s,p,mid,mp)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }

    bool is_subSeq(string& s, string& p, int mid, vector<int>& mp){
        int i = 0, j = 0;
        while(i < s.size() && j < p.size()){
            if(mp[i] <= mid){
                i++;
            }
            else{
                if(s[i] == p[j]){
                    i++;
                    j++;
                }
                else{
                    i++;
                }
            }
        }
        if(j == p.size())return true;
        else return false;
    }
};