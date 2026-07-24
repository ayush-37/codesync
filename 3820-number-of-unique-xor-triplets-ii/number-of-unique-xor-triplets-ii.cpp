class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st,fst,nst;
        for(int i = 0; i < n; i++){
            nst.insert(nums[i]);
            for(int j = 0; j < n; j++){
                st.insert(nums[i]^nums[j]);
            }
        }

        for(auto itr1 = st.begin(); itr1 != st.end(); itr1++){
            for(auto itr2 = nst.begin(); itr2 != nst.end(); itr2++)fst.insert(*itr1 ^ *itr2);
        }
        return (int)fst.size();
    }
};