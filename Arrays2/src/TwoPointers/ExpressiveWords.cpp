#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/expressive-words/
 * Sometimes people repeat letters to represent extra feeling. For example:

"hello" -> "heeellooo"
"hi" -> "hiiii"
In these strings like "heeellooo", we have groups of adjacent letters that are all the same: "h", "eee", "ll", "ooo".

You are given a string s and an array of query strings words. A query word is stretchy if it can be made to be equal to s by any number of applications of the following extension operation: choose a group consisting of characters c, and add some number of characters c to the group so that the size of the group is three or more.

For example, starting with "hello", we could do an extension on the group "o" to get "hellooo", but we cannot get "helloo" since the group "oo" has a size less than three. Also, we could do another extension like "ll" -> "lllll" to get "helllllooo". If s = "helllllooo", then the query word "hello" would be stretchy because of these two extension operations: query = "hello" -> "hellooo" -> "helllllooo" = s.
Return the number of query strings that are stretchy.
Input: s = "heeellooo", words = ["hello", "hi", "helo"]
Output: 1
Explanation:
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not size 3 or more.

https://leetcode.com/problems/expressive-words/discuss/122660/C%2B%2BJavaPython-2-Pointers-and-4-pointers
https://leetcode.com/problems/expressive-words/discuss/287113/Hope-my-explanation-can-help-a-little-bit-in-understanding-what-the-question-means
 */
bool checkExpressiveWords(string &s, string &w);

//Time Complexity: O(n*max(len(s), max(len(word in words array)))) where n is the length of words array
//Space Complexity: O(1)
int expressiveWords(string S, vector<string> &words) {
	int res = 0;
	for(auto &W : words) {
		if(checkExpressiveWords(S, W)) res++;
	}
	return res;
}

bool checkExpressiveWords(string &s, string &w) {
	int n = s.length(), m = w.length(), j = 0;

	for(int i = 0; i < n; i++) {
		if(j < m && s[i] == w[j]) j++;
		else if(i > 0 && i < n - 1 && s[i] == s[i-1] && s[i] == s[i+1]);
		else if(i > 1 && s[i] == s[i-1] && s[i] == s[i-2]);
		else return false;
	}
	return j == m;
}
/*
int main() {
	string s = "heeellooo";
	vector<string> words = {"hello", "hi", "helo"};
	cout << expressiveWords(s, words) << endl;

	return 0;
}*/
