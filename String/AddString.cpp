#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <string.h>
#include <unordered_map>
#include <queue>

using namespace std;
/*https://leetcode.com/problems/add-strings/
 * Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.
Input: num1 = "11", num2 = "123"
Output: "134"
https://leetcode.com/problems/add-strings/discuss/90453/C%2B%2B_Accepted_13ms
 */
//Time :O(N)
string addString(string num1, string num2) {
	int i = num1.size() - 1, j = num2.size() - 1;
	string res = "";
	int carry = 0;

	while(i >= 0 || j >= 0 || carry) {
		long sum = 0;
		if(i >= 0) {
			sum += (num1[i] - '0');
			i--;
		}
		if(j >= 0) {
			sum += (num2[j] - '0');
			j--;
		}
		sum += carry;
		carry = sum / 10;
		sum = sum % 10;
		res += to_string(sum);
	}
	reverse(res.begin(), res.end());
	return res;
}
/*
int main() {
	cout << addString("11", "111") << endl;
	return 0;
}*/
