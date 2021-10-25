#include <iostream>
#include <vector>

using namespace std;

/*
 * https://leetcode.com/problems/find-common-characters/
 * Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.
 *
 * Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]

https://leetcode.com/problems/find-common-characters/discuss/712527/C%2B%2B-simple-and-sweet
https://leetcode.com/problems/find-common-characters/discuss/247573/C%2B%2B-O(n)-or-O(1)-two-vectors
https://stackoverflow.com/questions/17201590/c-convert-from-1-char-to-string
 * works
 *
 */

/*
vector<string> commonchars(vector<string>& words) {
	vector<string> result;
	if(words.size() == 0)
		return result;
	vector<int> count1(26, INT_MAX);

	for(auto string : words) {
		vector<int> count2(26, 0);

		for(char c : string) {
			++count2[c - 'a'];
		}

		for(int i = 0; i < 26; i++) {
			count1[i] = min(count1[i], count2[i]);
		}
	}

	for(int i = 0; i < 26; i++) {
		int count = count1[i];
		while(count > 0) {
			result.push_back(string(1, i + 'a'));
			count--;
		}
	}

	return result;

}*/
/*
int main() {
	vector<string> words;
	words.push_back("bella");words.push_back("label");words.push_back("roller");

	commonchars(words);
	return 0;
} */
