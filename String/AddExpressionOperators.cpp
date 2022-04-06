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
/*https://leetcode.com/problems/expression-add-operators/
 * Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

Note that operands in the returned expressions should not contain leading zeros.
Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
https://leetcode.com/problems/expression-add-operators/discuss/572099/C%2B%2BJavaPython-Backtracking-and-Evaluate-on-the-fly-Clean-and-Concise

!!WORKS!!

 */

class ExprOperators {
public:
string s;
int target;
vector<string> exprResult;
//void backtrack(int index, const string &path, long resSoFar, long prevNum);

//TC: O(4^n). branching factor raised to the power of the height of the tree:t every step along the way, we consider exactly 4 different choices or 4 different recursive paths.
//SC: O(N): size of stack
	vector<string> addExprOperators(string s, int target){
		this->s = s;
		this->target = target;
		backtrack(0, "", 0, 0);
		return exprResult;
	}

	void backtrack(int index, const string &path, long resSoFar, long prevNum) {
		if(index == s.size()) {
			if(resSoFar == target) exprResult.push_back(path);
			return;
		}
		string numStr;
		long num = 0;
		for(int j = index; j < s.size(); j++) {
			if(j > index && s[index] == '0') continue;
			numStr += s[j];
			num = num * 10 + s[j] - '0';
			if(index == 0)
				backtrack(j+1, path + numStr, num, num);
			else {
				backtrack(j+1, path + "+" + numStr, resSoFar + num, num);
				backtrack(j+1, path + "-" + numStr, resSoFar - num, -num);
				backtrack(j+1, path + "*" + numStr, resSoFar - prevNum + prevNum * num, prevNum * num);
			}
		}
	}
};
/*
int main() {
	ExprOperators *expr = new ExprOperators();
	expr->addExprOperators("123", 6);

	return 0;
}*/
