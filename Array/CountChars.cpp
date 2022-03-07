#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
 * You are given an array of strings words and a string chars.
A string is good if it can be formed by characters from chars (each character can only be used once).
Return the sum of lengths of all good strings in words.
Example 1:
Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation:
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/discuss/360978/C%2B%2B-Track-Count

 */

int countChars(vector<string>& words, string chars) {
	int len = 0;
	if(words.size() == 0) return len;

	unordered_map<char, int> map;
	for(char c: chars) {
		map[c]++;
	}

	for(string word : words) {
		unordered_map<char, int> temp = map;
		bool match = true;
		for(char c : word) {
			if(--temp[c] < 0) {
				match = false;
				break;
			}
		}
		if(match) len += word.size();
	}
	return len;
}
/*
int main() {
	vector<string> words;
	words.push_back("hello");words.push_back("world");words.push_back("leetcode");
	string chars = "welldonehoneyr";
	cout << countChars(words, chars) << endl;

	return 0;
}
*/
