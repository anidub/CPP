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
/*https://www.educative.io/courses/grokking-the-coding-interview/3YlQz7PE7OA
 * Given an array of unsorted numbers and a target number, find a triplet in the array whose sum is as close to the target number as possible,
 * return the sum of the triplet. If there are more than one such triplet, return the sum of the triplet with the smallest sum.
 Input: [-2, 0, 1, 2], target=2
Output: 1
Explanation: The triplet [-2, 1, 2] has the closest sum to the target.
 */
//O(N^2), SC:O(1)
int searchTripletArraySumTarget(vector<int>& arr, int targetSum) {
	if(arr.empty()) return -1;
	sort(arr.begin(), arr.end());
	int smallestDiff = INT_MAX;

	for(int i = 0; i < arr.size() - 2; i++) {
		int left = i + 1, right = arr.size() - 1;
		while(left < right) { // comparing the sum of three numbers to the 'targetSum' can cause overflow
	        // so, we will try to find a target difference
			int targetDiff = targetSum - arr[i] - arr[left] - arr[right];
			if(targetDiff == 0) return targetSum;

			if(abs(targetDiff) < abs(smallestDiff) || (abs(targetDiff) == abs(smallestDiff) &&
					targetDiff > smallestDiff)) {// 2nd or condition is to make sure smallestDiff is positive
				smallestDiff = targetDiff;// save the closest difference
			}
			if(targetDiff > 0) left++;// we need a triplet with a bigger sum
			else
				right--;// we need a triplet with a smaller sum
		}
	}
	return targetSum - smallestDiff;
}

/*
int main() {
	  vector<int> vec = {-2, 0, 1, 2};
	  cout << searchTripletArraySumTarget(vec, 2) << endl;
	  vec = {-3, -1, 1, 2};
	  cout << searchTripletArraySumTarget(vec, 1) << endl;
	  vec = {1, 0, 1, 1};
	  cout << searchTripletArraySumTarget(vec, 100) << endl;

	return 0;
}*/
