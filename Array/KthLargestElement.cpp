#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <set>

using namespace std;
/*https://leetcode.com/problems/kth-largest-element-in-an-array/
 * Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

https://www.youtube.com/watch?v=BP7GCALO2v8 : to understand quick select
https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsort
 this algorithm reduces the size of the problem by approximately one half after each partition, giving the recurrence T(n) = T(n/2) + O(n) with O(n) being the time for partition. The solution is T(n) = O(n), which means we have found an average linear-time solution. However, in the worst case, the recurrence will become T(n) = T(n - 1) + O(n) and T(n) = O(n^2).
 *
 */

int partition(vector<int>& nums, int left, int right);

//TC: average:O(n), worse case : O(n^2)
int kthLargestElement(vector<int>& nums, int k) {
	int left = 0, right = nums.size() - 1, kth;
	while(true) {
		int idx = partition(nums, left, right);
		if(idx == k - 1) {
			kth = nums[idx];
			break;
		}
		if(idx < k - 1)
			left++;
		else
			right--;
	}
	return kth;
}

int partition(vector<int>& nums, int left, int right) {
	int l = left + 1, r = right;
	int pivot = nums[left];

	while(l <= r) {
		if(nums[l] < pivot && nums[r] > pivot)
			swap(nums[l++], nums[r--]);
		if(nums[l] >= pivot)
			l++;
		if(nums[r] <= pivot)
			r--;
	}
	swap(nums[left], nums[r]);
	return r;
}

/*
int main() {
	vector<int> nums = {3,2,1,5,6,4};
	cout << kthLargestElement(nums, 2) << endl;

	return 0;
}*/
