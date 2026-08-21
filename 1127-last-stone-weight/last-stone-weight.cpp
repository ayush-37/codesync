class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto x: stones)pq.push(x);

        while(pq.size() > 1){
            int m1 = pq.top();
            pq.pop();
            int m2 = pq.top();
            pq.pop();
            if(m1 != m2)pq.push(m1-m2);
        }

        return pq.empty()?0:pq.top();
    }
};