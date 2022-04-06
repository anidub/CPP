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
/*https://leetcode.com/problems/custom-sort-string/
 * You are given two strings order and s. All the words of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.
Input: order = "cba", s = "abcd"
Output: "cbad"
Explanation:
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
https://leetcode.com/problems/custom-sort-string/discuss/1336524/C%2B%2BPython-Counting-Sort-Clean-and-Concise-O(N) : used
https://leetcode.com/problems/custom-sort-string/discuss/1336619/C%2B%2B-Simple-and-Short-Solution-Using-Custom-Sorting-5-Lines-of-Code

 */
//Time: O(N), where N is the length of string str, Space : O(1)
string customSort(string order, string str) {
	if(order.empty()) return str;
	if(str.empty()) return "";

	int cnt[128] = {};

	for(char c : str)
		cnt[c]++;

	int i = 0;
	for(char c : order) {
		while(cnt[c] > 0) {
			str[i++] = c;
			cnt[c]--;
		}
	}
	for(char c = 'a'; c <= 'z'; c++) {//for(i = 65; i <= 122; i++) for caps on and off
		while(cnt[c] > 0) {
			str[i++] = c;
			cnt[c]--;
		}
	}
	return str;
}

static string m_order;
static bool compareCustomSort(char a, char b) {
	return m_order.find(a) < m_order.find(b);
}

string customSortString(string order, string str) {
	m_order = order;
	sort(str.begin(), str.end(), compareCustomSort);

	return str;
}
/*
int main() {
	cout << customSort("cba", "abcd") << endl;
	cout << customSortString("cba", "abcd") << endl;

	return 0;
}*/
