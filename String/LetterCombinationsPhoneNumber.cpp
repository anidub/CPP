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
/*https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
https://leetcode.com/problems/letter-combinations-of-a-phone-number/discuss/1148252/Short-and-Easy-Solutions-or-Multiple-Approaches-Explained-or-Beats-100

 */

vector<string> mappings = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;

//Time Complexity : O(4^N*N), where N, is the length of input string. 4^N for building every possible string combination and N to form the string by joining each character.. Here, 4 is chosen assuming the worst case where each digit will be 7 or 9 and we would have 4*4*4*4 total string combinations.
//Space Complexity : O(N) : for stack
void letterCombinationsBacktracking(string& digits, int i, string& combi);
vector<string> letterCombinations(string digits) {
	if(digits == "") return ans;
	string combination = "";
	letterCombinationsBacktracking(digits, 0, combination);
	return ans;
}

void letterCombinationsBacktracking(string& digits, int i, string& combi) {
	if(i == digits.size()) {
		ans.push_back(combi);
		return;
	}
	for(auto c : mappings[digits[i] - '0']) {
		combi.push_back(c);
		letterCombinationsBacktracking(digits, i+1, combi);
		combi.pop_back();
	}
}
/*
int main() {
	letterCombinations("23");

	return 0;
}
*/
