#include <iostream>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
/*https://leetcode.com/problems/unique-binary-search-trees/
 * Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
 * Input: n = 3
Output: 5

https://leetcode.com/problems/unique-binary-search-trees/solution/ : read for explanantion

 */

int uniqueNumberOfBSTs(int n)  {
	vector<int> count(n+1);
	count[0] = 1;
	count[1] = 1;

	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			count[i] += count[j-1] * count[i-j];
		}
	}
	return count[n];
}
/*
int main() {
	cout << uniqueNumberOfBSTs(3) << endl;

	return 0;
}*/
