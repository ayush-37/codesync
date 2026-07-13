class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                int sum = 0;
                bool is = true;
                for(int k = i; k <= j; k++){
                    sum = (sum*10) + (s[k]-'0');
                    if(sum > high){
                        is = false;
                        break;
                    }
                }
                if(is && (sum >= low && sum <= high))ans.push_back(sum);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};