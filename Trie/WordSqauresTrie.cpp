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
#include <set>

using namespace std;
// works
//http://www.voycn.com/article/leetcode-425-dancifangkuaitrieshudfs : used
//https://www.cnblogs.com/grandyang/p/6006000.html
/*https://www.youtube.com/watch?v=unLYmWQ9MVI
 * Time complexity:
Say there are n words, the words' length is l, and each trie node has c children on average. buildTrie() takes O(ln).
 wordSquares() helper method takes O(c^l). So the for loop takes O(nc^l). The overall time complexity is O(ln + nc^l).
 */
class Trie{
public:
	bool endOfWord = false;;
	Trie* next[26] = {NULL};
	vector<int> words; // words passing through this node. store their index

	void insert(string& s, int idx){
		Trie* cur = this;
		for(int i = 0; i < s.size(); i++) {
			if(!cur->next[s[i] - 'a'])
				cur->next[s[i] - 'a'] = new Trie();
			cur = cur->next[s[i] - 'a'];
			cur->words.push_back(idx);
		}
		cur->endOfWord = true;
	}
};

vector<vector<string>> ans;
int n;

void dfsWordSquares(vector<string>& words, Trie* t, vector<string>& mat, int level, int n) {
	if(level == n) {
		ans.push_back(mat);
		return;
	}

	string nextPrefix;
	for(int i = 0; i < level; i++)
		nextPrefix += mat[i][level];

	Trie* cur = t;
	for(int i = 0; i < nextPrefix.size(); i++) {
		if(!cur->next[nextPrefix[i] - 'a'])
			return;
		cur = cur->next[nextPrefix[i] - 'a'];
	}
	for(int wd_idx : cur->words) {
		mat.push_back(words[wd_idx]);
		dfsWordSquares(words, t, mat, level+1, n);
		mat.pop_back();
	}
}

vector<vector<string>> wordSquaresTrie(vector<string>& words) {
	Trie* t = new Trie();
	for(int i = 0; i < words.size(); i++) {
		t->insert(words[i], i);
	}
	int n = words[0].size();
	vector<string> mat;
	for(auto& w : words) {
		mat.push_back(w);
		dfsWordSquares(words, t, mat, 1, n);
		mat.pop_back();
	}
	return ans;
}


/*
struct TrieNode {
        vector < int > indexes;
        vector <TrieNode*> children;
        TrieNode(): children( 26 , nullptr) {}
 };
 TrieNode * buildTrie(vector< string >& words) {
        TrieNode *root = new TrieNode();
         for ( int i = 0 ; i <words.size(); ++ i) {
            TrieNode *t = root;
             for ( int j = 0 ; j <words[i].size(); ++ j) {
                 if (!t->children[words[i][j]- 'a' ]) {
                    t ->children[words[i][j]- 'a' ] = new TrieNode();
                }
                t = t->children[words[i][j]- 'a' ];
                t -> indexes.push_back(i);
            }
        }
        return root;
 }

void helper(vector< string >& words, int level, TrieNode* root, vector< string >& out , vector<vector< string >>& res) {
         if (level >= words[ 0 ].size()) {
            res.push_back( out );
             return ;
        }
        string str = "" ;
         for ( int i = 0 ; i <level; ++ i) {
            str += out [i][level];
        }
        TrieNode *t = root;
         for ( int i = 0 ; i <str.size(); ++ i) {
             if (!t->children[str[i] - 'a' ]) return ;
            t = t->children[str[i] - 'a' ];
        }
        for ( int idx: t-> indexes) {
             out [level] = words[idx];
            helper(words, level + 1 , root, out , res);
        }
}

vector <vector< string >> wordSquaresTrie(vector< string >& words) {
        TrieNode *root = buildTrie(words);
        vector < string > out (words[ 0 ].size());
        vector <vector< string >> res;
         for ( string word: words) {
             out [ 0 ] = word;
            helper(words, 1 , root, out , res);
        }
        return res;
}*/
/*
 int main() {
    	vector<string> words;
    	words.push_back("area");words.push_back("lead");
    	words.push_back("wall");words.push_back("lady");
    	words.push_back("ball");
        vector<vector<string>> res = wordSquaresTrie(words);
        for(auto& s : res) {
            for(auto& i : s) {
                cout << i << endl;
            }
            cout << "---" << endl;
        }

    	return 0;
 }*/
