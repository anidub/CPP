#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_map>

using namespace std;
/*https://leetcode.com/problems/search-suggestions-system/
 * You are given an array of strings products and a string searchWord.
Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.
Return a list of lists of the suggested products after each character of searchWord is typed.
Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]

https://leetcode.com/problems/search-suggestions-system/discuss/436126/C%2B%2B-Easy-sort-(No-trie)-O(1)-Space : comments
 */
vector<vector<string>> searchSuggestionSystem(vector<string>& products, string& searchWord) {
	if(products.empty() || searchWord.empty()) return {};
	vector<vector<string>> result;

	sort(products.begin(), products.end());
	auto it = products.begin();
	string cur = "";

	for(char c : searchWord) {
		cur += c;
		vector<string> suggestions;
		it = lower_bound(it, products.end(), cur);
		for(int i = 0; i < 3; i++) {
			if(it+i == products.end()) break;
			string& str = *(it + i);
			if(cur != str.substr(0, cur.size())) break;
			suggestions.push_back(str);
		}
		result.push_back(suggestions);
	}
	return result;
}
/*
int main() {
	vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
	string searchWord = "mouse";
	searchSuggestionSystem(products, searchWord);


	return 0;
}*/
