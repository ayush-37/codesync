class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size(), ans = 0;
        int l = 0, r = n-1;
        while(l <= r){
            if(people[r] + people[l] > limit){
                ans++;
                r--;
            }
            else{
                ans++;
                l++;
                r--;
            }
        }

        return ans;
    }
};