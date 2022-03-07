#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <unordered_map>
#include <list>

using namespace std;
/*https://leetcode.com/problems/stream-of-characters/
 * Design an algorithm that accepts a stream of characters and checks if a suffix of these characters is a string of a given array of strings words.

For example, if words = ["abc", "xyz"] and the stream added the four characters (one by one) 'a', 'x', 'y', and 'z', your algorithm should detect that the suffix "xyz" of the characters "axyz" matches "xyz" from words.

Implement the StreamChecker class:

StreamChecker(String[] words) Initializes the object with the strings array words.
boolean query(char letter) Accepts a new character from the stream and returns true if any non-empty suffix from the stream forms a word that is in words.
Input
["StreamChecker", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query"]
[[["cd", "f", "kl"]], ["a"], ["b"], ["c"], ["d"], ["e"], ["f"], ["g"], ["h"], ["i"], ["j"], ["k"], ["l"]]
Output
[null, false, false, false, true, false, true, false, false, false, false, false, true]

Explanation
StreamChecker streamChecker = new StreamChecker(["cd", "f", "kl"]);
streamChecker.query("a"); // return False
streamChecker.query("b"); // return False
streamChecker.query("c"); // return False
streamChecker.query("d"); // return True, because 'cd' is in the wordlist
streamChecker.query("e"); // return False
streamChecker.query("f"); // return True, because 'f' is in the wordlist
streamChecker.query("g"); // return False
streamChecker.query("h"); // return False
streamChecker.query("i"); // return False
streamChecker.query("j"); // return False
streamChecker.query("k"); // return False
streamChecker.query("l"); // return True, because 'kl' is in the wordlist

https://leetcode.com/problems/stream-of-characters/discuss/807429/C%2B%2B-trie-solution-simple-and-clean-explained : COMMENTS
 */
struct SSCNode{
	bool isEnd = false;
	SSCNode* child[26];

	SSCNode() {
		memset(child, 0, sizeof(SSCNode*)*26);
	}
	~SSCNode() {
		for(int i = 0; i < 26; i++) {
			free(child[i]);
		}
	}
};

class StreamChecker{
public:
	StreamChecker(vector<string>& words) {
		root = new SSCNode();
		for(string& word : words) {
			maxL = max(maxL, word.size());
			addWord(word);
		}
	}

	bool query(char letter) {
		dict.push_back(letter);
		if(dict.size() > maxL) dict.pop_front();
		SSCNode* cur = root;
		for(auto it = dict.rbegin(); it != dict.rend(); it++) {
			if(cur->isEnd) return true;
			int pos = (*it) - 'a';
			if(!cur->child[pos]) return false;
			cur = cur->child[pos];
		}
		return cur->isEnd;
	}

private:
	SSCNode* root;
	list<char> dict;
	size_t maxL = 0;

	inline void addWord(string& word) {
		SSCNode* cur = root;
		for(int i = word.size() - 1; i >= 0; i--) {
			int pos = word[i] - 'a';
			if(!cur->child[pos])
				cur->child[pos] = new SSCNode();
			cur = cur->child[pos];
		}
		cur->isEnd = true;
	}
};

