#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_map>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/reorder-data-in-log-files/
 * You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

There are two types of logs:

Letter-logs: All words (except the identifier) consist of lowercase English letters.
Digit-logs: All words (except the identifier) consist of digits.
Reorder these logs so that:

The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
The digit-logs maintain their relative ordering.
Return the final order of the logs.
Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
Explanation:
The letter-log contents are all different, so their ordering is "art can", "art zero", "own kit dig".
The digit-logs have a relative order of "dig1 8 1 5 1", "dig2 3 6".
https://leetcode.com/problems/reorder-data-in-log-files/discuss/192438/C%2B%2B-O(NlogN)-Time-O(N)-Space
 */
//Time: O(NlogN), Space:O(N)
vector<string> reorderLogFiles(vector<string>& logs) {
	if(logs.empty()) return {};

	vector<string> digitLogs, ans;
	vector<pair<string, string>> letterLogs;

	for(string& s : logs) {
		int i = 0;
		while(s[i] != ' ') i++;

		if(isalpha(s[i+1])) {
			letterLogs.emplace_back(s.substr(0,i) , s.substr(i+1));
		} else
			digitLogs.push_back(s);
	}

	sort(letterLogs.begin(), letterLogs.end(), [&](auto& a, auto& b) {
		return a.second == b.second ? a.first < b.first : a.second < b.second;
	});

	for(auto& p : letterLogs)
		ans.push_back(p.first + " " + p.second);

	for(string& s : digitLogs) ans.push_back(s);

	return ans;
}
/*
int main() {
	vector<string> logs = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
	reorderLogFiles(logs);

	return 0;
}
*/
