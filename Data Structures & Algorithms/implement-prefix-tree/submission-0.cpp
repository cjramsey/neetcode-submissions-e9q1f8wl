class PrefixTree {
public:
    PrefixTree() 
    {
        root = make_shared<Trie>();
    }
    
    void insert(string word) { 
        shared_ptr<Trie> cur = root;
        for (char& c: word) {
            if (cur->next.contains(c)) {
                cur = cur->next[c];
            }
            else {
                shared_ptr<Trie> next = make_shared<Trie>();
                cur->next[c] = next;
                cur = next;
            }
        }
        cur->next['*'] = nullptr;
    }
    
    bool search(string word) {
        word += '*';
        shared_ptr<Trie> cur = root;
        for (char& c: word) {
            if (!cur->next.contains(c)) {
                return false;
            }
            cur = cur->next[c];
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        shared_ptr<Trie> cur = root;
        for (char& c: prefix) {
            if (!cur->next.contains(c)) {
                return false;
            }
            cur = cur->next[c];
        }
        return true;
    }

private:
    struct Trie {
        unordered_map<char, shared_ptr<Trie>> next;
    };
    shared_ptr<Trie> root;
};
