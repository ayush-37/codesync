class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n / rows;
        string ans;
        for(int j = 0; j < cols; j++){
            int c = j;
            for(int i = 0; i < rows && c < cols; i++, c++){
                int ind = i*cols + c;
                ans.push_back(encodedText[ind]);
            }
        }

        while(!ans.empty() && ans.back() == ' ')ans.pop_back();
        return ans;
    }
};