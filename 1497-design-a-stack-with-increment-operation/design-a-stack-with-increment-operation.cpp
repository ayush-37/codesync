class CustomStack {
public:
    vector<int> arr;
    int size, curr;
    CustomStack(int maxSize) {
        size = maxSize;
        arr.resize(size,-1);
        curr = -1;
    }
    
    void push(int x) {
        if(curr+1 < size && arr[curr+1] == -1){
            arr[curr+1] = x;
            curr++;
        }
    }
    
    int pop() {
        if(curr == -1)return -1;
        else{
            int temp = arr[curr];
            arr[curr] = -1;
            curr--;
            return temp;
        }
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(size,k) && arr[i] != -1; i++)arr[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */