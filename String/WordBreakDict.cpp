#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/word-break-ii/
 *Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
 Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]

https://leetcode.com/problems/word-break-ii/discuss/44178/11ms-C%2B%2B-solution-(concise)
Explaination:
lets take an example. s="catsand" and wordDict = ["cat", "cats", "and", "sand"].

The solution starts by taking the string S( "catsand") initially finding whether whole string is present or not . IN this case it is not present in the dict.

Now breaking the string and then finding
s.substr( i) gives the substring from ith index till the end. so string word goes as

atsand // not present
tsand // not present

sand //present then the remainder is calculated which is cat in this case and recursive function is called and same thing is done with cat which will return cat and also store the result in the unordered map . Now comes the combine part where both the string are combined and the pushed in the result " cat sand".

and // then comes and which is present so now again wordbreak called on remainder which is cats now and this will return cats. Now both strings are combined and inserted into result . result = {. "cat sand", "cats and"}; Now after the loop ending the result is returned and also stored in map.

Hope this helps.
 */
unordered_map<string, vector<string>> m;
vector<string> wordBreakDict(string s, unordered_set<string>& dict);
vector<string> combine(string word, vector<string> prev);

//Time: O(N2 +2powerN + W) Let N be the length of the input string and W be the number of words in the dictionary
//Space : O(2powerN . N + N2 + W)
vector<string> wordBreakDict(string s, vector<string>& wordDict) {
	if(s.empty()) return {};
	unordered_set<string> dict;
	for(auto& w : wordDict) {
		dict.insert(w);
	}
	return wordBreakDict(s, dict);
}

vector<string> wordBreakDict(string s, unordered_set<string>& dict) {
	if(m.count(s)) return m[s];//take from memory
	vector<string> result;

	if(dict.count(s)) result.push_back(s);//a whole string is a word

	for(int i = 1; i < s.size(); i++) {
		string word = s.substr(i);
		if(dict.count(word)) {
			string rem = s.substr(0, i);
			vector<string> prev = combine(word, wordBreakDict(rem, dict));
			result.insert(result.end(), prev.begin(), prev.end());
		}
 	}
	m[s] = result;//memorize
	return result;
}

vector<string> combine(string word, vector<string> prev) {
	cout << "---------------" << endl;
	for(int i = 0; i < prev.size(); i++) {
		cout << "before:" << prev[i] << endl;
		prev[i] += " " + word;
		cout << "after:" << prev[i] << endl;
	}
	cout << "---------------" << endl;
	return prev;
}
/*
int main() {
	string s = "catsanddog";
	vector<string> wordDict = {"cat","cats","and","sand","dog"};
	wordBreakDict(s, wordDict);
	return 0;
}*/
