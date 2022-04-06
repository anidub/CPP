#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/verifying-an-alien-dictionary/
 * In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.
Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
https://leetcode.com/problems/verifying-an-alien-dictionary/discuss/1149842/Simple-Solution-using-HashMap-w-Explanation-or-O(N)-O(1)-or-Beats-100
 */
unordered_map<char, int> alienDict;
bool checkOrder(string &a, string &b);

//TC: O(N), SC: O(1), we only need constant amount of space to store the mapping of letters to index which does not depend on the size of input. Hence we get constant space complexity.
bool isAlienSorted(vector<string> &words, string order) {
	if(order.empty()) return false;

	for(int i = 0; i < order.size(); i++)
		alienDict[order[i]] = i;// mapping letter to its corresponding index in order

	for(int i = 0; i < words.size() - 1; i++) {
		if(!checkOrder(words[i], words[i+1])) return false;
	}
	return true;
}

// checking if two words are lexicographically sorted
bool checkOrder(string &a, string &b) {
	int i = 0;
	while(i < a.size() && i < b.size()) {
		if(alienDict[a[i]] != alienDict[b[i]]) return alienDict[a[i]] < alienDict[b[i]];
		i++;
	}
	return a.size() <= b.size();
}

/*
int main() {
	vector<string> words = {"hello", "leetcode"};
	cout << isAlienSorted(words, "hlabcdefgijkmnopqrstuvwxyz") << endl;

	return 0;
}
*/
