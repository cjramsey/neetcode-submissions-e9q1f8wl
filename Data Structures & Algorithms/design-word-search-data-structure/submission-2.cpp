class WordDictionary {
private:
    struct Trie {
        unordered_map<char, shared_ptr<Trie>> next;
    };
    shared_ptr<Trie> root;

public:
    WordDictionary() {
        root = make_shared<Trie>();
    }
    
    void addWord(string word) {
        word += '*';
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
    }
    
    bool search(string word, shared_ptr<Trie> cur = nullptr) {
        if (word[word.length() - 1] != '*') {
            word += '*';
        }
        cout << word << '\n';
        if (!cur) {
            cur = root;
        }

        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (cur->next.contains(c)) {
                cur = cur->next[c];
            }
            else if (c == '.') {
                for (const auto& next: cur->next) {
                    if (next.first == '*') {
                        continue;
                    } 
                    if (search(word.substr(i + 1), next.second)) {
                        return true;
                    }
                }
                return false;
            }
            else {
                return false;
            }
        }    
        return true;
    }
};
