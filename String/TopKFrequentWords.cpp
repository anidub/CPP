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
/*https://leetcode.com/problems/top-k-frequent-words/
 * Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical orde
Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
https://leetcode.com/problems/top-k-frequent-words/discuss/112651/Simple-C%2B%2B-solutions
 */

struct Comp{
	bool operator()(const pair<int, string>& lhs, const pair<int, string>& rhs) const {
		if(lhs.first != rhs.first)
			return lhs.first < rhs.first;
		return lhs.second > rhs.second;
	}
};

vector<string> topKFrequentWords(vector<string>& words, int k) {
	if(words.empty()) return {};
	unordered_map<string, int> cnt;
	for(auto& w : words)
		cnt[w]++;

	priority_queue<pair<int, string>, vector<pair<int, string>>, Comp> Q;
	for(auto& it : cnt) {
		Q.emplace(it.second, it.first);
	}
	vector<string> res;
	while(k-- > 0 && !Q.empty()) {
		res.push_back(Q.top().second);
		Q.pop();
	}
	return res;
}

/*
int main() {
	vector<string> words = {"i","love","leetcode","i","love","coding"};
	topKFrequentWords(words, 2);

	return 0;
}*/
