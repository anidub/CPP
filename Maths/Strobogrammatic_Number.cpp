#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/strobogrammatic-number/
 * Given a string num which represents an integer, return true if num is a strobogrammatic number.

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Input: num = "69"
Output: true
Input: num = "962"
Output: false

https://leetcode.com/problems/strobogrammatic-number/discuss/67207/C%2B%2B-unordered_map : comments
 */

//TC: O(1), SC: O(1) since constant space
bool isStrobogrammatic(string num) {
	unordered_map<char, char> mp = {{'0', '0'}, {'1','1'}, {'8','8'}, {'6','9'}, {'9','6'}};
	int left = 0, right = num.size() - 1;

	while(left <= right) {
		if(mp[num[left++]] != num[right--]) return false;
	}
	return true;
}
/*
int main() {
	cout << isStrobogrammatic("69") << endl;

	return 0;
}*/
