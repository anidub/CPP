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
/*https://leetcode.com/problems/design-add-and-search-words-data-structure/
 * Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise.
 word may contain dots '.' where dots can be matched with any letter.
 */
class TrieNode {
public:
	TrieNode* next[26];
	bool is_leaf = false;

	TrieNode* get(char c) {
		return next[c - 'a'];
	}

	void add(char c) {
		next[c - 'a'] = new TrieNode();
	}
};


class WordDictionary {
public:
	WordDictionary() {
		root = new TrieNode();
	}

	//TC:O(M), SC:O(M) M is key length.
	void addWord(const string &word) {
		TrieNode *p = root;
		for(char c : word) {
			if(p->get(c) == nullptr)
				p->add(c);
			p = p->get(c);
		}
		p->is_leaf = true;
	}

	//O(M) for the "well-defined" words without dots, where M is the key length,and N is a number of keys
	//, and O(N * 26 ^ M)for the "undefined" words. That corresponds to the worst-case situation of searching an undefined word
	//which is one character longer than all inserted keys.
	bool search(const string &word) {
		return search(word, 0, root);
	}


private:
	TrieNode *root;

	bool search(const string &word, int pos, TrieNode* root) {
		if(pos == word.length())
			return root->is_leaf;

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
	 WordDictionary* obj = new WordDictionary();
	 obj->addWord("bad");
	 bool param_2 = obj->search("bad");
}*/
