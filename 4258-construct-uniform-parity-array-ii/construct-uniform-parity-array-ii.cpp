class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mno = -1, mne = -1;
        for(auto x: nums1){
            if(x%2){
                if(mno == -1)mno = x;
                else mno = min(mno, x);
            }
            else{
                if(mne == -1)mne = x;
                else mne = min(mne, x);
            }
        }

        if(mno == -1 || mne == -1)return true;

        return mno < mne;
    }
};