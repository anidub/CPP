#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_set>

using namespace std;
/*https://leetcode.com/problems/remove-invalid-parentheses/
 * Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return all the possible results. You may return the answer in any order.

 Input: s = "()())()"
Output: ["(())()","()()()"]
https://leetcode.com/problems/remove-invalid-parentheses/discuss/75048/recommend-for-beginnersclean-C%2B%2B-implementation-with-detailed-explaination
 */
//TC: O(2^N) since in the worst case we will have only left parentheses in the expression and for every bracket we will have two options i.e. whether to remove it or consider it.
//SC: O(N): stack space
void helperRemoveInvalidParenthsisDFS(int pair, int index, int left_removal, int right_removal, const string &s, string solution, unordered_set<string> &result);
vector<string> removeInvalidParenthsis(string s) {
	if(s.empty()) return {};
	unordered_set<string> result;
	int left_removal = 0, right_removal = 0;
	/***  calculate the remained # of left and right parentheses  ***/
	for(char &c : s) {
		if(c == '(') left_removal++;
		else if(c == ')')
			if(left_removal > 0)
				left_removal--;
			else
				right_removal++;
	}

	helperRemoveInvalidParenthsisDFS(0, 0, left_removal, right_removal, s, "", result);
	return vector<string>(result.begin(), result.end());

}
/***
pair : record the () pair count in the solution
index : record the cur-position int the string s
remove_left : the number of left parentheses needed to delete
remove_right : the number of right parentheses needed to delete
s : origninal input string    solution : the current produced string
result : stores all the satisfied solution string
***/
void helperRemoveInvalidParenthsisDFS(int pair, int index, int left_removal, int right_removal, const string &s, string solution, unordered_set<string> &result) {
	if(index == s.size()) {
		if(pair == 0 && left_removal == 0 && right_removal == 0)
			result.insert(solution);
		return;
	}

	if(s[index] == '(') {
		/***    remove the left-half-parentheses     ***/
		if(left_removal > 0) helperRemoveInvalidParenthsisDFS(pair, index + 1, left_removal - 1, right_removal, s, solution, result);
		/***    keep  the  left-half-parentheses     ***/
		helperRemoveInvalidParenthsisDFS(pair + 1, index + 1, left_removal, right_removal, s, solution + s[index], result);
	} else if(s[index] == ')') {
		 /***    remove the right-half-parentheses     ***/
		if(right_removal > 0)
			helperRemoveInvalidParenthsisDFS(pair, index + 1, left_removal, right_removal - 1, s, solution, result);
		 /***    keep  the  right-half-parentheses     ***/
		if(pair > 0)
			helperRemoveInvalidParenthsisDFS(pair - 1, index + 1, left_removal, right_removal, s, solution + s[index], result);
	} else {  /***    other-characters     ***/
		helperRemoveInvalidParenthsisDFS(pair, index + 1, left_removal, right_removal, s, solution + s[index], result);
	}
}
/*
int main() {
	removeInvalidParenthsis("()())()");

	return 0;
}*/
