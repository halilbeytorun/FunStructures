#include <string>
#include <iostream>

#include <gtest/gtest.h>

using namespace std;



class TrieNode {
public:
    unique_ptr<TrieNode> children[26]; // Each node can have 26 possible children for each lowercase letter
    bool isEnd; // To mark the end of a word
    
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    unique_ptr<TrieNode> root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = make_unique<TrieNode>();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root.get();
        for (char c : word) {
            int index = c - 'a'; // Convert character to index (0 to 25)
            if (node->children[index] == nullptr) {
                node->children[index] = make_unique<TrieNode>(); // Create a new node if not already present
            }
            node = node->children[index].get();
        }
        node->isEnd = true; // Mark the end of the word
    }
    
    /** Returns true if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root.get();
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false; // If a node doesn't exist for the character, word is not found
            }
            node = node->children[index].get();
        }
        return node->isEnd; // Check if the last node is the end of a word
    }
    
    /** Returns true if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root.get();
        for (char c : prefix) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false; // If a node doesn't exist for the character, no word starts with this prefix
            }
            node = node->children[index].get();
        }
        return true; // If we can traverse through all characters of the prefix
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class TrieTest : public testing::Test
{

public:
    Trie unit{};
};


TEST_F(TrieTest, InsertAndSearch)
{
    this->unit.insert("halil");
    ASSERT_FALSE(this->unit.search("hhalil"));
    ASSERT_TRUE(this->unit.search("halil"));

}


