#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/
 *With respect to a given puzzle string, a word is valid if both the following conditions are satisfied:
word contains the first letter of puzzle.
For each letter in word, that letter is in puzzle.
For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and "baggage", while
invalid words are "beefed" (does not include 'a') and "based" (includes 's' which is not in the puzzle).
Return an array answer, where answer[i] is the number of words in the given word list words that is valid with respect to the puzzle puzzles[i].
Example 1:
Input: words = ["aaaa","asas","able","ability","actt","actor","access"], puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
Output: [1,1,3,2,4,0]
Explanation:
1 valid word for "aboveyz" : "aaaa"
1 valid word for "abrodyz" : "aaaa"
3 valid words for "abslute" : "aaaa", "asas", "able"
2 valid words for "absoryz" : "aaaa", "asas"
4 valid words for "actresz" : "aaaa", "asas", "actt", "access"
There are no valid words for "gaswxyz" cause none of the words in the list contains letter 'g'.
https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/discuss/372227/Detailed%3A-C%2B%2B-bit-set-hash-map-and-backtracking-(140ms-100-time-and-100-space)
https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/tutorial/ : to study bitmask

 */

inline void setBit(int& bit, int pos) {
	bit |= 1 << pos;
}

const int checkSubset(int& bits, int pos, const string& s, const unordered_map<int, int>& wordSets) {
	if(pos == s.size()) {
		auto found = wordSets.find(bits);
		return found != wordSets.end() ? found->second : 0;
	}

	int tmp = bits;
	int res = checkSubset(bits, pos+1, s, wordSets);
	setBit(bits, s[pos] - 'a');

	res += checkSubset(bits, pos+1, s, wordSets);
	bits = tmp;
	return res;
}
/*
 * Counting occurence of word patterns: O(M)
Checking puzzles: O(256 * N) = O(N)
Total complexity: O(M + N)
 */
vector<int> findNumValidWords(vector<string>& words, vector<string>& puzzles) {
	unordered_map<int, int> wordSets;
	for(const auto& word : words) {
		int bits = 0;
		for(char c : word)
			setBit(bits, c - 'a');
		wordSets[bits]++;
	}

	vector<int> result;
	result.reserve(puzzles.size());

	for(const auto& puzzle : puzzles) {
		int bits = 0;
		setBit(bits, puzzle[0] - 'a');
		int cnt = checkSubset(bits, 1, puzzle, wordSets);
		result.push_back(cnt);
	}
	return result;

}
/*
int main() {
	vector<string> words; words.push_back("aaaa");words.push_back("asas");words.push_back("able");
	words.push_back("ability");words.push_back("actt");words.push_back("actor");
	words.push_back("access");
	vector<string> puzzles; puzzles.push_back("aboveyz");puzzles.push_back("abrodyz");puzzles.push_back("abslute");
	puzzles.push_back("absoryz");puzzles.push_back("actresz");puzzles.push_back("gaswxyz");

	findNumValidWords(words, puzzles);

	return 0;
}*/
