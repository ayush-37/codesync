class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        solve(arr,0,ans,0,0);
        return ans;
    }

    void solve(vector<string>& arr, int ind, int& ans, int cnt, int msk){
        if(ind  == (int)arr.size()){
            ans = max(ans,cnt);
            return;
        }

        bool pos = true;
        vector<int> v(26,0);
        for(int i = 0; i < arr[ind].size(); i++){
            int s = arr[ind][i] - 'a';
            if((v[s] == 1) || (msk>>s)&1){
                pos = false;
                break;
            }
            v[s]++;
        }

        if(pos){
            // not use str
            solve(arr,ind+1,ans,cnt,msk);

            // use str
            for(auto x: arr[ind]){
                msk |= (1<<(x-'a'));
            }
            int inc = arr[ind].size();
            solve(arr,ind+1,ans,cnt+inc,msk);
        }
        else{
            solve(arr,ind+1,ans,cnt,msk);
        }
    }

};