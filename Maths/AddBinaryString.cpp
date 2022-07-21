#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

/*https://leetcode.com/problems/add-binary/
 * Given two binary strings a and b, return their sum as a binary string.
 * Input: a = "11", b = "1"
Output: "100"
https://leetcode.com/problems/add-binary/discuss/1680021/Very-simple-O(n)-C%2B%2B-solution

Important point to note: (Reference - http://codeforces.com/blog/entry/66660)

a = a + "xy" is O(N) while a += "xy" is O(1) (amortized).

a = a + "xy" creates a copy of a, appends "xy" and then assigns it back to a.

a += "xy" just appends "xy" to a.

Therefore the time complexity of this approach is O(n).
 */
//TC: O(N)
string addTwoBinaryStrings(string a, string b) {
	int i = a.length() - 1, j = b.length() - 1;
	string ans;
	int carry = 0;

	while(i >= 0 || j >= 0 || carry) {
		if(i >= 0) {
			carry += a[i] - '0';
			i--;
		}

		if(j >= 0) {
			carry += b[j] - '0';
			j--;
		}
		ans += (carry % 2 + '0');
		carry = carry / 2;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
/*
int main() {
	cout << addTwoBinaryStrings("11", "1") << endl;

	return 0;
}*/
