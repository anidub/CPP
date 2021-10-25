#include <iostream>
#include <vector>

using namespace std;
/*
 * https://leetcode.jp/problemdetail.php?id=1708
 * https://www.geeksforgeeks.org/greatest-contiguous-sub-array-of-size-k/
 * An array A is larger than some array B if for the first index i where A[i] != B[i], A[i] > B[i].

For example, consider 0-indexing:

[1,3,2,4] > [1,2,2,4], since at index 1, 3 > 2.
[1,4,4,4] < [2,1,1,1], since at index 0, 1 < 2.
A subarray is a contiguous subsequence of the array.

Given an integer array nums of distinct integers, return the largest subarray of nums of length k.

Example 1:
Input: nums = [1,4,5,2,3], k = 3
Output: [5,2,3]
Explanation: The subarrays of size 3 are: [1,4,5], [4,5,2], and [5,2,3].
Of these, [5,2,3] is the largest.
Input: nums = [1,4,5,2,3], k = 4
Output: [4,5,2,3]
Explanation: The subarrays of size 4 are: [1,4,5,2], and [4,5,2,3].
Of these, [4,5,2,3] is the largest.
Input: nums = [1,4,5,2,3], k = 1
Output: [5]
https://github.com/fishercoder1534/Leetcode/blob/master/src/main/java/com/fishercoder/solutions/_1708.java
 */

vector<int> getLargestSubarray(vector<int> arr, int k) {
	if(arr.size() == 0) return arr;
	vector<int> result;
	int max_value = arr[0];
	int begin_index = 0;
	for(int i = 0; i < arr.size() - k; i++) {
		if(max_value < arr[i]) {
			max_value = arr[i];
			begin_index = i;
		}
	}

	while(k > 0) {
		result.push_back(arr[begin_index]);
		begin_index++;
		k--;
	}
	for(int i : result)
		cout << i << " ";
	return result;
}
/*

int main() {
    vector<int> arr;//1, 9, 2, 7, 9, 3}
    arr.push_back(1);arr.push_back(9);arr.push_back(2);arr.push_back(7);arr.push_back(9);
    arr.push_back(3);
    getLargestSubarray(arr,3);
	return 0;
}*/
