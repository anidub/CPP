#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <sstream>

using namespace std;
/*https://leetcode.com/problems/intersection-of-three-sorted-arrays/
 * Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order, return a sorted array of only the integers that appeared in all three arrays.
 * Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
Output: [1,5]
Explanation: Only 1 and 5 appeared in the three arrays.
https://leetcode.com/problems/intersection-of-three-sorted-arrays/discuss/398081/C%2B%2B-super-simple-and-easy-O(n)-time-O(1)-space-9-line-solution-beats-100-time-and-100-space!
 */
//TC: O(n) SC: O(1)
vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
	int p1 = 0, p2 = 0, p3 = 0;
	vector<int> res;

	while(p1 < arr1.size() && p2 < arr2.size() && p3 < arr3.size()) {
		if(arr1[p1] == arr2[p2] && arr2[p2] == arr3[p3]) res.push_back(arr1[p1]);
		int m = min(arr1[p1], min(arr2[p2], arr3[p3]));
		if(arr1[p1] == m) p1++;
		if(arr2[p2] == m) p2++;
		if(arr3[p3] == m) p3++;
	}
	return res;
}
/*
int main() {
	vector<int> arr1 = {1,2,3,4,5};
	vector<int> arr2 = {1,2,5,7,9};
	vector<int> arr3 = {1,3,4,5,8};
	arraysIntersection(arr1, arr2, arr3);

	return 0;
}*/
