class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<vector<int>> lang(m+1,vector<int> (n+1,0));
        
        for(int i = 0; i < m; i++){
            for(auto x: languages[i])lang[i+1][x] = 1;
        }

        unordered_set<int> st;
        for(auto x: friendships){
            int f1 = x[0], f2 = x[1];
            bool communicate = false;
            for(int i = 1; i <= n; i++){
                if(lang[f1][i] == 1 && lang[f2][i] == 1){
                    communicate = true;
                    break;
                }
            }

            if(!communicate){
                st.insert(f1);
                st.insert(f2);
            }
        }

        int badFriends = st.size();
        vector<int> cnt(n+1);
        for(auto x: st){
            for(auto v: languages[x-1])cnt[v]++;
        }

        int maxi = 0;
        for(auto x: cnt)maxi = max(maxi,x);
        
        return badFriends - maxi;
    }
};