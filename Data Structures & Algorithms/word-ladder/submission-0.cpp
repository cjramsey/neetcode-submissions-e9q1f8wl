class Solution {
public:
    unordered_map<string, vector<string>> patterns;
    unordered_set<string> seen;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        for (string& word: wordList) {
            for (string& pattern: generate_patterns(word)) {
                patterns[pattern].push_back(word);
            }
        }
        
        int steps = 1;  // steps in sequence (includes first word)
        queue<string> q;
        q.push(beginWord);
        seen.insert(beginWord);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                string cur = q.front();
                q.pop();
                for (string& pattern: generate_patterns(cur)) {
                    for (string& word: patterns[pattern]) {
                        if (word == endWord) {
                            return ++steps;
                        }
                        if (seen.contains(word)) {
                            continue;
                        }
                        seen.insert(word);
                        q.push(word);
                    }
                }
            }
            ++steps;
        }
        return 0;
    }

    vector<string> generate_patterns(string word) {
        int n = word.length();
        vector<string> res(n);
        for (int i = 0; i < n; ++i) {
            string cur = word.substr(0, i) + "*" + word.substr(i + 1);
            res[i] = cur;
        }
        return res;
    }
};
