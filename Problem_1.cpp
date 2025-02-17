// Author: Subhed Chavan
// Batch: December 24
// Problem Statement: Implement a Trie (Prefix Tree)
// Approach: TrieNode struct with an array for child
// Time Complexity: O(n)
// Space Complexity: O(n * m)

class Trie {
    private:
        struct TrieNode {
            TrieNode* children[26];
            bool isEnd;
            TrieNode() {
                for (int i = 0; i < 26; i++) {
                    children[i] = nullptr;
                }
                isEnd = false;
            }
        };
    
        TrieNode* root;
    
    public:
        // Constructor to initialize the Trie
        Trie() { root = new TrieNode(); }
    
        // Insert a word into the Trie
        void insert(string word) {
            TrieNode* curr = root;
            for (char c : word) {
                if (curr->children[c - 'a'] == nullptr) {
                    curr->children[c - 'a'] = new TrieNode();
                }
                curr = curr->children[c - 'a'];
            }
            curr->isEnd = true;
        }
    
        // Search for a word in the Trie
        bool search(string word) {
            TrieNode* curr = root;
            for (char c : word) {
                if (curr->children[c - 'a'] == nullptr) {
                    return false;
                }
                curr = curr->children[c - 'a'];
            }
            return curr->isEnd;
        }
    
        // Check if a prefix exists in the Trie
        bool startsWith(string prefix) {
            TrieNode* curr = root;
            for (char c : prefix) {
                if (curr->children[c - 'a'] == nullptr) {
                    return false;
                }
                curr = curr->children[c - 'a'];
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