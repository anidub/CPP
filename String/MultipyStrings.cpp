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
/*https://leetcode.com/problems/multiply-strings/
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
https://leetcode.com/problems/multiply-strings/discuss/1563507/C%2B%2B-Simple-Easy-and-Short-Solution-Brief-Explanation
 */
//Time Complexity: O(mn)
//Space Complexity: O(n+m)
string multiplyStrings(string num1, string num2) {
	if(num1.empty() && num2.empty()) return "";

	if (num1 == "0" || num2 == "0") return "0";

	vector<int> res(num1.size() + num2.size(), 0);

	for(int i = num1.size() - 1; i >= 0; i--) {
		for(int j = num2.size() - 1; j >= 0; j--) {
			res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
			res[i + j] += res[i + j + 1] / 10;
			res[i + j + 1] %= 10;
		}
	}
	int i = 0;
	string ans = "";
	while(res[i] == 0) i++;
	while(i < res.size())
		ans.push_back(res[i++] + '0');
	return ans;
}
/*
int main() {
	cout << multiplyStrings("21", "42") << endl;

	return 0;
}
*/
