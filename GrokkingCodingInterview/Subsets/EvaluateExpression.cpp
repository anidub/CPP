#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/N0Q3PKRKMPz
 * https://leetcode.com/problems/different-ways-to-add-parentheses/
 *Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.
 *Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0
(2-(1-1)) = 2
 *
 *https://leetcode.com/problems/different-ways-to-add-parentheses/discuss/66331/C%2B%2B-4ms-Recursive-and-DP-solution-with-brief-explanation
 */
class EvaluateExpression {
public:
	//TC: O(N * 2^N), SC: O(2^N)
	vector<int> diffWaysToEvaluateExpression(const string& input) {
		if(input.empty()) return {};
		/*vector<int> result;
		int size = input.size();

		for(int i = 0; i < size; i++) {
			char cur = input[i];
			if(cur == '+' || cur == '-' || cur == '*') {
				vector<int> result1 = diffWaysToEvaluateExpression(input.substr(0, i));
				vector<int> result2 = diffWaysToEvaluateExpression(input.substr(i + 1));

				for(int n1 : result1) {
					for(int n2 : result2) {
						if(cur == '+')
							result.push_back(n1 + n2);
						else if(cur == '-')
							result.push_back(n1 - n2);
						else
							result.push_back(n1 * n2);
					}
				}
			}
		}
		if(result.empty())
			result.push_back(atoi(input.c_str()));

		return result;*/
		vector<int> result;
		int size = input.size();
		for(int i = 0; i < size; i++) {
			char cur = input[i];
			if(cur == '+' || cur == '-' || cur == '*') {
				vector<int> result1 = diffWaysToEvaluateExpression(input.substr(0, i));
				vector<int> result2 = diffWaysToEvaluateExpression(input.substr(i + 1));
				for(int n1 : result1) {
					for(int n2 : result2) {
						if(cur == '+') result.push_back(n1 + n2);
						else if(cur == '-') result.push_back(n1 - n2);
						else if(cur == '*') result.push_back(n1 * n2);
					}
				}
			}

		}
		if(result.empty()) result.push_back(atoi(input.c_str()));
		return result;
	}

	//USED !! understand above as its same but with memo
	//TC: O(N * 2^N), SC: O(2^N)
	vector<int> diffWaysToEvaluateExpressionmemo(const string& input) {
	//	unordered_map<string, vector<int>> memo;
	//	return diffWaysToEvaluateExpressionMEMO(input, memo);
		unordered_map<string, vector<int>> memo;
		diffWaysToEvaluateExpressionMEMO(memo, input);
	}

	vector<int> diffWaysToEvaluateExpressionMEMO(const string& input, unordered_map<string, vector<int>> &memo) {
		if(input.empty()) return {};
		vector<int> result;

		int size = input.size();

		for(int i = 0; i < size; i++) {
			char cur = input[i];
			if(cur == '+' || cur == '-' || cur == '*') {
				vector<int> result1;
				vector<int> result2;
				string substring = input.substr(0, i);
				if(memo.find(substring) != memo.end()) {
					result1 = memo[substring];
				} else
					 result1 = diffWaysToEvaluateExpressionMEMO(substring, memo);

				substring = input.substr(i + 1);
				if(memo.find(substring) != memo.end()) {
					result2 = memo[substring];
				} else
					 result2 = diffWaysToEvaluateExpressionMEMO(substring, memo);

				for(int n1 : result1) {
					for(int n2 : result2) {
						if(cur == '+')
							result.push_back(n1 + n2);
						else if(cur == '-')
							result.push_back(n1 - n2);
						else
							result.push_back(n1 * n2);
					}
				}
			}
		}
		if(result.empty())
			result.push_back(atoi(input.c_str()));

		memo[input] = result;
		return result;
	}
};

/*
int main(int argc, char* argv[]) {
	EvaluateExpression ee;
  vector<int> result = ee.diffWaysToEvaluateExpression("1+2*3");
  cout << "Expression evaluations: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = ee.diffWaysToEvaluateExpressionmemo("1+2*3");
    cout << "Expression evaluations: ";
    for (auto num : result) {
      cout << num << " ";
    }
    cout << endl;

  result = ee.diffWaysToEvaluateExpression("2*3-4-5");
  cout << "Expression evaluations: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = ee.diffWaysToEvaluateExpressionmemo("2*3-4-5");
    cout << "Expression evaluations: ";
    for (auto num : result) {
      cout << num << " ";
    }
    cout << endl;
}
*/
