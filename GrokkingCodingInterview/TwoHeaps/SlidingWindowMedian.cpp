#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <utility>
#include <set>

using namespace std;

class SlidingWindowMedian {
/*https://www.educative.io/courses/grokking-the-coding-interview/3Y9jm7XRrXO
 * Given an array of numbers and a number ‘k’, find the median of all the ‘k’ sized sub-arrays (or windows) of the array.
 * https://leetcode.com/problems/sliding-window-median/
 * The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.

For examples, if arr = [2,3,4], the median is 3.
For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
Explanation:
Window position                Median
---------------                -----
[1  3  -1] -3  5  3  6  7        1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7        3
 1  3  -1  -3 [5  3  6] 7        5
 1  3  -1  -3  5 [3  6  7]       6
 https://leetcode.com/problems/sliding-window-median/solution/

 */
public:
	//TC:O(NLOGK), SC:O(K)
	 vector<double> medianSlidingWindow(vector<int> &nums, int k) {
		 if(nums.empty()) return {};
		 vector<double> medians;

		 multiset<int> window(nums.begin(), nums.begin() + k);
		 auto mid = next(window.begin(), k / 2);

		 for(int i = k; ;i++) {
			 medians.push_back( ((double)(*mid) + *next(mid, k % 2 - 1)) * 0.5 );

			 if(i == nums.size()) break;

			 window.insert(nums[i]);

			 if(nums[i] < *mid)
				 mid--;

			 if(nums[i-k] <= *mid)
				 mid++;

			 window.erase(window.lower_bound(nums[i-k]));
		 }
		 return medians;
	 }
};
/*
int main() {
	vector<int> nums {1,3,-1,-3,5,3,6,73};
	SlidingWindowMedian sm;
	sm.medianSlidingWindow(nums, 3);
}*/
