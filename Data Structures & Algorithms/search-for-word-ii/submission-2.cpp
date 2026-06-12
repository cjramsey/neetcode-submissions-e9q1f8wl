class Solution {
private:
    class Trie {
    public:
        struct TrieNode {
            unordered_map<char, shared_ptr<TrieNode>> next;
        };
        shared_ptr<TrieNode> root;

        Trie() {
            root = make_shared<TrieNode>();
        }

        void insert(string word) {
            word += '*';
            shared_ptr<TrieNode> cur = root;
            for (char c: word) {
                if (cur->next.contains(c)) {
                    cur = cur->next[c];
                }
                else {
                    shared_ptr next = make_shared<TrieNode>();
                    cur->next[c] = next;
                    cur = next;
                }
            }
        }

        // return number of letters matched so we know when to stop dfs
        int search(string word) {
            word += '*';
            int found = 0;
            shared_ptr<TrieNode> cur = root;
            for (char c: word) {
                if (!cur->next.contains(c)) {
                    return found;
                }
                cur = cur->next[c];
                ++found;
            }
            return found;
        }
    };

public:
    unordered_set<string> res;
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        res.clear();
        Trie trie{};
        for (const auto& word: words) {
            trie.insert(word);
        }
        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                char curChar = board[r][c];
                board[r][c] = '.';
                dfs(r, c, std::string(1, curChar), board, trie);
                board[r][c] = curChar;
            }
        }

        return vector<string>(res.begin(), res.end());
    }

    void dfs(int r, int c, string curWord, vector<vector<char>>& board, Trie& trie) {
        int result = trie.search(curWord);
        if (result < curWord.length()) {
            return;
        }
        if (result == curWord.length() + 1) {
            res.insert(curWord);
        }

        int m = board.size(), n = board[0].size();

        for (const auto[dr, dc]: directions) {
            int new_r = r + dr;
            int new_c = c + dc;
            if (new_r < 0 || new_r >= m || new_c < 0 || new_c >= n) {
                continue;
            }
            if (board[new_r][new_c] == '.') {
                continue;
            }
            char curChar = board[new_r][new_c];
            board[new_r][new_c] = '.'; 
            dfs(new_r, new_c, curWord + curChar, board, trie);
            board[new_r][new_c] = curChar;
        }
    }
};
