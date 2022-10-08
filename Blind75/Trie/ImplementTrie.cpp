#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <stack>
#include <unordered_map>
#include <string.h>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/implement-trie-prefix-tree/
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings.
 *  There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True

 */

class TrieNode {
public:
	TrieNode *next[26];
	bool is_word;

	TrieNode(bool b = false) {
		is_word = b;
		memset(next, 0, sizeof(next));
	}
};

class Trie {
TrieNode *root;
public:
    Trie() {
    	root = new TrieNode();
    }

    //TC:O(N), SC:O(N) N is word length
    void insert(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.length(); i++) {
            if(p->next[word[i] - 'a'] == nullptr)
                p->next[word[i] - 'a'] = new TrieNode();
            p = p->next[word[i] - 'a'];
        }
        p->is_word = true;
    }

    //TC:O(N), SC:O(1) N is word length
    bool search(string word) {
    	TrieNode* p = find(word);
    	return p != nullptr && p->is_word;
    }

    bool startsWith(string prefix) {
    	return find(prefix) != nullptr;
    }

private:
    TrieNode* find(string key) {
        TrieNode* p = root;
        for(int i = 0; i < key.length() && p != nullptr; i++) {
            p = p->next[key[i] - 'a'];
        }
        return p;
    }
};
/*
int main() {
	Trie* obj = new Trie();
	obj->insert("apple");
	bool param_2 = obj->search("apple");
	bool param_3 = obj->startsWith("app");
}
*/
