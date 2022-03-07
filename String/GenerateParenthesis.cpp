#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>

using namespace std;

/*https://leetcode.com/problems/generate-parentheses/
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
https://leetcode.com/problems/generate-parentheses/discuss/10105/Concise-recursive-C%2B%2B-solution
 */

void generateParenthesisHelper(vector<string>& result, string str, int left, int right);
//time complexity will be O(2 * N * # of output)
vector<string> generateParenthesis(int n) {
	vector<string> result;
	generateParenthesisHelper(result, "", n, n);
	return result;
}

void generateParenthesisHelper(vector<string>& result, string str, int left, int right) {
	if(left == 0 && right == 0) {
		result.push_back(str);
		return;
	}
	if(left > 0) generateParenthesisHelper(result, str + '(', left-1, right);
	if(right > left) generateParenthesisHelper(result, str + ')', left, right-1);
}
/*
int main() {
	generateParenthesis(5);

	return 0;
}*/
