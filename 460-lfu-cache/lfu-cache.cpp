class LFUCache {
    struct Node{
        int key, val, use;
        Node* next;
        Node* prev;
        
        Node(int key, int val, int use = 0){
            this->key = key;
            this->val = val;
            next = NULL;
            prev = NULL;
            this->use = use+1;
        }
    };

    void addNode(int key, int val, int use){
        if(toTail.count(use+1) == 0){
            Node* th = new Node(-1,-1,-1);
            Node* tt = new Node(-1,-1,-1);
            th->next = tt;
            tt->prev = th;

            toTail[use+1] = tt;
            toHead[use+1] = th;

        }
        Node* tail = toTail[use+1];
        Node* node = new Node(key,val,use);
        tail->prev->next = node;
        node->next = tail;
        node->prev = tail->prev;
        tail->prev = node;
        mp[key] = node;
        cnt[use+1]++;
    }

    void removeNode(Node* node){
        Node* temp = node;
        temp->prev->next= temp->next;
        temp->next->prev = temp->prev;

        temp->next = NULL;
        temp->prev = NULL;

        mp.erase(temp->key);
        cnt[temp->use]--;
        if(cnt[temp->use] == 0){
            cnt.erase(temp->use);
        }
        delete(temp);
        
    }

    void removeHead(){
        int least = mini;
        Node* head = toHead[least];
        Node* temp = head->next;

        head->next = temp->next;
        temp->next->prev = head;
        temp->next = NULL;
        temp->prev = NULL;

        mp.erase(temp->key);
        cnt[temp->use]--;
        if(cnt[temp->use] == 0){
            cnt.erase(temp->use);
        }
        delete(temp);
    }

    unordered_map<int,int> cnt;
    unordered_map<int,Node*> mp;
    unordered_map<int,Node*> toTail;
    unordered_map<int,Node*> toHead;
    int mini;
    int cap;
public:
    LFUCache(int capacity) {
        cap = capacity;
        mini = 0;
    }
    
    int get(int key) {
        if(mp.count(key)){
            Node* node = mp[key];
            int u = node->use;
            int v = node->val;
            int k = key;

            removeNode(node);
            if(mini == u && !cnt.count(u))mini = u+1;
            addNode(k,v,u);
            return v;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* node = mp[key];
            int u = node->use;
            int v = node->val;
            int k = key;

            removeNode(node);
            if(mini == u && !cnt.count(u))mini = u+1;
            addNode(k,value,u);
        }
        else{
            if(mp.size() == cap){
                Node* node = toHead[mini]->next;
                removeNode(node);
                addNode(key,value,0);
                mini = 1;
            }
            else{
                addNode(key,value,0);
                mini = 1;
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */