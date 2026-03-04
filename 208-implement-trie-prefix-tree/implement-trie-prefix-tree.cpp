class Trie {
    struct Node{
        Node* links[26];
        bool flag = false;

        bool containsChar(char c){
            if(links[c-'a'] == NULL)return 0;
            else return 1;
        }
        void linkNode(char c, Node* node){
            links[c-'a'] = node;
        }

        Node* moveNode(char c){
            return links[c-'a'];
        }

        void setFlag(){
            flag = true;
        }
        bool getFlag(){
            return flag;
        }
    };


    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsChar(word[i])){
                Node* child = new Node();
                node->linkNode(word[i],child);
            }
            node = node->moveNode(word[i]);
        }

        node->setFlag();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsChar(word[i])){
                return false;
            }
            node = node->moveNode(word[i]);
        }

        return node->getFlag();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++){
            if(!node->containsChar(prefix[i])){
                return false;
            }
            node = node->moveNode(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */