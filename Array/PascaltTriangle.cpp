#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;

/*
 * https://leetcode.com/problems/pascals-triangle/
 * Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
 * Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

https://leetcode.com/problems/pascals-triangle/discuss/38150/My-C%2B%2B-code-0ms
 */

vector<vector<int>> generatePascals(int numrows) {
	vector<vector<int>> result;
	if(numrows == 0) return result;

	for(int i = 0; i < numrows; i++) {
		result.push_back(vector<int>(i+1, 1));
		for(int j = 1; j < i; j++) {
			result[i][j] = result[i-1][j-1] + result[i-1][j];
		}
	}
	return result;
}
/*
int main() {
	generatePascals(5);

	return 0;
}*/
