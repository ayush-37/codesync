class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> final,prev;

        for(int i = 0; i < arr.size(); i++){
            unordered_set<int> curr;
            for(auto itr = prev.begin(); itr != prev.end(); itr++){
                curr.insert((*itr)|arr[i]);
                final.insert((*itr)|arr[i]);
            }
            curr.insert(arr[i]);
            final.insert(arr[i]);

            prev = curr;
        }

        return (int)final.size();
    }
};