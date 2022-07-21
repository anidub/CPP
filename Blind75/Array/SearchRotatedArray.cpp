#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
/*https://leetcode.com/problems/search-in-rotated-sorted-array/
 * There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
 */
class SearchRotatedArray {
public:
	//TC:O(LOGN), SC:O(1)
	int search(vector<int>& arr, int key) {
		if(arr.empty()) return -1;
		int start = 0, end = arr.size() - 1;

		while(start <= end) {
			int mid = start + (end - start) / 2;
			if(arr[mid] == key) return mid;
			if(arr[start] <= arr[mid]) {
				if(key < arr[mid] && key >= arr[start])
					end = mid - 1;
				else
					start = mid + 1;
			} else {
				if(key > arr[mid] && key <= arr[end])
					start = mid + 1;
				else
					end = mid - 1;
			}
		}
		return -1;
	}
};

/*
int main() {
	SearchRotatedArray sra;
	vector<int> arr = {4,5,6,7,0,1,2};
	cout << sra.search(arr, 0) << endl;
}*/
