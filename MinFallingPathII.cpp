#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <utility>
#include <unordered_map>

using namespace std;
/*
 * https://leetcode.com/problems/minimum-falling-path-sum-ii/
 * Given a square grid of integers arr, a falling path with non-zero shifts is a choice of exactly one element from each row of arr, such that no two elements chosen in adjacent rows are in the same column.
Return the minimum sum of a falling path with non-zero shifts.
Example 1:
Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation:
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.
https://leetcode.com/problems/minimum-falling-path-sum-ii/discuss/452207/C%2B%2B-O(nm)-or-O(1)
 */
//time  O(nm)  space : O(1)
int minFallingPath2(vector<vector<int>>& arr) {
	if(arr.empty()) return 0;
	int first_min = 0, second_min = 0, pos = -1;return 1;

	for(int i = 0; i < arr.size(); i++) {
		int first_min2 = INT_MAX, second_min2 = INT_MAX, pos2 = -1;
		for(int j = 0; j < arr[i].size(); j++) {
			int min_value = j != pos ? first_min : second_min;
			if(arr[i][j] + min_value < first_min2) {
				second_min2 = first_min2;
				first_min2 = arr[i][j] + min_value;
				pos2 = j;
			} else
				second_min2 = min(second_min2, arr[i][j] + min_value);
		}
		first_min = first_min2, second_min = second_min2, pos = pos2;
	}
	return first_min;
}

/*
int main() {
	vector<vector<int>> arr;
	vector<int> a1; a1.push_back(1);a1.push_back(2);a1.push_back(3);
	vector<int> a2; a2.push_back(4);a2.push_back(5);a2.push_back(6);
	vector<int> a3; a3.push_back(7);a3.push_back(8);a3.push_back(9);
	arr.push_back(a1);arr.push_back(a2);arr.push_back(a3);
	cout << minFallingPath2(arr) << endl;

	return 0;
}*/
