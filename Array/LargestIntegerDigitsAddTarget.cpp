#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
 * Given an array of integers cost and an integer target. Return the maximum integer you can paint under the following rules:
The cost of painting a digit (i+1) is given by cost[i] (0 indexed).
The total cost used must be equal to target.
Integer does not have digits 0.
Since the answer may be too large, return it as string.
If there is no way to paint any integer given the condition, return "0".
Example 1:

Input: cost = [4,3,2,5,6,7,2,5,5], target = 9
Output: "7772"
Explanation:  The cost to paint the digit '7' is 2, and the digit '2' is 3. Then cost("7772") = 2*3+ 3*1 = 9. You could also paint "977", but "7772" is the largest number.
Digit    cost
  1  ->   4
  2  ->   3
  3  ->   2
  4  ->   5
  5  ->   6
  6  ->   7
  7  ->   2
  8  ->   5
  9  ->   5
  https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/discuss/635190/C%2B%2B-Top-Down-greater-Bottom-Up-greater-O(n)
 */
string dpLargestNumberAddTarget[5001] = {};
// TC:O(n ^ 2)
string largestNumberAddTarget(vector<int>& cost, int t){
	if(t <= 0)
		return t == 0 ? "" : "0";
	if(dpLargestNumberAddTarget[t].empty()) {
		dpLargestNumberAddTarget[t] = "0";
		for(int i = 1; i <= 9; i++) {
			auto res = largestNumberAddTarget(cost, t - cost[i-1]);
			if(res != "0" && res.size() + 1 >= dpLargestNumberAddTarget[t].size())
				dpLargestNumberAddTarget[t] = to_string(i) + res;
		}
	}
	return dpLargestNumberAddTarget[t];
}
/*
int main() {
	vector<int> cost;
	cost.push_back(4);cost.push_back(3);cost.push_back(2);
	cost.push_back(5);cost.push_back(6);cost.push_back(7);
	cost.push_back(2);cost.push_back(5);cost.push_back(5);
	cout << largestNumberAddTarget(cost, 9) << endl;

	return 0;
}
*/
