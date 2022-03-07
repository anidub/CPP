#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <utility>

using namespace std;
/*
 * https://www.cnblogs.com/grandyang/p/5628786.html
 * Assume you have an array of length n initialized with all 0 's and are given k update operations.
Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc .
Return the modified array after all k operations were executed.
Example:
Given:
    length = 5,
    updates = [
        [1, 3, 2],
        [2, 4, 3],
        [0, 2, -2]
    ]
Output:
    [-2, 0, 3, 5, 3]

 Initial state:
[0, 0, 0, 0, 0]

After applying operation [1, 3, 2]:
[0, 2, 2, 2, 0]

After applying operation [2, 4, 3]:
[0, 2, 5, 5, 3]

After applying operation [0, 2, -2]:
[-2, 0, 3, 5, 3]
 *
 * https://baihuqian.github.io/2018-08-16-range-addition/
 */

vector<int> getModifiedArray(vector<vector< int >>& updates, int length) {
	vector<int> arr(length, 0);
	for(int i = 0; i < updates.size(); i++) {
		int start = updates[i][0];
		int end = updates[i][1];
		int inc = updates[i][2];

		arr[start] += inc;
		if(end + 1 < length)
			arr[end+1] -= inc;
	}

	for(int i = 1; i < arr.size(); i++) {
		arr[i] += arr[i-1];
	}

	for(int i : arr) {
		cout << i << " ";
	}
	return arr;
}
/*https://leetcode.com/problems/range-addition/
 * You are given an integer length and an array updates where updates[i] = [startIdxi, endIdxi, inci].
 * Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
Output: [-2,0,3,5,3]
https://leetcode.com/problems/range-addition/discuss/84225/Detailed-explanation-if-you-don't-understand-especially-%22put-negative-inc-at-endIndex%2B1%22
 well explained above
 Put inc at startIndex allows the inc to be carried to the next index starting from startIndex when we do the sum accumulation.
Put -inc at endIndex + 1 simply means cancel out the previous carry from the next index of the endIndex, because the previous carry should not be counted beyond endIndex.
 */
//tc: o(N)
vector<int> getModifiedArraySimple(int length, vector<vector<int>>& updates) {
	vector<int> res(length + 1, 0);

	for(auto& e : updates) {
		int start = e[0], end = e[1], val = e[2];
		res[start] += val;
		res[end + 1] -= val;
	}
	for(int i = 1; i < length; i++) {
		res[i] += res[i-1];
	}
	res.pop_back();
	return res;
}
/*
int main() {
	vector<vector<int>> updates;
	vector<int> nums;
	nums.push_back(1);nums.push_back(3);nums.push_back(2);
	vector<int> nums1;
	nums1.push_back(2);nums1.push_back(4);nums1.push_back(3);
	vector<int> nums2;
	nums2.push_back(0);nums2.push_back(2);nums2.push_back(-2);
	updates.push_back(nums);updates.push_back(nums1);updates.push_back(nums2);

	getModifiedArray(updates, 5);
	return 0;
}*/

