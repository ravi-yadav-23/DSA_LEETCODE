class Solution {
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

    void insert(const string& word) {
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

    string findRoot(const string& word) {
        TrieNode* curr = root;
        string prefix;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                break;
            }
            prefix.push_back(c);
            curr = curr->children[idx];
            if (curr->isEnd) {
                return prefix;
            }
        }
        return word;
    }

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TrieNode();
        for (const string& word : dictionary) {
            insert(word);
        }
        string ans;
        string word;
        stringstream ss(sentence);
        while (ss >> word) {
            if (!ans.empty()) {
                ans.push_back(' ');
            }
            ans += findRoot(word);
        }
        return ans;
    }
};