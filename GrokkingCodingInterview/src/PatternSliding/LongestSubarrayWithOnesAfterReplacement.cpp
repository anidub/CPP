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
/*https://www.educative.io/courses/grokking-the-coding-interview/B6VypRxPolJ
 * Given an array containing 0s and 1s, if you are allowed to replace no more than ‘k’ 0s with 1s, find the length of the longest contiguous subarray having all 1s.
 * Input: Array=[0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1], k=3
Output: 9
Explanation: Replace the '0' at index 6, 9, and 10 to have the longest contiguous subarray of 1s having length 9
 */
int findOnesLength(const vector<int>& arr, int k) {
	if(arr.empty()) return 0;
	int windowStart = 0, maxOnes = 0, maxLength = 0;

	for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
		if(arr[windowEnd] == 1) maxOnes++;

		if(windowEnd - windowStart + 1 - maxOnes > k) {
			if(arr[windowStart] == 1) maxOnes--;
			windowStart++;
		}
		maxLength = max(maxLength, windowEnd - windowStart + 1);
	}
	return maxLength;
}
/*
int main(int argc, char* argv[]) {
  cout << findOnesLength(vector<int>{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 2) << endl;
  cout << findOnesLength(vector<int>{0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, 3) << endl;
}*/
