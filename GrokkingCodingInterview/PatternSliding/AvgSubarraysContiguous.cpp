#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
/*https://www.educative.io/courses/grokking-the-coding-interview/7D5NNZWQ8Wr
 * Given an array, find the average of all subarrays of ‘K’ contiguous elements in it.
 * Array: [1, 3, 2, 6, -1, 4, 1, 8, 2], K=5
 * Output: [2.2, 2.8, 2.4, 3.6, 2.8]
 */
//TC: O(N)
vector<double> findAverageContiguiousElement(int K, const vector<int> &nums) {
/*	if(nums.empty()) return {};

	vector<double> result(nums.size() - K + 1);
	int windowStart = 0; double windowSum = 0;

	for(int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
		windowSum += nums[windowEnd];
		if(windowEnd >= K - 1) {
			result[windowStart] = windowSum/K;
			windowSum -= nums[windowStart];
			windowStart++;
		}
	}
	return result; */
	vector<double> result(nums.size() - K + 1);

	double windowSum = 0, windowStart = 0;

	for(int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
		windowSum += nums[windowEnd];
		if(windowEnd >= K - 1) {
			result[windowStart] = windowSum / K;
			windowSum -= nums[windowStart];
			windowStart++;
		}
	}
	return result;
}
/*
int main() {
	vector<int> nums = {1, 3, 2, 6 , -1, 4, 1, 8, 2};
	vector<double> result = findAverageContiguiousElement(5, nums);
	  for (double d : result) {
	    cout << d << " ";
	  }
	return 0;
} */
