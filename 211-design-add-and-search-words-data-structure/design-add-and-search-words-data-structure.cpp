class WordDictionary {
    struct Node{
        Node* links[26];
        bool flag = false;

        bool find(char ch){
            return links[ch-'a'] != nullptr;
        }

        void link(char ch, Node* node){
            links[ch-'a'] = node;
        }

        Node* move(char ch){
            return links[ch-'a'];
        }

        void setFlag(){
            flag = true;
        }

        bool getFlag(){
            return flag;
        }
    };

    bool searchDot(string& word, int ind, Node* node){
        if(ind == word.size())return node->getFlag();

        char ch = word[ind];
        if(ch == '.'){
            for(int i = 0; i < 26; i++){
                char chr = i+'a';
                Node* next = node->move(chr);
                if(next){
                    if(searchDot(word,ind+1,next))return true;
                }
            }
            return false;
        }
        else{
            if(!node->find(ch))return false;
            node = node->move(ch);
            return searchDot(word,ind+1,node);
        }
    }

    Node* root;

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(auto ch: word){
            if(!node->find(ch)){
                node->link(ch,new Node());
            }
            node = node->move(ch);
        }
        node->setFlag();
    }
    
    bool search(string word) {
        Node* node = root;
        return searchDot(word,0,node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */