class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        vector<pair<int,pair<int,int>>> len1, len2;
        int sum = 0, n = nums.size();
        int l = 0, r = 0;
        if(firstLen != 0){
            while(r < firstLen){
                sum += nums[r];
                r++;
            }
            len1.push_back({sum,{l,r-1}});
            while(r < n){
                sum += (nums[r] - nums[l]);
                len1.push_back({sum, {l+1, r}});
                l++,r++;
            }

            sort(len1.begin(), len1.end(), [&](pair<int,pair<int,int>>& a, pair<int,pair<int,int>>& b){
                return a.first > b.first;
            });
        }
        l = 0, r = 0, sum = 0;
        if(secondLen != 0){
            while(r < secondLen){
                sum += nums[r];
                r++;
            }
            len2.push_back({sum,{l,r-1}});
            while(r < n){
                sum += (nums[r] - nums[l]);
                len2.push_back({sum, {l+1, r}});
                l++,r++;
            }

            sort(len2.begin(), len2.end(), [&](pair<int,pair<int,int>>& a, pair<int,pair<int,int>>& b){
                return a.first > b.first;
            });
        }

        // for(auto x: len1)cout<<x.first<<" {"<<x.second.first<<","<<x.second.second<<"}, ";
        // cout<<endl;
        // for(auto x: len2)cout<<x.first<<" {"<<x.second.first<<","<<x.second.second<<"}, ";
        // cout<<endl;

        if(firstLen == 0)return len2[0].first;
        else if(secondLen == 0)return len1[0].first;
        else{
            int res = 0;
            for(auto [s1, c1]: len1){
                auto [l1,r1] = c1;
                for(auto [s2,c2]: len2){
                    auto [l2,r2] = c2;
                    if(r1 < l2 || l1 > r2){
                        res = max(res, s1 + s2);
                    }
                }
            }

            return res;
        }
        
    }
};