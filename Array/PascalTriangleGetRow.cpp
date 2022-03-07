#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * https://leetcode.com/problems/pascals-triangle-ii/
 * Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
https://leetcode.com/problems/pascals-triangle-ii/discuss/38560/C%2B%2B-implementation
 */

vector<int> getRow(int rowIndex) {
	vector<int> result(rowIndex + 1, 0);
	result[0] = 1;

	for(int i = 1; i <= rowIndex; i++) {
		for(int j = i; j >= 1; j--) {
			result[j] = result[j] + result[j-1];
		}
	}
	for(int i : result)
		cout << i << " ";
	return result;
}
/*
int main() {
	getRow(3);
	return 0;
}*/
