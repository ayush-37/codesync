class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < arr1.size(); i++){
            int temp = arr1[i];
            while(temp){
                mp[temp] = 1;
                temp/=10;
            }
        }
        for(int i = 0; i < arr2.size(); i++){
            int temp = arr2[i];
            while(temp){
                if(mp.count(temp)){
                    ans = max(ans,(int)to_string(temp).size());
                    break;
                }
                temp/=10;
            }
        }
        return ans;
    }
};