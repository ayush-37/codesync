class Solution {
public:
    int findLUSlength(string a, string b) {
        int an = a.size(), bn = b.size();
        if(an > bn)return an;
        else if(an < bn)return bn;
        else {
            if(a == b)return -1;
            else return an;
        }
    }
};