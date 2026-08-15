class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int s = 0, e = n-1, ans = 0;
        while(s <= e){
            int mid = s + (e-s)/2;
            vector<int> v;
            for(int i = 1; i <= mid; i++){
                if(heights[i]-heights[i-1] > 0)v.push_back(heights[i]-heights[i-1]);
            }

            sort(v.begin(),v.end());
            int sum = 0;
            for(int i = 0; i < (int)v.size()-ladders; i++){
                sum += v[i];
            }

            if(sum <= bricks){
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }

        return ans;
    }
};