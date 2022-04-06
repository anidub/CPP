#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <utility>
#include <string.h>

using namespace std;
/*https://leetcode.com/problems/shortest-way-to-form-string/
 * A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Given two strings source and target, return the minimum number of subsequences of source such that their concatenation equals target. If the task is impossible, return -1.

 *Input: source = "abc", target = "abcbc"
Output: 2
Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".

 * https://www.youtube.com/watch?v=OSZovOH9w44 : explained
 * https://unofficial-sendoh.gitbook.io/unofficialsendoh/c/l/leetcode1055 : used
 */

// time: : O(n log m), where n and m are sizes of the source and target. space: O(m)to store indexes for target.
int shortestWayFormString(string source, string target) {
	if(target.empty()) return 0;

	unordered_map<char, vector<int>> char_to_index;
	for(int i = 0; i < source.length(); i++)
		char_to_index[source[i]].push_back(i);

	int source_ptr = -1;
	int target_index = 0;
	int target_len = target.size();
	int copy_needed = 1;

	while(target_index < target_len) {
		char cur_element = target[target_index];

		if(!char_to_index.count(cur_element)) return -1;

		auto search_range = char_to_index[cur_element];
		auto it = upper_bound(search_range.begin(), search_range.end(), source_ptr);

		if(it == search_range.end()) {
			copy_needed++;
			source_ptr = -1;
		} else {
			source_ptr = *it;
			target_index++;
		}
	}
	return copy_needed;
}

//https://jimmylin1991.gitbook.io/practice-of-algorithm-problems/greedy/1055.-shortest-way-to-form-string
//// time: O(n * m); space: O(1)
int shortestWayFormStringBrute(string source, string target)  {
	 // i: position in target string; j: position in source string
	int i = 0, res = 0;

	while(i < target.size()) {
		int orig_idx = i;
		for(int j = 0; j < source.size(); j++) {
			if(target[i] == source[j])
				i++;
		}
		if(i == orig_idx) return -1;
		res++;
	}
	return res;
}
/*
int main() {
	cout << shortestWayFormString("abc", "abcbc") << endl;
	cout << shortestWayFormStringBrute("abc", "abcbc") << endl;

	return 0;
}*/
