#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <stack>
#include <utility>
#include <list>
#include <iterator>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/design-add-and-search-words-data-structure/
 *esign a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

https://leetcode.com/problems/design-add-and-search-words-data-structure/discuss/59552/C%2B%2B-Trie : comments
 */
class TrieNode {
public:
	TrieNode *next[26]{};
	bool is_leaf = false;
	TrieNode *get(char c) { return next[c - 'a'];}
	void *add(char c) { next[c - 'a'] = new TrieNode;}
};

class WordAddSearch {
public:
	WordAddSearch() : root(new TrieNode) {}

	void addWord(const string &word) {
		auto p = root;
		for(auto c : word) {
			if(!p->get(c)) p->add(c);
			p = p->get(c);
		}
		p->is_leaf = true;
	}

	bool search(const string &word) { return search(word, 0, root); }

private:
	TrieNode *root;
	//TC: O(M) for well definesd words without dots and O(N26^M) for undefined words, hence worse case : O(26^M)
	//SC : O(1) for defined words, O(M) for undefined words
	bool search(const string &word, int pos, TrieNode *root) {
		if(pos == word.size()) return root->is_leaf;

		if(word[pos] != '.') {
			root = root->get(word[pos]);
			return root ? search(word, pos + 1, root) : false;
		}
		for(int i = 0; i < 26; i++) {
			if(root->next[i] && search(word, pos + 1, root->next[i]))
				return true;
		}
		return false;
	}
};
/*
int main() {
	WordAddSearch* obj = new WordAddSearch();
	obj->addWord("bad");obj->addWord("dad");obj->addWord("mad");
	cout <<  obj->search("dad") << endl;
	cout <<  obj->search(".ad") << endl;
	delete obj;

	return 0;
}*/
