class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        TrieNode() : isEnd(false) {
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    bool dfs(const string& word, int idx, TrieNode* node) {
        if (node == nullptr) {
            return false;
        }
        if (idx == (int)word.size()) {
            return node->isEnd;
        }
        char c = word[idx];
        if (c == '.') {
            for (int i = 0; i < 26; ++i) {
                if (node->children[i] != nullptr && dfs(word, idx + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int childIdx = c - 'a';
            return dfs(word, idx + 1, node->children[childIdx]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */