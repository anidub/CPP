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
/*https://leetcode.com/problems/longest-common-prefix/
 * Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Time complexity : preprocessing O(S)O, where S is the number of all characters in the array, LCP query O(m)O.

Trie build has O(S) time complexity. To find the common prefix of q in the Trie takes in the worst case O(m).

Space complexity : O(S). We only used additional S extra space for the Trie.
prefix of query string : q

https://leetcode.com/problems/longest-common-prefix/discuss/1742290/C%2B%2B-trie

 */
struct TrieNode {
    bool last = false;
    unordered_map<char, TrieNode *> letters;
};
class Trie {
    TrieNode head;
public:
    void addWord(const string &s) {
        TrieNode *p = &head;
        for(char c : s) {
            if(p->letters.count(c) == 0) {
                p->letters[c] = new TrieNode{};
            }
            p = p->letters[c];
        }
        p->last = true;
    }
    string lcp() {
        string ret;
        auto *p = &head;

        while(p->letters.size() == 1 && !p->last) {
            auto it = p->letters.begin();
            p = p->letters[it->first];
            ret += it->first;
        }
        return ret;
    }
};

string longestCommonPrefix(vector<string>& strs) {
    Trie trie;
    for(const auto &w : strs) {
        trie.addWord(w);
    }
    return trie.lcp();
}
/*
int main() {
	vector<string> strs = {"flower","flow","flight"};
	cout << longestCommonPrefix(strs) << endl;

	return 0;
}*/

