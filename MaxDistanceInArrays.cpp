#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
/*624. Maximum Distance in Arrays
 * https://www.cnblogs.com/grandyang/p/7073343.html
 * Given  m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers  a and  b to be their absolute difference  |a-b|. Your task is to find the maximum distance.

Example 1:

Input:
[[1,2,3],
 [4,5],
 [1,2,3]]
Output: 4
Explanation:
One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
 */
// O(n)
int maxDistanceInArrays(vector<vector<int>>& arrays) {
	if(arrays.empty() || arrays[0].size() == 0) return -1;
	int result = 0, start = arrays[0][0], end = arrays[0].back();

	for(int i = 0; i < arrays.size(); i++) {
		result = max(result, max(abs(arrays[i].back() - start), abs(arrays[i][0] - end)));
		start = min(start, arrays[i][0]);
		end = max(end, arrays[i].back());
	}
	return result;
}
/*
int main() {
	vector<vector<int>> arrays;
	vector<int> arr1; arr1.push_back(1);arr1.push_back(2);arr1.push_back(3);
	vector<int> arr2; arr2.push_back(4);arr2.push_back(5);
	vector<int> arr3; arr3.push_back(1);arr3.push_back(2);arr3.push_back(3);
	arrays.push_back(arr1); arrays.push_back(arr2); arrays.push_back(arr3);

	cout << maxDistanceInArrays(arrays) << endl;
	return 0;
}
*/
