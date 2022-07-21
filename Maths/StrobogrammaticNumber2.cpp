#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <utility>
#include <map>
#include <set>

using namespace std;
/*https://leetcode.com/problems/strobogrammatic-number-ii/
 * Given an integer n, return all the strobogrammatic numbers that are of length n. You may return the answer in any order.

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Input: n = 2
Output: ["11","69","88","96"]

https://leetcode.com/problems/strobogrammatic-number-ii/solution/
 */
vector<string>  generateStrobogrammaticNums(int n, int finalLength);

vector<vector<char>> reversiblePairs = { {'0','0'}, {'1', '1'}, {'6','9'}, {'9', '6'}, {'8','8'} };

vector<string> findStrobogrammatic(int n) {
	return generateStrobogrammaticNums(n, n);
}
//TC: N 5^(N/2)+1, SC :  N 5^(N/2) explained in solutions
vector<string>  generateStrobogrammaticNums(int n, int finalLength) {
	if(n == 0) return { "" };// 0-digit strobogrammatic number is an empty string.
	if(n == 1) return {"0", "1", "8"}; // 1-digit strobogrammatic numbers.

	vector<string> prevStroboNums = generateStrobogrammaticNums(n-2, finalLength);
	vector<string> curStroboNums;

	for(string &prevStr : prevStroboNums) {
		for(vector<char> &pair : reversiblePairs) {
			if(pair[0] != '0' || n != finalLength)// We can only append 0's if it is not first digit.
				curStroboNums.push_back(pair[0] + prevStr + pair[1]);
		}
	}
	return curStroboNums;
}
/*
int main() {
	findStrobogrammatic(2);

	return 0;
}*/
