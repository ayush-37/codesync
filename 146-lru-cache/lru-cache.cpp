class LRUCache {
    struct Node{
        int key,val;
        Node* next;
        Node* prev;

        Node(int key,int val){
            this->key = key;
            this->val = val;
            next = NULL;
            prev = NULL;
        }
    };
    
    void addNode(int key, int value){
        Node* node = new Node(key,value);
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
        mp[key] = node;
    }

    void removeNode(Node* node){
        Node* temp = node;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = NULL;
        temp->prev = NULL;
        mp.erase(temp->key);
        delete(temp);
    }

    void removeHead(){
        Node* temp = head->next;
        head->next = temp->next;
        temp->next->prev = head;
        temp->next = NULL;
        temp->prev = NULL;
        mp.erase(temp->key);
        delete(temp);
    }

    unordered_map<int,Node*> mp;
    Node* head;
    Node* tail;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.count(key)){
            int k = key;
            int v = mp[key]->val;
            removeNode(mp[key]);
            addNode(k,v);
            return v;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            removeNode(mp[key]);
            addNode(key,value);
        }
        else{
            if(mp.size() == cap){
                removeHead();
                addNode(key,value);
            }
            else{
                addNode(key,value);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */