// Author: Subhed Chavan
// Batch: December 24
// Problem Statement: Replace Words
// Approach: Trie
// Time Complexity: O(N + M), 
// Space Complexity: O(N), 


class Solution {
    private:
        struct TrieNode {
            TrieNode* children[26]; // Array to store child nodes
            bool isEnd;             // Flag to mark the end of a word
            TrieNode() {
                for (int i = 0; i < 26; i++) {
                    children[i] = nullptr;
                }
                isEnd = false;
            }
        };
        
        TrieNode* root;
    
        // Function to insert a word into the Trie    
        void insert(const string& word) {
            TrieNode* curr = root;
            for (char c : word) {
                if (curr->children[c - 'a'] == nullptr) {
                    curr->children[c - 'a'] = new TrieNode();
                }
                curr = curr->children[c - 'a'];
            }
            curr->isEnd = true;
        }
        
    public:
    
        // Function to replace words in the sentence using the shortest root word from the dictionary
        string replaceWords(vector<string>& dictionary, string sentence) {
            if (sentence.empty()) {
                return sentence;
            }
            
            root = new TrieNode();
            for (const string& word : dictionary) {
                insert(word);
            }
            
            string result;
            size_t pos = 0;
            while (pos < sentence.length()) {
                if (!result.empty()) {
                    result += " ";
                }
                
                size_t space = sentence.find(' ', pos);
                string word = sentence.substr(pos, space - pos);
                
                TrieNode* curr = root;
                string prefix;
                for (char c : word) {
                    if (curr->children[c - 'a'] == nullptr || curr->isEnd) {
                        break;
                    }
                    prefix += c;
                    curr = curr->children[c - 'a'];
                }
                
                // Use the prefix if found; otherwise, use the original word
                result += (curr->isEnd) ? prefix : word;
                pos = (space == string::npos) ? sentence.length() : space + 1;
            }
            
            return result;
        }
    };
    