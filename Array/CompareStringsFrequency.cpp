#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <map>
#include <utility>

using namespace std;
/*
 * https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/discuss/386386/C%2B%2B-O(n)
 * Let the function f(s) be the frequency of the lexicographically smallest character in a non-empty string s. For example, if s = "dcce" then f(s) = 2 because the lexicographically smallest character is 'c', which has a frequency of 2.
You are given an array of strings words and another array of query strings queries. For each query queries[i], count the number of words in words such that f(queries[i]) < f(W) for each W in words.
Return an integer array answer, where each answer[i] is the answer to the ith query.
Example 1:

Input: queries = ["cbd"], words = ["zaaaz"]
Output: [1]
Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").
Example 2:

Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
Output: [1,2]
Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").

https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/discuss/775788/c%2B%2B-map-solution
https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/discuss/386386/C%2B%2B-O(n)
 *
 */
int getFrequencySmalled(string& s){
	if(s.empty()) return 0;
	int i = 1;
	sort(s.begin(), s.end());
	for(;i < s.size(); i++) {
		if(s[i] != s[i-1])
			return i;
	}
	return i;
}

vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
	if(queries.empty() || words.empty()) return {};
	map<int, int> map;

	for(string& s: words)
		map[getFrequencySmalled(s)]++;

	vector<int> result;
	for(string& s : queries) {
		int curCount = 0;
		for(auto iter = map.upper_bound(getFrequencySmalled(s)); iter != map.end(); iter++) {
			curCount += iter->second;
		}
		result.push_back(curCount);
	}
	return result;
}
vector<int> numSmallerByFrequencyOptimal(vector<string>& queries, vector<string>& words) {
	if(queries.empty() || words.empty()) return {};

	auto freq = [](string& s){
		return count(begin(s), end(s), *min_element(begin(s), end(s)));
	};

	vector<int> count(11, 0); //words[i].length <= 10

	for(string& s: words) {
		for(int i = freq(s) - 1; i >= 0; i--)
		count[i]++;
	}

	vector<int> result;
	for(auto& q: queries) {
		result.push_back(count[freq(q)]);
	}
	return result;
}

/*
int main() {

	return 0;
}*/
