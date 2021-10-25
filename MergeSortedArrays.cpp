#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;

/*https://leetcode.com/problems/merge-sorted-array/
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
The number of elements initialized in nums1 and nums2 are m and n respectively. You may assume that nums1 has a size equal to m + n such that it has enough space to hold additional elements from nums2.
Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]

https://leetcode.com/problems/merge-sorted-array/discuss/608230/C%2B%2B-or-Simple-solution
https://leetcode.com/problems/merge-sorted-array/discuss/323025/Fast-Simple-C%2B%2B-Solution-with-explanation-(%22Runtime%3A-0-ms-faster-than-100.00-of-C%2B%2B...%22)
 */

void mergeSortedArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if(m == 0 & n == 0) return;

	int i = m-1;
	int j = n-1;
	int k = m+n-1;

	while(i >= 0 && j >= 0) {
		if(nums1[i] > nums2[j]) {
			nums1[k] = nums1[i];
			i--;
		} else if(nums1[i] < nums2[j]) {
			nums1[k] = nums2[j];
			j--;
		} else {
			nums1[k] = nums1[i];
			k--;
			nums1[k] = nums2[j];
			i--;j--;
		}
		k--;
	}

	while(j >= 0){
		nums1[k] = nums2[j];
		j--; k--;
	}
	return;
}
/*
int main() {
	vector<int> nums1;
	nums1.push_back(1);nums1.push_back(2);nums1.push_back(3);
	nums1.push_back(0);nums1.push_back(0);nums1.push_back(0);

	vector<int> nums2;
	nums2.push_back(2);nums2.push_back(5);nums2.push_back(6);

	mergeSortedArrays(nums1,3, nums2, 3);
	return 0;
}*/
