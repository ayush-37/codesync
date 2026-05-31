class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int n = asteroids.size();
        vector<long long> psum(n+1,0);
        for(int i = 0; i < n; i++){
            psum[i+1] = psum[i] + asteroids[i];
        }

        bool ans = true;
        for(int i = 1; i < n+1; i++){
            if(psum[i-1]+mass < asteroids[i-1]){
                ans = false;
                break;
            }
        }
        return ans;
    }
};