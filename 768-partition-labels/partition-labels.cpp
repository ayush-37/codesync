class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> first(26,-1), last(26,-1);

        for(int i = 0; i < n; i++){
            int c = s[i]-'a';
            if(first[c] == -1)first[c] = i;
            last[c] = i;
        }

        int i = 0;
        int l = n+1, r = -1;
        vector<int> vis(26,0);
        vector<int> ans;
        while(i < n){
            int c = s[i]-'a';
            if(vis[c]){
                i++;
                continue;
            }

            vis[c] = 1;
            // cout<<s[i]<<"  "<<first[i]<<" "<<last[c]<<endl;
            if(r != -1 && first[c] > r){
                // cout<<l<<" "<<r<<endl;
                ans.push_back(r-l+1);
                l = first[c], r = last[c];
            }
            else{
                l = min(l,first[c]);
                r = max(r,last[c]);
            }
            i++;
        }
        ans.push_back(r-l+1);
        return ans;
    }
};